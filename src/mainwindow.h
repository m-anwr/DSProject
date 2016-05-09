#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsObject>

#include "scene.h"
#include "elevator.h"
#include "request.h"

namespace Ui {
class MainWindow;
}

class ElevatorShape : public QGraphicsObject
{
    Q_OBJECT

public:
    ElevatorShape(int intiFloor);
    ~ElevatorShape();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void move(int floor);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addRequestBtn_clicked();
    void on_createSimFileBtn_clicked();
    void on_startSimBtn_clicked();

public Q_SLOTS:
    void moveElv();

private:
    void startSimTimer();

private:
    int lastSec = -1;
    Ui::MainWindow *ui;
    Scene *scene;
    QQueue<pair> simQue;
    QTimer* simT;
    ElevatorShape* elvShape;
};

#endif // MAINWINDOW_H
