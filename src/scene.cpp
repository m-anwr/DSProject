#include <QGraphicsScene>

#include "scene.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene(parent)
{
}

Scene::~Scene()
{
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
        QBrush blue_brush(Qt::darkBlue);
        QBrush white_brush(Qt::cyan);

        QPen pen(Qt::black);
        QPen penb(Qt::darkBlue);
        QPen penw(Qt::white);
        QBrush darkgrey_brush(Qt::darkBlue);
        QBrush dark_brush(Qt::darkBlue);

        pen.setWidth(0);
        //the building
        addRect(0,0,300,500,pen,blue_brush);
        addRect(-20,-20,340,20,penb,dark_brush);
        //addRect(100,-50,100,20,pen,darkgrey_brush);
        //elevators doors
        addRect(125,30,50,70,penw,white_brush);
        addRect(125,130,50,70,penw,white_brush);
        addRect(125,230,50,70,penw,white_brush);
        addRect(125,330,50,70,penw,white_brush);
        addRect(125,430,50,70,penw,white_brush);
        //between floors
        addRect(50,410,200,5,penw,white_brush);
        addRect(50,310,200,5,penw,white_brush);
        addRect(50,210,200,5,penw,white_brush);
        addRect(50,110,200,5,penw,white_brush);
        // left windows
        addRect(35,20,20,20,penw,white_brush);
        addRect(60,20,20,20,penw,white_brush);
        addRect(35,45,20,20,penw,white_brush);
        addRect(60,45,20,20,penw,white_brush);
        // right windows
        addRect(220,20,20,20,penw,white_brush);
        addRect(245,20,20,20,penw,white_brush);
        addRect(220,45,20,20,penw,white_brush);
        addRect(245,45,20,20,penw,white_brush);

        QGraphicsScene::drawBackground(painter, rect);
    }
