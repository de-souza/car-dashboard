#ifndef VOYANTSMAROUA_H
#define VOYANTSMAROUA_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "objet_virtuel.h"
#include <QTest>
class VoyantsMaroua : public objet_virtuel
{

public:
    VoyantsMaroua();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void activate();
  int clignotant;

};

#endif // VOYANTSMAROUA_H
