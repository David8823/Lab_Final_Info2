#include "planetas.h"

int planetas::getDT() const
{
    return DT;
}

void planetas::setDT(int value)
{
    DT = value;
}

planetas::planetas(float _px, float _py, float _vx, float _vy,float _msol,float _xsol,float _ysol,float r)
{
    px=_px;
    py=_py;

    vx=_vx;
    vy=_vy;

    msol=_msol;
    xsol=_xsol;
    ysol=_ysol;
    rad=r;
    setPos(px,py);

}

void planetas::advance(int phase)
{
   float angulo;
   float totalx = xsol-px;
   float totaly = ysol-py;

   if(totalx != 0){angulo = atan(totaly/totalx);}//caso que la division no da infinito
   else if(totaly > 0){angulo=1.5*PI;}//caso en el que la division da menos infinito
   else{angulo=0.5*PI;}//caso en el que la division da infinito
   if(angulo<0)
   {
       if(totalx>0 && totaly<0){angulo=PI+angulo;}
       else if(totaly>0 && totalx<0){angulo=2*PI+angulo;}
   }
   if((totalx>0) && (totaly>0)&&angulo){angulo=angulo+PI;}
   float r2 = pow(totalx,2)+pow(totaly,2);//Distancia al cuadrado entre el planeta y el sol

   float G = 6.67384*pow(10,-11); //constante de gravitacion universal
   float a = -(G*msol)/r2;//magnitud de la aceleracion

   ax=a*cos(angulo);//aceleracion en x
   ay=a*sin(angulo);//aceleracion en y

   vx = vx + ax*DT;//velocidad en x
   vy = vy + ay*DT;//velocidad en y

   px = px + vx*DT + 0.5*ax*DT*DT;
   py = py + vy*DT + 0.5*ay*DT*DT;
   setPos(px,py);

}


QRectF planetas::boundingRect() const
{
    return QRectF(px,py,rad,rad);
}

void planetas::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);
    painter->drawEllipse(boundingRect());
}
