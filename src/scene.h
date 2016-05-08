#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>

class Scene: public QGraphicsScene
{

public:
    Scene(QObject *parent = 0);
    ~Scene();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif // GRAPHICS_H
