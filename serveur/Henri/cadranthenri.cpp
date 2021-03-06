#include "cadranthenri.h"
#include <QDateTime>

cadrantHenri::cadrantHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    valueMax=999;
    valeurMaxNombreCompteur=270;
    styleTexte="Uroob";
    epesseurTraitVitesse=10;
    tailleTexteVitesse=27;
}


QRectF cadrantHenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}

void cadrantHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{




//.....création des carrés de fond pour le disigne du cadrant........................

    QRect carre[10];
    for (int i=0;i<10;i++)
    {
        carre[i]=QRect(-300+i*5,-300+i*5,600-i*10,600-i*10);
    }

//.....fin création des carrés de fond pour le disigne du cadrant.....................







//.....Designe fond degradé rond derrierre cadrant....................................

    for (int i=90;i>40;i--)
    {
        painter->setPen(QPen( QColor(0,0,0,15) , i, Qt::SolidLine,Qt::FlatCap));

        painter->drawArc(carre[4],0,360*16);
    }

//.....Fin Designe fond degradé rond derrierre cadrant...................................








//.....Designe vitesse cadrant....................................................

    painter->setRenderHint(QPainter::Antialiasing);

    painter->setPen(QPen(QBrush("darkCyan") , 40, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>-46;i-=10.0*270/valeurMaxNombreCompteur)
        {
        painter->drawArc(carre[2],i*16,epesseurTraitVitesse);
        }

    painter->setPen(QPen(QBrush("darkCyan") , 30, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>-46;i-=1.0*270/valeurMaxNombreCompteur)
        {
        painter->drawArc(carre[4],i*16,epesseurTraitVitesse);
        }

    painter->setPen(QPen(QBrush("cyan") , 40, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>224-qMin(270.0,(value*270.0/valeurMaxNombreCompteur));i-=10.0*270/valeurMaxNombreCompteur)
        {
        painter->drawArc(carre[2],i*16,epesseurTraitVitesse);
        }

    painter->setPen(QPen(QBrush("cyan") , 30, Qt::SolidLine,Qt::FlatCap));
    for (float i=225;i>224-qMin(270.0,(value*270.0/valeurMaxNombreCompteur));i-=1.0*270.0/valeurMaxNombreCompteur)
        {
        painter->drawArc(carre[4],i*16,epesseurTraitVitesse);
        }


//.....Fin designe vitesse cadrant...........................................





//.....Designe text pour vitesse cadrant.............................................

    painter->setPen(QPen(QBrush("cyan") , 40 , Qt::SolidLine,Qt::FlatCap));
    painter->setFont(QFont(styleTexte, tailleTexteVitesse, -1,false));
    float pi=3.14159265;
    int j=0;
    for (float i=35*pi/28;i>=-7*pi/28;i-=6*pi/(27*4)*270/(valeurMaxNombreCompteur+1))
    {


        painter->drawText(qCos(i)*345-18,-qSin(i)*345+13,QString("%1").arg(j));
        j+=10;
        if (j>value)
            painter->setPen(QPen(QBrush("darkCyan") , 40, Qt::SolidLine,Qt::FlatCap));
    }

//.....fin Designe text pour vitsse cadrant...............................................................


//.....affichage vitesse en nombre

    painter->setPen(QPen(QBrush("black") , 40 , Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor("black"));
    painter->drawRoundRect(QRect(-80,-170,160,60),25,25);


    QRadialGradient gradient(0, 0, 1000);
    gradient.setColorAt(0, QColor("darkCyan"));
    gradient.setColorAt(1, QColor("dark"));
    QBrush brush(gradient);
    painter->setBrush(brush);
    painter->setPen(QPen(brush,40));

    painter->setFont(QFont("URW Gothic L",80));
    int v=static_cast<int>(getValue());
    if(getValue()<10)
    painter->drawText(-30,-100,QString("%1").arg(v));
    if( (getValue()>=10) & (getValue()<100) )
    painter->drawText(-60,-100,QString("%1").arg(v));
    if(getValue()>=100)
    painter->drawText(-90,-100,QString("%1").arg(v));

//.....fin affichage vitesse en nombre





//.....affichage heure
    painter->setFont(QFont("URW Gothic L",30));
    painter->setPen(QPen(QBrush("cyan") , 40 , Qt::SolidLine,Qt::FlatCap));
    QString heure = QDateTime::currentDateTime().toString("hh:mm");
    painter->drawText(-52,-33,heure);
//.....fin affichage heure



}
