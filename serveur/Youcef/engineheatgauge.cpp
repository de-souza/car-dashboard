#include "engineheatgauge.h"
#include <QtMath>
#include <QGraphicsTextItem>
#include <QStringList>


EngineHeatGauge::EngineHeatGauge(objet_virtuel *)
{
value=0;
valueMax=100;
}

QRectF EngineHeatGauge::boundingRect() const
{
       return QRectF(-600, -400, 1200, 800);
}

void EngineHeatGauge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);

    {
      QRect RectSpeed (-500,-300, 405, 405);
      painter->setPen(QPen(QBrush("red"), 4, Qt::SolidLine,Qt::RoundCap,Qt::BevelJoin));

      QPolygonF polygon;
      QPainterPath rectPath;
      rectPath.moveTo(-96,-64);
      rectPath.lineTo(-13,-64);
      rectPath.lineTo(-13, 85);
      rectPath.lineTo(-212,85);
      rectPath.arcTo(RectSpeed,-64,50 );
      rectPath.closeSubpath();
      rectPath.addPolygon(polygon);

      QRadialGradient gradient(-119, -4.5, 200);
      gradient.setColorAt(0, QColor(0,0,0,0));
      gradient.setColorAt(0.5, QColor("dark blue"));
      gradient.setColorAt(1, QColor("dark"));
      QBrush brush(gradient);
      painter->setBrush(brush);
      painter->drawPath(rectPath);

     }
     {
        QPen pen ;
        pen.setWidth(2);
        pen.setColor("#DF3A01");
        painter->setPen(pen);

        QBrush NeedleColor("#DF3A01",Qt::SolidPattern);
        painter->setBrush(NeedleColor);

        for (int i=0;i<=9;i++)
           {
            if((i+1)>getValue()/10)
            {
                QBrush NeedleColor("white",Qt::SolidPattern);
                painter->setBrush(NeedleColor);

            }

         float x1,y1;int r=15;
         x1=-275+190*(cos((56-(i*5.1))*pi/180));
         y1=-90+190*(sin((56-(i*5.1))*pi/180));
         painter->drawRoundedRect(x1,y1,2*r,r/2,2,2);
        }
      }
      {
        QRect RectSpeed (-550,-350, 505, 505);

        int startAngle= -42*16;
        int spanAngle= 32.4*16;
        int startAngle1 = -9.5*16;
        int spanAngle1 = -9.0*16;

        painter->setPen(QPen(QBrush("dark"), 5, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
        painter->drawArc(RectSpeed,startAngle,spanAngle);

        painter->drawLine(QPoint(-74,16),QPoint(-54,16));
        painter->drawLine(QPoint(-90,45),QPoint(-77,45));
        painter->drawLine(QPoint(-108,70),QPoint(-85,70));


        painter->setPen(QPen(QBrush("red"), 5, Qt::SolidLine,Qt::FlatCap,Qt::BevelJoin));
        painter->drawLine(QPoint(-60,-17),QPoint(-46,-17));
        painter->drawLine(QPoint(-51,-53),QPoint(-35,-53));
        painter->drawArc(RectSpeed,startAngle1,spanAngle1);


        painter->setFont(QFont("ariel", 15,  QFont::Bold, false));
        painter->setPen(QPen(QBrush("red") ,10, Qt::SolidLine,Qt::FlatCap));
        painter->drawText(-33,-45, "H");
        painter->setPen(QPen(QBrush("dark") ,10, Qt::SolidLine,Qt::FlatCap));
        painter->drawText(-80, 75, "C");
      }


    {


    if (getValue()>80)
        {
        painter->setPen(QPen(QColor("red") , 32, Qt::SolidLine,Qt::FlatCap));
        QPixmap img1 ( ":/new/logos/Icones/iconeSurchaufe.png");
        QPixmap img2=img1.scaled(40,40);
        painter->drawPixmap(-55,-10,40,40,img2);
        }

    else
    {
         painter->setPen(QPen(QColor(Qt::transparent) , 32, Qt::SolidLine,Qt::FlatCap));
 QPixmap img1 ( ":/new/logos/Icones/iconeSurchaufe.png");
 QPixmap img2=img1.scaled(40,40);
 painter->drawPixmap(-55,-10,40,40,img2);


    }
}
}


