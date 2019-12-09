#ifndef STOPHENRI_H
#define STOPHENRI_H
#include "objet_virtuel.h"
#include <QTest>

class stopHenri : public objet_virtuel
{
public:
    stopHenri();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int cligno;
    void MAJ();
};

#endif // STOPHENRI_H