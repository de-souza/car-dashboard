#include "feuxhenri.h"

feuxHenri::feuxHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
}

QRectF feuxHenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void feuxHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    QPixmap *test=new QPixmap(":/new/prefix1/icones/iconeRoute.png");
    if ( getValue()==1)
    painter->drawPixmap(-35,40,70,70,*test);
}
