#include "stophenri.h"
#include <QDebug>


stopHenri::stopHenri()
{
    value=0;
    cligno=0;
    jt=new jaugeTemperatureHenri();
    check=new onoffpaintHenri(100,0,70,55,QPixmap(":/new/prefix1/icones/checkengine.png"));
}

QRectF stopHenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void stopHenri::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (jt->getValue() > 120 || check->getValue() ==1)
    {
    QRect carre(-150,-150,300,300);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor("red")) , 89, Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QBrush(QColor("red")));
    if (cligno==1)
    {
        painter->setPen(QPen(QBrush(QColor("black")) , 89, Qt::SolidLine,Qt::FlatCap));
        painter->setBrush(QBrush(QColor("black")));
    }
    painter->drawArc(carre,231*16,80*16);

    QRect carre2(-66,80,134,50);
    painter->setPen(QPen(QBrush(QColor("red")) , 1, Qt::SolidLine,Qt::FlatCap));
    if (cligno==1)
        painter->setPen(QPen(QBrush(QColor("black")) , 1, Qt::SolidLine,Qt::FlatCap));
    painter->drawRect(carre2);

    painter->setPen(QPen(QBrush(QColor("black")) , 80, Qt::SolidLine,Qt::FlatCap));
    if (cligno==1)
        painter->setPen(QPen(QBrush(QColor("red")) , 80, Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont("unroob",50));
    painter->drawText(-86,160,"STOP");
    MAJ();
    }
}

void stopHenri::MAJ()
{
    cligno=!cligno;
    QTest::qWait(800);
    update();
}
