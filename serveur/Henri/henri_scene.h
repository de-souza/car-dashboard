#ifndef SCENEGLOBALE_H
#define SCENEGLOBALE_H
#include <QMainWindow>
#include "scene_globale.h"
#include "objet_virtuel.h"
#include "jaugeclignotanthenri.h"
#include "jaugeessencehenri.h"
#include "cadranthenri.h"
#include "jaugetemperaturehenri.h"
#include "jaugetoursminutehenri.h"
#include "scenedefondhenri.h"
#include "affichekmhenri.h"
#include "warninghenri.h"
#include "onoff.h"
#include "porteshenri.h"
#include "onoffpainthenri.h"
#include "stophenri.h"


class henri_scene : public scene_globale
{
public:
    henri_scene(scene_globale *parent=nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    sceneDeFondHenri *fond;
    stopHenri *stop;
};



#endif // SCENEGLOBALE_H
