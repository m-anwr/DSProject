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
    QBrush blue_brush(Qt::blue);
    QBrush white_brush(Qt::white);

    QPen pen(Qt::black);
    QPen penw(Qt::white);
    QBrush darkgrey_brush(Qt::darkGray);
    QBrush dark_brush(Qt::gray);

    pen.setWidth(0);
    addRect(0,0,300,500,pen,blue_brush);
    addRect(50,-30,200,30,pen,dark_brush);
    addRect(100,-50,100,20,pen,darkgrey_brush);
    addRect(125,30,50,70,penw,white_brush);
    addRect(125,130,50,70,penw,white_brush);
    addRect(125,230,50,70,penw,white_brush);
    addRect(125,330,50,70,penw,white_brush);
    addRect(125,430,50,70,penw,white_brush);

    QGraphicsScene::drawBackground(painter, rect);
}
