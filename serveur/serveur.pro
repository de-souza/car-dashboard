#-------------------------------------------------
#
# Project created by QtCreator 2019-11-12T17:29:26
#
#-------------------------------------------------

QT       += core gui network

QT += testlib

linux-buildroot-g++ {
    target.path     = root
    INSTALLS       += target
}
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serveur
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Henri/henri_scene.cpp \
    Henri/cadranthenri.cpp \
    Henri/jaugeclignotanthenri.cpp \
    Henri/jaugeessencehenri.cpp \
    Henri/jaugetemperaturehenri.cpp \
    Henri/jaugetoursminutehenri.cpp \
    Henri/scenedefondhenri.cpp \
    Hugo/hugo_compteur.cpp \
    Hugo/hugo_mygraphicsitem.cpp \
    Hugo/hugo_scene.cpp \
    Hugo/hugo_voyants_clignotant.cpp \
    Hugo/hugo_voyants_simples.cpp \
    Jonas/jonas_compteur.cpp \
    Jonas/jonas_scene.cpp \
    Youcef/cardialerprototype.cpp \
    Youcef/carspeeddial.cpp \
    Youcef/engineheatgauge.cpp \
    Youcef/flashinglight_youss.cpp \
    Youcef/fuelgauge.cpp \
    Youcef/indicator_youss.cpp \
    Youcef/maindisplay_youcef.cpp \
    Youcef/tachometer.cpp \
    Youcef/warning_youss.cpp \
    Youcef/youcef_scene.cpp \
    main.cpp \
    mainwindow.cpp \
    objet_virtuel.cpp \
    scene_globale.cpp \
    Florian/sceneflorian.cpp \
    Florian/florianvoyant.cpp \
    Florian/cadrantflorian.cpp \
    Florian/florianclignotant.cpp \
    Henri/affichekmhenri.cpp \
    Henri/warninghenri.cpp \
    Hugo/hugo_ecran.cpp \
    Hugo/hugo_voyant_warning.cpp \
    Jonas/jonas_voyant_simple.cpp \
    Lea/fuelgauge_lea.cpp \
    Lea/lea_scene.cpp \
    Lea/speedometer_lea.cpp \
    Lea/tachometergauge_lea.cpp \
    Lea/voyant_lea.cpp \
    Lea/lea_clignottants.cpp \
    Florian/floriancompteurkm.cpp \
    Karim/cadranEss.cpp \
    Karim/cadrantourparmin.cpp \
    Karim/CadranVitesse.cpp \
    Karim/clignot.cpp \
    Karim/karim_scene.cpp \
    Hugo/hugo_boite_vitesse.cpp \
    Loto/fuel_guage.cpp \
    Loto/leds.cpp \
    Loto/loto_dashboard.cpp \
    Loto/tachometre.cpp \
    Loto/tempgauge.cpp \
    Loto/loto_scene.cpp \
    Lea/lea_scenedefond.cpp \
    Jonas/jonas_voyant_clignotant.cpp \
    Inna/arrowspeedometerinna.cpp \
    Inna/arrowtachometerinna.cpp \
    Inna/clignotantinna.cpp \
    Inna/enginetinna.cpp \
    Inna/fuellevelinna.cpp \
    Inna/iconinna.cpp \
    Inna/infowindowinna.cpp \
    Inna/inna_scene.cpp \
    Inna/oilgaugeinna.cpp \
    Inna/speedometerinna.cpp \
    Inna/tachometerinna.cpp \
    Inna/icononoffinna.cpp \
    Inna/arrowoillinna.cpp \
    Inna/arrowoiltinna.cpp \
    Inna/fuelengineinna.cpp \
    Inna/prnd_inna.cpp \
    Inna/compteurkminna.cpp \
    Jonas/jonas_voyant_warning.cpp \
    Jonas/jonas_compteurkm.cpp \
    Henri/porteshenri.cpp \
    Henri/onoff.cpp \
    Henri/onoffpainthenri.cpp \
    Lea/warning_lea.cpp \
    Lea/jauge_temperature_lea.cpp \
    Lea/compteur_kilometre_lea.cpp \
    Lea/horloge_lea.cpp \
    Harout/harout_scene.cpp \
    Harout/cadran.cpp \
    Kodjo/kodjo_scene.cpp \
    Kodjo/Cadran_Kodjo.cpp \
    Karim/voyants_warning.cpp \
    Karim/voyants_karim.cpp \
    Maroua/cadrantcontour.cpp \
    Maroua/cadrantessence.cpp \
    Maroua/cadranttempmoteur.cpp \
    Maroua/cadranttour.cpp \
    Maroua/cadrantvitesse.cpp \
    Maroua/maroua_scene.cpp \
    Maroua/voyantsmaroua.cpp \
    Harout/harc.cpp \
    Maroua/warningmaroua.cpp \
    Maroua/autresvoyants.cpp \
    Henri/stophenri.cpp \
    Leo/leo_gauge.cpp \
    Leo/leo_limit.cpp \
    Leo/leo_object.cpp \
    Leo/leo_scene.cpp \
    Loto/blinkingleds.cpp \
    Loto/kmcalculator.cpp \
    Harout/hvoyant.cpp \
    Harout/hvoyantwarning.cpp \
    Harout/hclignotant.cpp



   

