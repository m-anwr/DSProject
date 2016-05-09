#include "mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "ui_mainwindow.h"
#include <QSet>
#include <QDebug>
#include <QGraphicsObject>

#include "ui_mainwindow.h"
#include "request.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->reqTable->horizontalHeader()->setVisible(true);
    ui->reqTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->reqTable->setHorizontalHeaderItem(0, new QTableWidgetItem("At"));
    ui->reqTable->setHorizontalHeaderItem(1, new QTableWidgetItem("From"));
    ui->reqTable->setHorizontalHeaderItem(2, new QTableWidgetItem("To"));

    scene = new Scene(ui->graphicsView);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 300, 450);
    QTimer::singleShot(200, this, SLOT(showMaximized()));
    simT = new QTimer(this);
    simT->setInterval(1000);

    connect(simT, SIGNAL(timeout()),
            this, SLOT(moveElv()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addRequestBtn_clicked()
{
    int reqAt   = ui->reqAt->value();
    int reqFrom = ui->reqFrom->value();
    int reqTo   = ui->reqTo->value();

    if(reqFrom == reqTo)
    {
        QMessageBox::critical(this, "Error", "Request origin and destination are the same");
        return;
    }

    int newRowindex = ui->reqTable->rowCount();
    ui->reqTable->insertRow(newRowindex);
    ui->reqTable->setItem(newRowindex, 0, new QTableWidgetItem(QString::number(reqAt)));
    ui->reqTable->setItem(newRowindex, 1, new QTableWidgetItem(QString::number(reqFrom)));
    ui->reqTable->setItem(newRowindex, 2, new QTableWidgetItem(QString::number(reqTo)));
}


void MainWindow::on_createSimFileBtn_clicked()
{
    if(ui->reqTable->rowCount() == 0)
    {
        QMessageBox::information(this, "Info", "Request table is empty!");
        return;
    }

    QString savingPath = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::home().absolutePath(), tr("Elevator Sim (*.elv)"));

    if(savingPath.isEmpty()) return;

    QFile f(savingPath);
    f.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&f);

    QString elevState = QString::number(ui->elvInitialFloor->value()) + " " + QString::number(ui->elvTransitionTime->value());
    out << elevState;

    for(int i = 0; i < ui->reqTable->rowCount(); ++i)
    {
        out << "\n";
        out << ui->reqTable->item(i, 0)->text() + " " + ui->reqTable->item(i, 1)->text() + " " + ui->reqTable->item(i, 2)->text();
    }

    f.close();
}

void MainWindow::on_startSimBtn_clicked()
{
    QSet<Request> RequestsIn;
    QString simFilePath = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::home().absolutePath(), tr("Elevator Sim (*.elv)"));
    if(simFilePath.isEmpty()) return;

    QFile f(simFilePath);
    f.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream in(&f);

    int elvFloor, elvTransitionTime, tempTime, tempFrom, tempTo;

    in >> elvFloor >> elvTransitionTime;

    while(!in.atEnd())
    {
        in >> tempTime >> tempFrom >> tempTo;
        RequestsIn.insert(Request(tempTime, tempFrom, tempTo));
    }
    f.close();

    // Send values and Request Set to elevator
    ui->statusBar->showMessage("WAITING");
    elvShape = new ElevatorShape(elvFloor);
    scene->addItem(elvShape);
    Elevator e = Elevator(RequestsIn, elvFloor);
    simQue = e.simulate();
    startSimTimer();
}

void MainWindow::moveElv()
{
    if(simQue.empty())
    {
        simT->stop();
        return;
    }
    pair p = simQue.head();
    if(p.getTime() == lastSec)
    {
        simQue.dequeue();
        ui->statusBar->showMessage("WAITING");
        return;
    }

    ui->statusBar->showMessage("MOVING");

    elvShape->move(p.getFloor());
    simQue.dequeue();
    lastSec = p.getTime();
}

void MainWindow::startSimTimer()
{
    simT->start();
}

// ================================================================

ElevatorShape::ElevatorShape(int intiFloor)
    : QGraphicsObject(0)
{
    setZValue(100);
    move(intiFloor);
}

ElevatorShape::~ElevatorShape()
{
}

QRectF ElevatorShape::boundingRect() const
{
    return QRectF(0,0,50,70);
}

void ElevatorShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setBrush(QColor(0,255,0,255));
    painter->drawRect(0,0,50,70);
}

void ElevatorShape::move(int floor)
{
    qreal y= 430 - floor * 100;
    setPos(125,y);
}
