#include "mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QSet>
#include <QDebug>

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
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::draw()
{
    scene->clear();
    //int x=0,y =0,hh=500,w=300;
    QBrush blue_brush(Qt::blue);
    QBrush black_brush(Qt::black);
    QBrush white_brush(Qt::white);
    QPen pen(Qt::black);
    QPen penw(Qt::white);
    QBrush darkgrey_brush(Qt::darkGray);
    QBrush dark_brush(Qt::gray);
    pen.setWidth(0);
    building = scene->addRect(0,0,300,500,pen,blue_brush);
    buildtop1 = scene->addRect(50,-30,200,30,pen,dark_brush);
    buildtop2 = scene->addRect(100,-50,100,20,pen,darkgrey_brush);
    floor1 = scene->addRect(125,30,50,70,penw,white_brush);
    floor2 = scene->addRect(125,130,50,70,penw,white_brush);
    floor3 = scene->addRect(125,230,50,70,penw,white_brush);
    floor4 = scene->addRect(125,330,50,70,penw,white_brush);
    floor5 = scene->addRect(125,430,50,70,penw,white_brush);




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

}
