#include "Inna/inna_scene.h"
#include <QPainter>
#include <QFontDatabase>
///
/// \file inna_scene.cpp
/// \brief Classe dérivée de scene_globale où sont ajoutés et paramétrés tous les composants du tableau de bord.
/// Tous les objets doivent être définis au préalable dans scene_globale.h
/// \param parent = scene_globale
///
inna_scene::inna_scene(scene_globale *parent):scene_globale(parent)
{   QFontDatabase::addApplicationFont(":/I_SevenSegment.ttf"); // adding custom fonts to the application
    QFontDatabase::addApplicationFont(":/I_mecheffects2bb_ital.ttf");
    QFontDatabase::addApplicationFont(":/I_mecheffects2bb_reg.ttf");


    setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern)); // setting the background to be solid black

    CompteurKm = new compteurKmInna();
        CompteurKm->setZValue(5.0);
        addItem(CompteurKm);
    speedometerInna = new SpeedometerInna();
        speedometerInna->setZValue(1.0); // setting the position in the scene item's order
        addItem(speedometerInna); // adding item to the scene
    tachometerInna = new TachometerInna();
        tachometerInna->setZValue(4.9);
        addItem(tachometerInna);
    oilgaugeInna = new OilGaugeInna();
        oilgaugeInna->setZValue(0.5);
        addItem(oilgaugeInna);
    infoInna = new InfoWindowInna ();
        infoInna->setZValue(1.0);
        addItem(infoInna);
    fuel_engineInna = new FuelEngineInna ();
        fuel_engineInna->setZValue(0.5);
        addItem(fuel_engineInna);
    Vitesse = new ArrowSpeedometerInna();
        Vitesse->setZValue(8.0);
        addItem(Vitesse);
    Essence = new FuelLevelInna ();
        Essence->setZValue(8.0);
        addItem(Essence);
    CompteTours = new ArrowTachometerInna();
        CompteTours->setZValue(10.0);
        addItem(CompteTours);
    Clignotant = new clignotantInna();
        addItem(Clignotant);
    jaugeTemperature = new EngineTInna ();
        jaugeTemperature->setZValue(8.0);
        addItem(jaugeTemperature);
    VoyantBatterie = new iconOnOffInna(QPoint(610,405),QSize(40,40),":/I_battery.gif",5.0);
        addItem(VoyantBatterie);
    position = new iconOnOffInna(QPoint(460,320),QSize(50,50),":/I_dayLight.gif",5.0);
        addItem(position);
    croisement = new iconOnOffInna(QPoint(460,320),QSize(50,50), ":/I_lowBeam.gif",5.0);
        addItem(croisement);
    route = new iconOnOffInna(QPoint(460,320),QSize(50,50), ":/I_highBeam.gif",5.0);
        addItem(route);
    warning = new iconOnOffInna(QPoint(680,230),QSize(40,40), ":/I_warning.gif", 5.0);
        addItem(warning);
    AdaptiveSuspensionDampers = new iconOnOffInna(QPoint(640,340),QSize(50,50),":/I_AdaptiveSuspensionDampers_yellow.gif",5.0);
        addItem(AdaptiveSuspensionDampers);
    AutomaticTransmissionMode = new PRND_Inna();
        AutomaticTransmissionMode->setZValue(5.0);
        addItem(AutomaticTransmissionMode);
    RearAntifog = new iconOnOffInna(QPoint(440,360),QSize(50,50),":/I_rearFogLight.gif",5.0);
        addItem(RearAntifog);
    FrontAntifog = new iconOnOffInna(QPoint(475,360),QSize(50,50),":/I_frontFogLight.gif",5.0);
        addItem(FrontAntifog);
    SeatBelt = new iconOnOffInna(QPoint(950,200),QSize(40,40),":/I_seatBeltSign_red.gif",5.0);
        addItem(SeatBelt);
    RearWindowHeating = new iconOnOffInna(QPoint(405,365),QSize(40,40),":/I_rearWindowHeating_yellow.gif",5.0);
        addItem(RearWindowHeating);
    CheckEngine = new iconOnOffInna(QPoint(900,415),QSize(50,50),":/I_checkEngine.gif",5.0);
        addItem(CheckEngine);
    OpenDoorDriver= new iconOnOffInna(QPoint(1005,210),QSize(60,60),":/I_driverDoorOpen.gif", 5.0 );
        addItem(OpenDoorDriver);
    OpenDoorFrontPassenger = new iconOnOffInna(QPoint(1005,210),QSize(60,60),":/I_frontRightDoorOpen.gif", 5.0 );
        addItem(OpenDoorFrontPassenger);
    OpenDoorBackLeftPassenger= new iconOnOffInna(QPoint(1005,210),QSize(60,60),":/I_backLeftDoorOpen.gif", 5.0 );
        addItem(OpenDoorBackLeftPassenger);
    OpenDoorBackRightPassenger = new iconOnOffInna(QPoint(1005,210),QSize(60,60),":/I_backrightDoorOpen.gif", 5.0 );
        addItem(OpenDoorBackRightPassenger);
    AdaptiveCruiseControl= new iconOnOffInna(QPoint(390,230),QSize(60,60),":/I_adaptiveCruiseControl_green.gif",5.0);
        addItem(AdaptiveCruiseControl);
    AirbagOn = new iconOnOffInna (QPoint(900,195),QSize(50,50),":/I_airBag.gif",5.0);
        addItem(AirbagOn);
    BonnetOpen =  new iconOnOffInna(QPoint(950,230),QSize(60,60),":/I_bonnetOpen_red.gif", 4.0 );
        addItem(BonnetOpen);
    BootOpen =  new iconOnOffInna(QPoint(885,230),QSize(60,60),":/I_bootOpen_red.gif", 4.0 );
        addItem(BootOpen);
    OilTemp = new ArrowOilTInna ();
        OilTemp->setZValue(8.0);
        addItem(OilTemp);
    oilLevel = new ArrowOilLInna();
        oilLevel->setZValue(10.0);
        addItem(oilLevel);
    ABS = new iconOnOffInna (QPoint(1005,415), QSize(50,50), ":/I_ABS_ON.gif",5.0);
        addItem(ABS);
    CruiseControlOn = new iconOnOffInna (QPoint(390,270),QSize(40,40),":/I_CruiseControl_green.gif",5.0);
    addItem(CruiseControlOn);
    handbrake = new iconOnOffInna (QPoint(955,415), QSize(50,50), ":/I_hand_brake.gif",5.0);
    addItem(handbrake);
    SpeedLimit = new iconOnOffInna();


}

QRectF inna_scene::boundingRect() const
{
    return QRectF(0,0,1400,600);
}

void inna_scene::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}
