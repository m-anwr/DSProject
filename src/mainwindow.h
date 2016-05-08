#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphics.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addRequestBtn_clicked();
    void on_createSimFileBtn_clicked();

    void on_selectSimFileBtn_clicked();

    void on_startSimBtn_clicked();
    void draw ();
private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsRectItem *building;
    QGraphicsRectItem *buildtop1;
    QGraphicsRectItem *buildtop2;
    QGraphicsRectItem *between1_2;
    QGraphicsRectItem *between2_3;
    QGraphicsRectItem *between3_4;
    QGraphicsRectItem *between4_5;
    QGraphicsRectItem *floor1;
    QGraphicsRectItem *floor2;
    QGraphicsRectItem *floor3;
    QGraphicsRectItem *floor4;
    QGraphicsRectItem *floor5;
};

#endif // MAINWINDOW_H
