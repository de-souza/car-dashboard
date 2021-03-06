#include "cadrantflorian.h"
#include <QDebug>
#include <QtMath>
#include <QLinearGradient>

/**
 * @brief CadrantFlorian::CadrantFlorian
 * @param hasText
 * @param hasSubTrait
 * @param invertAiguille
 * @param pas
 * @param angleB
 * @param angleE
 * @param valeurMax
 * @param parent
 */
CadrantFlorian::CadrantFlorian(bool hasText, bool hasSubTrait,int invertAiguille, int pas, int angleB, int angleE, int valeurMax, bool hasGradient, QGraphicsItem * parent):objet_virtuel(parent)
{
    this->invertAiguille = invertAiguille;
    this->hasText = hasText;
    this->hasSubTrait = hasSubTrait;
    this->width = 200;
    this->pas = pas;
    this->height = 200;
    this->valueMax = valeurMax;
    this->angleB = angleB;
    this->angleE = angleE;
    this->value = 0;
    this->hasGradient = hasGradient;
}

/**
 * @brief CadrantFlorian::boundingRect
 * @return retourne un rectangle qui encadre l'objet
 */
QRectF CadrantFlorian::boundingRect()const
{
    QRectF rect(0,0,width,height);
    return rect;
}
// paint la scène
/**
 * @brief CadrantFlorian::paint
 * @param painter
 * @details dessine les différents éléments du compteur : aiguille, compteur, chiffre...
 */
void CadrantFlorian::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing); // ajout de l antialiasing au tableau de bord
    if(this->hasGradient == true){
        QLinearGradient gradient(QPointF(0,0),QPointF(200,200));
        gradient.setColorAt(0,QColor(100,100,100,90));
        gradient.setColorAt(1,QColor(0,0,0,255));

        painter->setBrush(QBrush(gradient));
        painter->drawEllipse(0,0,height, width);
    }
    QPen pen2(QColor(10,10,200));
    QPen pen1((QColor(Qt::gray)));
    QPen pen3((QColor(Qt::white)));


    pen1.setWidth(1);
    QFont font = QFont();
    font.setPixelSize(9);
    pen2.setWidth(1);
    painter->setPen(pen2);
    // dessine plusieurs cercles pour le compteur pour donner un effet de flou en variant l'alpha
    painter->drawArc(0, 0, width-2, height-2, 16*(angleB+10),(-angleE-20)*16);
    pen2.setColor(QColor(10,10,200,175));
    pen2.setWidth(3);
    painter->setPen(pen2);
    painter->drawArc(0, 0, width-1, height-1, 16*(angleB+10),(-angleE-20)*16);
    pen2.setColor(QColor(10,10,200,120));
    QBrush b((QColor(Qt::red)));
    pen2.setWidth(5);
    painter->setPen(pen2);
    painter->drawArc(0, 0, width, height, 16*(angleB+10),(-angleE-20)*16);

    painter->setBrush(b);
    painter->setPen(pen1);
    float f = generateAngle();
    QPointF * p = (QPointF *) malloc(sizeof(QPointF)*4);
    //dessine l'aiguille en fonction de si elle est à l'envers ou non (droite ou gauche)
    if(invertAiguille==1){
        p[0].setX(width/2.0);
        p[0].setY(height/2.0);
        p[1].setX(cos(qDegreesToRadians((-angleB+10+f)*1.0))*(15.0)+ width/2.0);
        p[1].setY(sin(qDegreesToRadians((-angleB+10+f)*1.0))*(15.0) + height/2.0);
        p[2].setX(cos(qDegreesToRadians((-angleB+f)*1.0))*(width/2.0-25)+ width/2.0);
        p[2].setY(sin(qDegreesToRadians((-angleB+f)*1.0))*(height/2.0-25) + height/2.0);
        p[3].setX(cos(qDegreesToRadians((-angleB-10+f)*1.0))*(15.0)+ width/2.0);
        p[3].setY(sin(qDegreesToRadians((-angleB-10+f)*1.0))*(15.0) + height/2.0);
    }
    else{

        p[0].setX((width/2.0)*1.0);
        p[0].setY((height/2.0)*1.0);
        p[1].setX(cos(qDegreesToRadians((-angleB+10+angleE+f)*1.0))*(15.0)+ width/2.0);
        p[1].setY(sin(qDegreesToRadians((-angleB+10+angleE+f)*1.0))*(15.0) + height/2.0);
        p[2].setX(cos(qDegreesToRadians((-angleB+angleE+f)*1.0))*(width/2.0-25)+ width/2.0);
        p[2].setY(sin(qDegreesToRadians((-angleB+angleE+f)*1.0))*(height/2.0-25) + height/2.0);
        p[3].setX(cos(qDegreesToRadians((-angleB+angleE-10+f)*1.0))*(15.0)+ width/2.0);
        p[3].setY(sin(qDegreesToRadians((-angleB+angleE-10+f)*1.0))*(15.0) + height/2.0);
    }
    painter->drawPolygon(p,4);
    painter->setPen(pen3);
    painter->setFont(font);
    int pair = 0;
    //dessine les petits traits, le texte...
    for(int i=0; i <= this->valueMax; i+=pas){
        float val = (float)angleE/valueMax* i;
        if(pair % 2 == 1 && this->hasSubTrait == true){
            painter->drawLine(cos(qDegreesToRadians(-angleB+val))*(width/2-5)+ width/2,
                              sin(qDegreesToRadians(-angleB+val))*(height/2-5) + height/2,
                              cos(qDegreesToRadians(-angleB+val))*(width/2-7)+ width/2,
                              sin(qDegreesToRadians(-angleB+val))*(height/2-7) + height/2);
        }
        else{
            painter->drawLine(cos(qDegreesToRadians(-angleB+val))*(width/2-5)+ width/2,
                          sin(qDegreesToRadians(-angleB+val))*(height/2-5) + height/2,
                          cos(qDegreesToRadians(-angleB+val))*(width/2-10)+ width/2,
                          sin(qDegreesToRadians(-angleB+val))*(height/2-10) + height/2);
        }
        //ajoute le texte s'il y a besoin
        if(hasText == 1 && pair % 2 == 0){
            painter->drawText(cos(qDegreesToRadians(-angleB+val))*(width/2-20)+ width/2-6,
                              sin(qDegreesToRadians(-angleB+val))*(height/2-20) + height/2+2, QString("%1").arg(i));
        }

        pair++;
    }
}

/**
 * @brief CadrantFlorian::generateAngle
 * @return la valeur de l'angle en fonction de la value et de la value max
 */
float CadrantFlorian::generateAngle()
{
    float angle = 0.0f;
    angle = (float)value/valueMax * angleE;
    //qDebug() << value << " " << angle;
    return angle;
}
