#include "estrellas.h"



float estrellas::getmsol() const
{
    return msol;
}

estrellas::estrellas(float _px,float _py,float _vx,float _vy,float _msol)
{

    px=_px;
    py=_py;
    vx=_vx;
    vy=_vy;
    msol=_msol;
    setPos(px,py);

}

QRectF estrellas::boundingRect() const
{
    return QRectF(px,py,100,100);
}

void estrellas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkYellow);
    painter->drawEllipse(boundingRect());
}
