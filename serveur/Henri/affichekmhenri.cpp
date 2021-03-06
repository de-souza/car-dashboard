///
///\file afficheKmHenri.cpp
/// \brief Classe dérivant de objet_virtuel permettant l'affichage du nombre de km parcourut.
///
#include "affichekmhenri.h"

///
/// \brief afficheKmHenri::afficheKmHenri
///\details Initialise la variable value de la classe mère à 0
afficheKmHenri::afficheKmHenri(objet_virtuel *parent):objet_virtuel (parent)
{
    value=0;
    valueMax=9999;
}

QRectF afficheKmHenri::boundingRect() const
{
    return QRect(-300,-300,600,600);
}


///
/// \brief afficheKmHenri::paint
/// \param painter
///\details La fonction paint va permettre l'affichage des kilometres totaux et actuels
///
void afficheKmHenri::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{

//.....affichage nombre de kilometres
    painter->setRenderHint(QPainter::Antialiasing);
    QRadialGradient gradient(0, 0, 1000);
    gradient.setColorAt(0, QColor("darkCyan"));
    gradient.setColorAt(1, QColor("dark"));
    QBrush brush(gradient);

    painter->setPen(QPen(QBrush("black") , 40 , Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor("black"));
    painter->drawRoundRect(QRect(80,-50,80,2),1,1);

    painter->setBrush(brush);
    painter->setPen(QPen(brush,20));

    painter->setFont(QFont("URW Gothic L",20));
    painter->drawText(80,-39,QString::number(getValue(), 'f', 1));
//.....fin affichage nombre de kilometres


//.....affichage nombre de kilometres totaux

    painter->setPen(QPen(QBrush("black") , 40 , Qt::SolidLine,Qt::FlatCap));
    painter->setBrush(QColor("black"));
    painter->drawRoundRect(QRect(-160,-50,80,2),1,1);

    painter->setBrush(brush);
    painter->setPen(QPen(brush,20));

    painter->setFont(QFont("URW Gothic L",20));
    painter->drawText(-165,-39,QString("%1").arg(142857.0+getValue()));

//.....fin affichage nombre de kilometres totaux

}
