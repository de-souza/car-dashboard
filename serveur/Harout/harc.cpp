#include "harc.h"
#include <Qt>
#include <QtCore>
#include <math.h>
#include <QDebug>
#include <QPainter>
#include <QtMath>
#include <QStringList>

Harc::Harc(int param_value, int param_valueMax, QString param_type )
{
    //valueMax = 120;
    value=0;
    spanAngle0 = param_value;
    //spanAngle =param_arcMax;
    //value = param_value;
    valueMax = param_valueMax;
    type=param_type;

}

QRectF Harc::boundingRect() const
{
    return QRectF(rec);
}

void Harc::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                 QWidget *)
{
    painter->translate(A/2, B/2);
    painter->scale(1, -1);
    painter->translate(-A/2, -A/2);
    painter->setPen(QPen(QBrush("white"), 15, Qt::SolidLine, Qt::FlatCap ));
    painter->drawArc(rec,  startAngle, spanAngle);

    if(type=="temperature"){
        if (value<=50)
        {
            painter->setPen(QPen(QBrush("blue"), 10, Qt::SolidLine, Qt::FlatCap ));
            painter->drawArc(rec,  startAngle, getValue()*16);
        }
        else if ( (50<value) & (value<80) )
        {
            painter->setPen(QPen(QBrush("orange"), 10, Qt::SolidLine, Qt::FlatCap ));
            painter->drawArc(rec,  startAngle, getValue()*16);
        }
        else
        {
            painter->setPen(QPen(QBrush("red"), 10, Qt::SolidLine, Qt::FlatCap ));
            painter->drawArc(rec,  startAngle, getValue()*16);
        }
    }

    if(type=="essence"){
    if (value<=25)
    {
        painter->setPen(QPen(QBrush("red"), 10, Qt::SolidLine, Qt::FlatCap ));
        painter->drawArc(rec,  startAngle, getValue()*16*1.2);
    }
    else if ( (25<value) & (value<50) )
    {
        painter->setPen(QPen(QBrush("orange"), 10, Qt::SolidLine, Qt::FlatCap ));
        painter->drawArc(rec,  startAngle, getValue()*16*1.2);
    }
    else
    {
        painter->setPen(QPen(QBrush("blue"), 10, Qt::SolidLine, Qt::FlatCap ));
        painter->drawArc(rec,  startAngle, getValue()*16*1.2);
    }
    }

    //    if (value > 80){
    //    painter->setPen(QPen(QBrush("red"), 10, Qt::SolidLine, Qt::FlatCap ));
    //    painter->drawArc(rec,  startAngle, getValue()*16);
    //    }
    //    else  if (50 <value<80){
    //        painter->setPen(QPen(QBrush("orange"), 10, Qt::SolidLine, Qt::FlatCap ));
    //        painter->drawArc(rec,  startAngle, getValue()*16);
    //    }
    //    else if (value<50) {
    //        painter->setPen(QPen(QBrush("blue"), 10, Qt::SolidLine, Qt::FlatCap ));
    //        painter->drawArc(rec,  startAngle, getValue()*16);
    //}


}
