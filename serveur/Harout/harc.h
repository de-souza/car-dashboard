#ifndef HARC_H
#define HARC_H
#include <objet_virtuel.h>

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QColor>
#include <QDebug>

class Harc : public objet_virtuel
{
public:
    Harc(int, int,QString/* QString,QString */);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
private:
    int A = 250;
    int B = 250;
    QRectF rec     = QRectF(0,0, A, B);
    QRectF rec2;
    int startAngle = 30 * 16;  //C'est pour arc
    int spanAngle  = 120 * 16;//C'est pour arc
    int spanAngle0;
    QString type;
//    QString param_text2;
//    QString param_text3;

};

#endif // HARC_H
