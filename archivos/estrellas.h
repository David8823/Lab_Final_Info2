#ifndef ESTRELLAS_H
#define ESTRELLAS_H
#include<QGraphicsItem>
#include <math.h>
#include <QPainter>

class estrellas : public QGraphicsItem
{
private:
    float px,py,vx,vy,msol;

public:
    estrellas(float,float,float,float,float);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    float getmsol() const;
};

#endif // ESTRELLAS_H