HEADERS += \
    Henri/jaugeclignotanthenri.h \
    Henri/cadranthenri.h \
    Henri/henri_scene.h \
    Henri/jaugeclignotanthenri.h \
    Henri/jaugeessencehenri.h \
    Henri/jaugetemperaturehenri.h \
    Henri/jaugetoursminutehenri.h \
    Henri/scenedefondhenri.h \
    Henri/stophenri.h \
    Hugo/hugo_compteur.h \
    Hugo/hugo_mygraphicsitem.h \
    Hugo/hugo_scene.h \
    Hugo/hugo_voyants_clignotant.h \
    Hugo/hugo_voyants_simples.h \
    Jonas/jonas_compteur.h \
    Jonas/jonas_scene.h \
    Leo/leo_gauge.h \
    Leo/leo_limit.h \
    Leo/leo_object.h \
    Leo/leo_scene.h \
    Youcef/cardialerprototype.h \
    Youcef/carspeeddial.h \
    Youcef/engineheatgauge.h \
    Youcef/flashinglight_youss.h \
    Youcef/fuelgauge.h \
    Youcef/indicator_youss.h \
    Youcef/maindisplay_youcef.h \
    Youcef/tachometer.h \
    Youcef/warning_youss.h \
    Youcef/youcef_scene.h \
    mainwindow.h \
    objet_virtuel.h \
    scene_globale.h \
    Florian/sceneflorian.h \
    Florian/cadrantflorian.h \
    Florian/florianvoyant.h \
    Florian/florianclignotant.h \
    Henri/affichekmhenri.h \
    Henri/warninghenri.h \
    Hugo/hugo_ecran.h \
    Hugo/hugo_voyant_warning.h \
    Jonas/jonas_voyant_simple.h \
    Lea/fuelgauge_lea.h \
    Lea/lea_scene.h \
    Lea/speedometer_lea.h \
    Lea/tachometergauge_lea.h \
    Lea/voyant_lea.h \
    Lea/lea_clignottants.h \
    Karim/cadranEss.h \
    Karim/cadrantourparmin.h \
    Karim/CadranVitesse.h \
    Karim/clignot.h \
    Karim/karim_scene.h \
    Hugo/hugo_boite_vitesse.h \
    Loto/fuel_guage.h \
    Loto/leds.h \
    Loto/loto_dashboard.h \
    Loto/tachometre.h \
    Loto/tempgauge.h \
    Loto/loto_scene.h \
    Lea/lea_scenedefond.h \
    Jonas/jonas_voyant_clignotant.h \
    Inna/tachometerinna.h \
    Inna/speedometerinna.h \
    Inna/oilgaugeinna.h \
    Inna/inna_scene.h \
    Inna/infowindowinna.h \
    Inna/iconinna.h \
    Inna/fuellevelinna.h \
    Inna/enginetinna.h \
    Inna/clignotantinna.h \
    Inna/arrowtachometerinna.h \
    Inna/arrowspeedometerinna.h \
    Inna/icononoffinna.h \
    Inna/arrowoillinna.h \
    Inna/arrowoiltinna.h \
    Inna/fuelengineinna.h \
    Inna/prnd_inna.h \
    Inna/compteurkminna.h \
    Henri/porteshenri.h \
    Henri/onoff.h \
    Florian/floriancompteurkm.h \
    Jonas/jonas_voyant_warning.h \
    Jonas/jonas_compteurkm.h \
    Henri/onoffpainthenri.h \
    Lea/warning_lea.h \
    Lea/jauge_temperature_lea.h \
    Lea/compteur_kilometre_lea.h \
    Lea/horloge_lea.h \
    Harout/harout_scene.h \
    Harout/cadran.h \
    Harout/harc.h \
    Kodjo/kodjo_scene.h \
    Kodjo/Cadran_Kodjo.h \
    Karim/voyants_warning.h \
    Karim/voyants_karim.h \
    Maroua/cadrantcontour.h \
    Maroua/cadrantessence.h \
    Maroua/cadranttempmoteur.h \
    Maroua/cadranttour.h \
    Maroua/cadrantvitesse.h \
    Maroua/maroua_scene.h \
    Maroua/voyantsmaroua.h \
    Maroua/warningmaroua.h \
    Maroua/autresvoyants.h \
    Loto/kmcalculator.h \
    Harout/hvoyant.h \
    Harout/hvoyantwarning.h \
    Harout/hclignotant.h



FORMS += \
        mainwindow.ui \

