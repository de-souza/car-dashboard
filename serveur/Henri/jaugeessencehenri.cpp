#include "jaugeessencehenri.h"


jaugeEssenceHenri::jaugeEssenceHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=100;
    valueMax=100;
}
QRectF jaugeEssenceHenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void jaugeEssenceHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

//début jauge à essence

    if (value<0)
        value=0;
    if (value>100)
        value=100;

    QRect carre(-280,-280,560,560);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QBrush(QColor(250-value*2.5,value*2.5,0,80)) , 34, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre,231*16,80*16);//le fond de transparence 80

    painter->setPen(QPen(QBrush(QColor(250-value*2.5,value*2.5/2,0,255)) , 40, Qt::SolidLine,Qt::FlatCap));
    painter->drawArc(carre,231*16,value*16*0.8);//l'essence réel de transparence 255 (aucune transparence)

    QPixmap *test=new QPixmap(":/new/prefix1/icones/iconeEssence.png");
    painter->drawPixmap(-15,265,30,30,*test);

    if (value == 0)
    {
        QPixmap *test2=new QPixmap(":/new/prefix1/icones/iconeEssenceRouge.png");
        painter->drawPixmap(-15,265,30,30,*test2);
    }


//fin jauge essence

}
