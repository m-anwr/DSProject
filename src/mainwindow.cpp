#include "mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "ui_mainwindow.h"
#include <QDebug>


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

    Request r1(0,3,4);
    Request r2(0,1,2);
    Request r3(0,0,4);
    Request r4(0,2,0);
    Request r5(0,4,0);
    Request r6(0,4,2);


    Elevator e;
    e.set(r1);
    e.set(r2);
    e.set(r3);
    e.set(r3);
    e.set(r3);
    e.set(r4);
    e.set(r5);
    e.set(r6);
    e.set(r1);
    e.set(r2);
    e.set(r1);
    e.set(r4);

    e.simulate();
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

void MainWindow::on_selectSimFileBtn_clicked()
{
    QString simFilePath = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::home().absolutePath(), tr("Elevator Sim (*.elv)"));
    if(!simFilePath.isEmpty())
    {
        ui->simFilePath->setText(simFilePath);
    }
}
