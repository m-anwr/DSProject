#include "graphics.h"

graphics::graphics(QObject *parent): QGraphicsScene(parent), d(new Private)
{
    scene = new QGraphicsScene(this);
    d->graphicsView->setScene(scene);
}

void graphics::drawBuilding()
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
