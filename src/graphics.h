#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsView>

class graphics: public QGraphicsScene
{

public:
    graphics(QObject *parent = 0);
    QGraphicsScene *scene;
    void drawBuilding ();
private:
        class Private;
        Private* const d;
        graphics *scene;
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

#endif // GRAPHICS_H
