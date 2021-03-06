#include "Inna/arrowtachometerinna.h"
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>
///
/// \file arrowtachometerinna.cpp
/// \brief Classe ArrowTachometerInna derivée de la classe objet_virtuel
/// \details Permettant la création de l' aiguille de la jauge compte-tours qui tourne en fonction de la valeur "value".
///
/// \param value - la valeur des tours par minute
/// \param valueMax - la valeur des tours par minute maximum
/// \param A0 - l'angle de debut de la jauge
/// \param Amax - l'ampleur de la jauge
/// \param r - le rayon de l'arche de la jauge
/// \param k - le coefficient pour convertir la valeur en degrés
///
ArrowTachometerInna::ArrowTachometerInna(objet_virtuel *parent) :  objet_virtuel(parent)
{
    value=0.0;
    vmax = 8000 ;
    valueMax =vmax;
    A0 = 225 ;
    Amax = 270 ;
    r = 170 ;
    dx = 10;
    dy = 12;
    k = Amax * 1.0 / vmax ;
}

ArrowTachometerInna::ArrowTachometerInna(int VMAX, int ALPHA0, int ALPHAMAX)
{
    value=0.0;
    vmax = VMAX ;
    valueMax =vmax;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 170 ;
    dx = 10;
    dy = 12;
    k = Amax * 1.0 / vmax ;
    
}

QRectF ArrowTachometerInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf; 
}

void ArrowTachometerInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
   painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
    v=qRound(value);
  if (v < 0 || v > vmax) v = (v < 0 ? 0 : vmax);
   v = qRound(v*Amax * 1.0f / vmax) ;
  
   ///
   ///\brief Dessin du circle central.
   /// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner une ellipse avec un gradient de couleur.

   QRadialGradient radialGrad2(QPointF(xc, yc), 50);
   radialGrad2.setColorAt(0, Qt::black);
   radialGrad2.setColorAt(1, "#e0e0d1");
   painter->setPen(QPen(Qt::transparent));
   painter->setBrush(QBrush(radialGrad2));
   painter->drawEllipse(qRound(xc-15),qRound(yc-15),30,30);

   ///
   ///\brief dessin de la flèche.
  ///\details On crée le gradient linear et un triangle, qu'on remplie avec un gradient de couleur. La position de la pointe de flèche est mathematiquement calculée.
  ///
  QLinearGradient linearGrad(QPointF(xc-(5*cos((A0-v-90)*rad)),yc+(5*sin((A0-v-90)*rad))), QPointF(xc+(5*cos((A0-v-90)*rad)),yc-(5*sin((A0-v-90)*rad))));
   linearGrad.setColorAt(0, "#F93737");
   linearGrad.setColorAt(0.5, "#ff3333");
   linearGrad.setColorAt(1, "#F93737");
   painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
   painter->setBrush(QBrush(linearGrad));
   QPointF points[3] = {
         QPointF(xc-5*cos((A0-v-90)*rad),yc+5*sin((A0-v-90)*rad)),

         QPointF(xc+(r-25)*cos((A0-v)*rad),yc-(r-25)*sin((A0-v)*rad)),
         QPointF(xc+5*cos((A0-v-90)*rad),yc-5*sin((A0-v-90)*rad))
          };

   painter->drawConvexPolygon(points, 3);

}

