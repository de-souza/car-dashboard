#include "Inna/arrowoiltinna.h"
#include <QFont>
#include <QtMath>
#include <QPainter>
///
/// \file arrowoiltinna.cpp
/// \brief Classe ArrowOilTInna derivée de la classe objet_virtuel
/// \details Permet la création de l' aiguille de la jauge de la température d'huile qui tourne en fonction de la valeur "value".
///
/// \param value - la valeur de la température d'huile
/// \param valueMax - la température d'huile maximum
/// \param A0 - l'aunge de debut de la jauge
/// \param Amax - l'ampleur de la jauge
/// \param r - le rayon de l'arche de la jauge
/// \param k - le coefficient pour convertir la valeur en degrés
///
ArrowOilTInna::ArrowOilTInna(objet_virtuel *parent) :  objet_virtuel(parent)
{   value = 80.0;
    tmax = 130 ;
    valueMax = tmax;
    A0 = 190 ;
    Amax = 90 ;
    r = 100;
    dx = 10;
    dy = 9;

}

ArrowOilTInna::ArrowOilTInna(int TMAX, int ALPHA0, int ALPHAMAX)
{   value=60.0;
    tmax = TMAX ;
    valueMax = tmax;
    A0 = ALPHA0 ;
    Amax = ALPHAMAX ;
    r = 100 ;
    dx = 10;
    dy = 9;

}

QRectF ArrowOilTInna::boundingRect() const
{
    QRectF rectf(0.0 , 0.0 , 1400.0 , 600.0);
    return rectf;
}

void ArrowOilTInna::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{ painter->setRenderHint(QPainter::Antialiasing); // for better smooth rendering
  
    double xot = xc + 30.0*cos((A0 - 15 - Amax / 2) * rad) ; //position of oil temperature arrow
    double yot = yc - 30.0*sin((A0 - 15 - Amax / 2) * rad);
    t = qRound(value);
   if (t < 60 || t > tmax) t = (t < 60 ? 60 : tmax); // condition to set the range and prevent arrow from pointing outside the scale

    
   ///
   ///\brief Dessin du circle central.
   /// \details On crée le gradient radial pour en suite instancier la brosse du *painter et dessiner une ellipse avec un gradient de couleur.


    QRadialGradient radialGradot(QPointF(xot, yot), 50);
    radialGradot.setColorAt(0, Qt::black);
    radialGradot.setColorAt(1, "#e0e0d1");

    painter->setPen(QPen(Qt::transparent));
    painter->setBrush(QBrush(radialGradot));
    painter->drawEllipse(qRound(xot-15),qRound(yot-15),30,30);

    if (t > 120 ) {painter->drawPixmap(120,360,40,40, QPixmap(":/I_Oil_t_red.gif"));}
    else {painter->drawPixmap(120,360,40,40, QPixmap(":/I_Oil_t_white.gif"));}



    ///
    ///\brief Dessin de la flèche.
    ///\details On crée le gradient linear et un triangle, qu'on remplie avec un gradient de couleur. La position de la pointe de flèche est mathematiquement calculée.


    k = (Amax+30) * 1.0 / (tmax - 60.0) ; // angle correction because the radius of a scale is not the same as the radius of the arrow trajectory

    QLinearGradient linearGradot(QPointF(xot-(5*cos((A0-k*(t-60)-90)*rad)),yot+(5*sin((A0-k*(t-60)-90)*rad))), QPointF(xot+(7*cos((A0-k*(t-60)-90)*rad)),yot-(7*sin((A0-k*(t-60)-90)*rad))));
    linearGradot.setColorAt(0, "#F93737");
    linearGradot.setColorAt(0.5, "#ff4d4d");
    linearGradot.setColorAt(1, "#F93737");

    painter->setPen(QPen(QBrush("#F93737",Qt::SolidPattern),2,Qt::SolidLine,Qt::SquareCap,Qt::RoundJoin));
    painter->setBrush(QBrush(linearGradot));
    QPointF points[3] = {
        QPointF(xot-(5*cos((A0-k*(t-60)-90)*rad)),yot+(5*sin((A0-k*(t-60)-90)*rad))),
        QPointF(xot+(r-15)*cos((A0-k*(t-60))*rad),yot-5-(r-15)*sin((A0-k*(t-60))*rad)),
        QPointF(xot+(5*cos((A0-k*(t-60)-90)*rad)),yot-(5*sin((A0-k*(t-60)-90)*rad))),
       };

    painter->drawConvexPolygon(points, 3);
    

}

