#ifndef PLANETAS_H
#define PLANETAS_H
#include<QGraphicsItem>
#include <math.h>
#include <QPainter>
#define PI 3.14159265

class planetas : public QGraphicsItem
{
private:
    float px,py,vx,vy,ax,ay,msol,xsol,ysol,rad;
    int DT = 1000;


public:
    planetas(float _px, float _py, float _vx, float _vy, float msol,float xsol,float ysol, float r);

    void advance(int phase);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getDT() const;
    void setDT(int value);
};

#endif // PLANETAS_H