RESOURCES += \
    Henri/images.qrc \
    Hugo/Icones/icones.qrc \
    Jonas/icons-dashboard/icons-dashboard.qrc \
    #florian.qrc \
    Karim/icone.qrc \
    Karim/newfont.qrc \
    Loto/myicons/icons.qrc \
    Inna/InnaRSC/inna.qrc \
    Lea/Lea.qrc \
    Florian/florian.qrc \
    Youcef/Youcef.qrc \
    Kodjo/kodjo.qrc \
    Harout/Icones/hicones.qrc


DISTFILES += \
    Henri/iconeEssence.png \
    Henri/iconeSurchaufe.png \
    Henri/liserMoi \
    Karim/LCDfont.ttf \
    Loto/myicons/Oil_white.pix \
    Loto/myicons/4WD_blue.gif \
    Loto/myicons/4WD_green.gif \
    Loto/myicons/4WD_red.gif \
    Loto/myicons/4WD_white.gif \
    Loto/myicons/4WD_yellow.gif \
    Loto/myicons/ABS_ON.gif \
    Loto/myicons/adaptiveCruiseControl_green.gif \
    Loto/myicons/adaptiveHeadlight.gif \
    Loto/myicons/AdaptiveSuspensionDampers_red.gif \
    Loto/myicons/AdaptiveSuspensionDampers_yellow.gif \
    Loto/myicons/airBag.gif \
    Loto/myicons/airSuspention_red.gif \
    Loto/myicons/airSuspention_yellow.gif \
    Loto/myicons/auto_D.gif \
    Loto/myicons/auto_N.gif \
    Loto/myicons/auto_P.gif \
    Loto/myicons/auto_R.gif \
    Loto/myicons/AWD_blue.gif \
    Loto/myicons/AWD_green.gif \
    Loto/myicons/AWD_red.gif \
    Loto/myicons/AWD_white.gif \
    Loto/myicons/AWD_yellow.gif \
    Loto/myicons/backLeftDoorOpen.gif \
    Loto/myicons/backrightDoorOpen.gif \
    Loto/myicons/battery.gif \
    Loto/myicons/bonnetOpen_red.gif \
    Loto/myicons/bootOpen_red.gif \
    Loto/myicons/brake_warning.gif \
    Loto/myicons/brakeBulbFailure_yelow.gif \
    Loto/myicons/brakeLiquid_red.gif \
    Loto/myicons/brakePads.gif \
    Loto/myicons/BulbFailure_yelow.gif \
    Loto/myicons/checkEngine.gif \
    Loto/myicons/dayLight.gif \
    Loto/myicons/driverDoorOpen.gif \
    Loto/myicons/engineT_blue.gif \
    Loto/myicons/engineT_red.gif \
    Loto/myicons/engineT_white.gif \
    Loto/myicons/engineT_yellow.gif \
    Loto/myicons/ExclamationPoint_red.gif \
    Loto/myicons/ExclamationPoint_yellow.gif \
    Loto/myicons/frontFogLight.gif \
    Loto/myicons/frontRightDoorOpen.gif \
    Loto/myicons/fuelL_red.gif \
    Loto/myicons/fuelL_white.gif \
    Loto/myicons/hazardLights.gif \
    Loto/myicons/highBeam.gif \
    Loto/myicons/lowBattery.gif \
    Loto/myicons/lowBeam.gif \
    Loto/myicons/OFF.gif \
    Loto/myicons/Oil_t_white.gif \
    Loto/myicons/Oil_white.gif \
    Loto/myicons/powerSteering_red.gif \
    Loto/myicons/powerSteering_yellow.gif \
    Loto/myicons/rearFogLight.gif \
    Loto/myicons/rearFogLight_blue.gif \
    Loto/myicons/rearWindowHeating_yellow.gif \
    Loto/myicons/scoda.gif \
    Loto/myicons/seatBeltSign_red.gif \
    Loto/myicons/securityLight_red.gif \
    Loto/myicons/securityLight_yellow.gif \
    Loto/myicons/tractionControl_blue.gif \
    Loto/myicons/tractionControl_green.gif \
    Loto/myicons/tractionControl_red.gif \
    Loto/myicons/tractionControl_white.gif \
    Loto/myicons/tractionControl_yellow.gif \
    Loto/myicons/turnLeft.gif \
    Loto/myicons/turnRight.gif \
    Loto/myicons/tyrePressure_red.gif \
    Loto/myicons/tyrePressure_yellow.gif \
    Loto/myicons/washerLiquid_yellow.gif \
    Loto/myicons/black-leather-texture-background.jpg \
    Loto/myicons/bonnetOpen.png \
    Loto/myicons/brake.png \
    Loto/myicons/engineT_red.png \
    Loto/myicons/gearProblem.png \
    Loto/myicons/hand_brake.png \
    Loto/myicons/Oil_red.png \
    Loto/myicons/Oil_white.png \
    Loto/myicons/seatBelt.png
