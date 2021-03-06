#include "Inna/speedometerinna.h"
#include <QFont>
#include <QtMath>
#include <QPainter>
///
/// \file speedometerinna.cpp
/// \brief Classe SpeedometerInna derivée de la classe QGraphicsItem
/// \details Permettant la création d'un objet static de la jauge vitesse
/// \param value - la valeur de vitesse
/// \param valueMax -  la vitesse maximum
/// \param A0 - l'angle de debut de la jauge
/// \param Amax - l'ampleur de la jauge
/// \param r - le rayon de l'arche de la jauge
/// \param k - le coefficient pour convertir la valeur en degrés
///
///
SpeedometerInna::SpeedometerInna(QGraphicsItem *parent) :  QGraphicsItem(parent)
{
    vmax = 300 ;
    A0 = 240 ;
    Amax = 180 ;
    r = 150 ;
    dx = 7;
    dy = 10;
    k = Amax * 1.0 / vmax ;

}

SpeedometerInna::SpeedometerInna(int VMAX, int ALPHA0, int ALPHAMAX)
{
    vmax = VMAX ;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 150 ;
    dx = 12;
    dy = 6;
    k = Amax * 1.0 / vmax ;



}

QRectF SpeedometerInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void SpeedometerInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    ///
    ///\brief Dessin du circle encadrant
   /// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner un circle  encadrant avec un gradient de couleur.
    painter->drawPixmap(158,50, 485, 520, QPixmap(":/I_L.gif"));



    painter->setBrush(QBrush("#0a0f0f",Qt::SolidPattern));
    painter->drawEllipse(QRectF(xc-r,yc-r,r*2,r*2));
     QRadialGradient radialGrad(QPointF(xc, yc), r+20); //setting the gradient to draw the outer arc
     radialGrad.setColorAt(0, Qt::transparent);
     radialGrad.setColorAt(0.8, "#f2f2f2");
     radialGrad.setColorAt(0.9, "#333333");
     radialGrad.setColorAt(1, "#f2f2f2");
     painter->setPen(QPen(QBrush(radialGrad),4,Qt::SolidLine,Qt::FlatCap)); // setting the brush with a gradient
     painter->setBrush(QBrush(Qt::transparent)); // to have a transparent background
     painter->drawArc(QRectF(xc-r,yc-r,r*2,r*2),37*16,298*16); // coordinates for the arc

  /// \brief Dessin du texte et des traits
  ///
     k = Amax * 1.0 / vmax ;
     for (int i = 0; i <= vmax ; i += 10) {
     if (i % 50 == 0)
         {
         painter->setPen(QPen(QBrush("#f2f2f2"),6,Qt::SolidLine,Qt::FlatCap));
         painter->drawLine( qRound(xc+(r-5)*cos((A0-k*i)*rad)),qRound(yc-(r-5)*sin((A0-k*i)*rad)),qRound(xc+(r-20)*cos((A0-k*i)*rad)),qRound(yc-(r-20)*sin((A0-k*i)*rad)));
         painter->setFont(QFont("Chandas",12,QFont::Bold));
         painter->setPen(QPen("#f5f5ef"));
         painter->drawText(qRound(xc-dx+(r-35)*cos((A0-k*i)*rad)),qRound(yc+10-(r-35)*sin((A0-k*i)*rad)),QString("%1").arg(i));
         }
     else {
         painter->setPen(QPen(QBrush("#f2f2f2"),2,Qt::SolidLine,Qt::FlatCap));
         painter->drawLine(qRound(xc+(r-5)*cos((A0-k*i)*rad)), qRound(yc-(r-5)*sin((A0-k*i)*rad)),qRound(xc+(r-15)*cos((A0-k*i)*rad)),qRound(yc-(r-15)*sin((A0-k*i)*rad)));
     }
    }



}
