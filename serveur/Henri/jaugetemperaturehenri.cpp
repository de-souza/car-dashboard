#include "jaugetemperaturehenri.h"

jaugeTemperatureHenri::jaugeTemperatureHenri()
{

}

QRectF jaugeTemperatureHenri::boundingRect() const
{
    return QRect(-800,-450,1600,900);
}

void jaugeTemperatureHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLinearGradient gradient(-200, 0, 150, 0);
    painter->setRenderHint(QPainter::Antialiasing);

    gradient.setColorAt(0, QColor("blue"));
    gradient.setColorAt(0.6, QColor("gray"));
    gradient.setColorAt(1, QColor("darkRed"));
    QBrush brush(gradient);
    painter->setBrush(brush);
    int l=240;
    QRect carre1(-l,-l,2*l,2*l);
    int j=15;
    QRect carre(-l+j,-l+j,2*l-2*j,2*l-2*j);
    QRect carre3(-l+2*j,-l+2*j,2*l-4*j,2*l-4*j);
    QRect carre4(-l+3*j,-l+3*j,2*l-6*j,2*l-6*j);

    painter->setPen(QPen(brush , 28, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre3,-129*16,80*16);

    painter->setPen(QPen(QBrush("black") , 30, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre1,-129*16,80*16);


    painter->setPen(QPen(QBrush("black") , 3, Qt::SolidLine,Qt::FlatCap));

    painter->drawArc(carre,-129*16,80*16);

    painter->drawArc(carre3,-129*16,80*16);
    painter->setPen(QPen(QBrush("black") , 28, Qt::SolidLine,Qt::FlatCap));

    painter->drawArc(carre3,-129*16,1*16);
    painter->drawArc(carre3,-90*16,1*16);
    painter->drawArc(carre3,-50*16,1*16);

    painter->setPen(QPen(QBrush("black") , 3, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre4,-129*16,80*16);

    QPixmap *test=new QPixmap(":/new/prefix1/iconeSurchaufe.png");
    painter->drawPixmap(-15,155,30,30,*test);
}
