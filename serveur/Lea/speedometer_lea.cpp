///
/// \file speedometer_lea.cpp
/// \brief Classe speedometer, permettant la création du compteur vitesse paramétrable avec aiguille.
/// \details Classe héritée de objet_virtuel. L'appel au constructeur permet d'initialiser la totalité des paramètres, et la fonction paint permet l'affichage.
///


#include "speedometer_lea.h"
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QtDebug>
#include <QPointF>

///
/// \brief speedometer_Lea::speedometer_Lea Constructeur de la classe, permet d'initialiser tous les paramètres ainsi que la valeur value de la classe mère à 0
/// \param param_x position horizontale du centre du compteur
/// \param param_y position verticale du centre du compteur
/// \param param_r rayon du compteur et taille de l'aiguille
/// \param param_start Angle de départ pour le tracé de l'arc de cercle
/// \param param_end Angle de fin pour le tracé de l'arcle de cercle
/// \param param_spanAngle angle total du cadran
/// \param param_param_vitMax determine la vitesse maximum jusqu'à laquelle va le cadran
///

speedometer_Lea::speedometer_Lea(double param_x, double param_y, double param_r, int param_start, int param_spanAngle, int param_vitMax)

{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    span_angle=param_spanAngle;
    valueMax=param_vitMax;
    value=0;
}

QRectF speedometer_Lea::boundingRect() const
{
    QRectF rectf(0,0,1000,500);
    return rectf;
}

///
/// \brief speedometer_Lea::paint Fonction permettant l'affichage du compteur
/// \details Cette fonction construit un compteur en plusieurs étapes : création du cadran, des graduations, ajout du texte sur les graduations, ajout de l'aiguille.
/// \param painter
///

void speedometer_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
///
/// \brief calibration de "value"
/// \details La variable "value" donnée par la fonction getValue() de la classe objet_virtuel est mise a 0 si la valeur entrée est inferieur à 0 et mise à "valueMax" si la valeur entrée est plus grande.
///

    if (value>=0 && value <=valueMax) {v=qRound(value);}
    else if (value<0) {v=0;}
    else {v=valueMax;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);
///
/// \brief Création du cadran.
/// \details Le cadran est basé sur un arc de cercle déssiné à l'aide de la fonction drawArc. le cercle est dessiné avec un QPen a qui a été donné une QBrush contenant un gradient radial de couleur bleu.
///
    // ******************** Dessine l'arc au dessus du compteur

    painter->setRenderHint(QPainter::Antialiasing);

            QRadialGradient radial(QPointF(x,y),r+20);
            radial.setColorAt(0,Qt::transparent);
            radial.setColorAt(0.95,Qt::blue);
            radial.setColorAt(1,Qt::transparent);
            painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
            painter->drawArc(qRound(x-r-20),qRound(y-r-20),qRound(r*2)+40,qRound(r*2)+40,(angle_debut+85)*16,(span_angle+10)*16);
            pen.setColor(Qt::transparent);
            pen.setCapStyle(Qt::RoundCap);
            painter->setPen(pen);

///
/// \brief Création des graduations du cadran.
/// \details Les graduations sont créées en utilisant la fonction drawLine et une boucle if pour changer la couleur des graduations à 50, 90 et 130km/h. Les graduations sont déssinées tous les 10km/h.
///
// ******************** Dessine les traits du compteur vitesse
    {   pen.setColor(Qt::white);
        for (int i=0;i<=valueMax;i+=10)
        {
        i%20==0 ? pen.setWidth(5) : pen.setWidth(2) ;
        pen.setColor(Qt::white);
            if (i==50 || i==90 || i==130)
            {
                pen.setColor(Qt::red);
            }
            pen.setCapStyle(Qt::FlatCap);
            pen.setStyle(Qt::SolidLine);
            painter->setPen(pen);

            painter->drawLine(qRound(x+r*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-r*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(x+(r-20)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y-(r-20)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))));
///
/// \brief Ajout du texte sur les graduations
/// \details Le texte est positionné de la même façon que les graduations, tous les 20km/h, avec une translation de manière à correspondre le plus possible aux positions des graduations.
///
            pen.setColor(Qt::white);
            painter->setPen(pen);
            painter->setRenderHint(QPainter::Antialiasing);
            QFont font("Bell",12, QFont::Bold);
            painter->setFont(font);
        if (i%20==0)
            painter->drawText(qRound(x-15+(r-40)*(cos((angle_debut-(i*span_angle/valueMax))*pi/180))),qRound(y+8-(r-40)*(sin((angle_debut-(i*span_angle/valueMax))*pi/180))),QString("%1").arg(i));
//ajoute un delta au x (-15) et au y (+8) pour que le texte se retrouve en face des graduations (sinon les nombres de plus de trois chiffres empiètent sur les graduations).
        }
    }

///
///\brief Création de l'aiguille.
/// \details Dans un premier temps, affichage de l'aiguille à l'aide de la fonction drawConvexPolygon. Puis affichage d'un petit cercle à la base de l'aiguille.
///

// ******************** Dessine l'aiguille


    painter->setRenderHints(QPainter::Antialiasing);
    brush.setStyle(Qt::SolidPattern);
    pen.setWidth(1);
    pen.setColor(Qt::red);
    brush.setColor(Qt::red);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->setBrush(brush);
    QPointF points[3] =
    {
          QPointF(x-9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y+9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180)),     //x -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
          QPointF(x+r*(cos((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180)), y-r*(sin((angle_debut-(span_angle*1.0f/valueMax)*value)*pi/180))),
          QPointF(x+9*cos((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180),y-9*sin((angle_debut-(span_angle*1.0f/valueMax)*value-90)*pi/180))
     };

    painter->drawConvexPolygon(points, 3);


// ******************** Dessine le cercle au centre du cadran par dessus la fin de l'aiguille(deux cercles l'un sur l'autre avec un gradient linéaire inversé
    pen.setColor(Qt::transparent);
    QLinearGradient linearGradie(QPointF(x-15, y-15), QPointF(x+15, y-15));
       linearGradie.setColorAt(0,"#9d0409" );
       linearGradie.setColorAt(1,Qt::red);
    QBrush brush9(linearGradie)  ;
    painter->setPen(pen);
    painter->setBrush(brush9);
    painter->drawEllipse(x-20,y-20,40,40);

brush.setColor(Qt::black);
QLinearGradient linearGradi(QPointF(x+15, y+15), QPointF(x-15, y-15));
   linearGradi.setColorAt(0, "#9d0409");
   linearGradi.setColorAt(1,"#5e0407");
QBrush brush8(linearGradi)  ;
painter->setPen(pen);
painter->setBrush(brush8);
painter->drawEllipse(x-15,y-15,30,30);

///
///\brief Création de l'affichage de la vitesse.
///\details L'affichage de la vitesse se fait avec la fonction drawText et en utilisant la variable "value" donnée par la fonction getValue() de la classe objet_virtuel.
///
// ******************** Dessine l'affichage de la vitesse avec une police d'ecriture intégrée dans les ressources et appelée dans lea_scene.cpp

pen.setColor(Qt::white);

QFont font("Seven Segment",30,QFont::Bold);
painter->setFont(font);
QRectF affiche_km_h (x-90,y+30,80,70);
pen.setCapStyle(Qt::SquareCap);
painter->setPen(pen);
painter->drawText(affiche_km_h, Qt::AlignRight ,QString("%1").arg(qRound(value)));

QFont font2("Seven Segment",10,QFont::Bold);
painter->setFont(font2);
painter->drawText(qRound(x+10),qRound(y+65),"km/h");

}


