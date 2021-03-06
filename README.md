# Projet dashboard
Ce document a pour but de clarifier l'ensemble des opérations nécéssaires afin
d'intégrer au programme un dashboard ou une fonctionnalité, de lister
l'ensemble des fonctionnalités/objets disponibles, et de répertorier les
éventuels bugs apparus lors de l'utilisation du programme.

## Intégrer son projet au serveur
Cette section explique en détails la manière d'intégrer son dashboard au
serveur. Le but premier du serveur est de permettre un changement dynamiqueme de
dashboard à la suite d'un simple message du client. Il est également important
d'harmoniser le nommage des différents objets ainsi que de de leur fonction, et
ce afin que le programme soi fonctionnel pour l'ensemble des dashboards. Ainsi,
il est nécéssaire de suivre les étapes suivantes avant d'intégrer son projet au
serveur.

* Une classe scene\_globale, dérivant de QGraphicsScene a été créée. Elle permet
de pouvoir passer dynamiquement d'un dashboard à un autre. Votre classe scène,
que vous pouvez nommer prénom_scene et qui contient l'ensemble de vos éléments
graphiques, doit donc elle même hériter de scene\_globale. 
* De même, une classe objet_virtuel contenant 3 méthodes (setValue, setValueMax,
getValue) a été créée. Toutes vos classes compteur, voyant, jauge, etc...
doivent hériter de cette classe, afin de rendre tous les objets fonctionnels. 
* Une fois l'ensemble de ces opérations effectuées, votre projet devrait être en
mesure d'intégrer le serveur. On objet scene_globale *dashboard a déjà été
intégré à "mainwindow.h". Il vous suffit donc de rajouter un #include
"prénom_scene" dans le "mainwindow.h". Ensuite, dans la fonction
MainWindow::reception() de "mainwindow.cpp", vous pouvez définir votre
dashboard dans la partie correspondant au message "CAN DASHBOARD":
    - delete dashboard; --> permet de supprimer le dashboard défini au
    préalable.
    - dashboard = new prénom_scene;--> définit l'objet dashboard avec votre
    classe dérivant de scene_globale.
    - ui->graphicsView->setScene(dashboard);-->attribut votre scène au
    QgraphicsView.

   Une fois votre scène intégrée au serveur, il est alors possible d'y intégrer
   de nouveaux objets et fonctionnalités. Vous pouvez tester la réussite de
   l'intégration de votre dashboard en envoyant le message CAN DASHBOARD prénom
   à partir du client.

## Intégration d'un nouvel objet au client et au serveur

L'ensemble des objets accessibles pour tous les dashboards sont définis en tant
que objet_virtuel dans "scene_globale.h". Ceci implique qu'un dashboard ne doit
pas obligatoirement posséder in situ l'ensemble des objets et fonctionnalités
définis dans "scene_globale.h". Il est en revanche bien évidemment déconseillé
de lancer à partir du client des messages CAN concernant des fonctionnalités
non inclues dans votre dashboard. Suivez ces différentes étapes pour ajouter un
objet au programme:

* Dans un premier temps, il faut créer votre message CAN de la forme "CAN votre_message " dans le client. Dans le fichier clientio.c, ajouter "votre_message" à la liste des commandes déjà disponibles de la fonction validate_message.
Puis dans le fichier main.c du client, ajoutez votre commande "CAN votre_message" ainsi qu'une brève description de votre message dans la commande "HELP" de la fonction main.
* Puis, dans le fichier mainwindow.cpp du serveur, ajoutez votre message sous forme de condition dans la liste déjà présente de la fonction reception. N'hésitez pas à rajouter des conditions pour vérifier si les valeurs associées à votre message sont acceptables.

## Liste des messages CAN

| Objet                      | Description                                                                      | Message CAN                      | Valeurs                                                                 |
|:-------------------------- |:--------------------------------------------------------------------------------:|:---------------------------------:| -----------------------------------------------------------------------:|
| Vitesse                    | Compteur vitesse                                                                 | CAN SPEED X                      | X=vitesse                                                               |
| CompteTours                | Compteur tour/min moteur                                                         | CAN RPM X                        | X=rpm                                                                   |
| VoyantBatterie             | Voyant indiquant changement de batterie                                          | CAN BATTERY_LIGHT                | 0 éteint,1 allumé                                                       |
| Essence                    | Jauge essence                                                                    | CAN GAZ X                        | X=%d'essence restant                                                    |
| position                   | Feux de position                                                                 | CAN LIGHT X                      | 0=éteint, 1=allumé                                                      |
| croisement                 | Feux de croisement                                                               | CAN LIGHT X                      | 0=éteint, 2=allumé                                                      |
| route                      | Feux de route                                                                    | CAN LIGHT X                      | 0=éteint, 3=allumé                                                      |
| Clignotant                 | Allume les clignotants gauche, droit ou les deux ensemble (feux d'avertissement) | CAN TURN X                       | 1=clignotant droit,-1=clignotant gauche, 2 clignotant les deux 0=éteint |
| Warning                    | Allume le warning et met la valeur des clignotants à 2                           | CAN WARNING X                    | 0=éteint, 1=allumé                                                      |
| AdaptiveSuspensionDampers  | Voyant indiquant que ASD est utilisé                                             | CAN ASD X                        | 0 éteint, 1 allumé                                                      |
| AutomaticTransmissionMode  | Indique le mode de transmission actuellement utilisé                             | CAN MODE  X                      | 1=P, 2=R, 3=N, 4=D                                                      |
| FrontAntifog               | feux de brouillard avants                                                        | CAN FRONT_FOG X                  | 0=éteint, 1=allumé                                                      |
| RearAntifog                | feux de brouillard arrières                                                      | CAN REAR_FOG X                   | 0=éteint, 1=allumé                                                      |
| SeatBelt                   | Ceinture de securité                                                             | CAN SEAT_BELT X                  | 0=éteint, 1=allumé                                                      |
| RearWindowHeating          | Chauffage de la glace arrière                                                    | CAN RW_HEAT X                    | 0=éteint, 1=allumé                                                      |
| CheckEngine                | Voyant d'anomalie du moteur                                                      | CAN CHECK_ENGINE X               | 0=éteint, 1=allumé                                                      |
| OpenDoorDriver             | Porte avant conducteur ouverte                                                   | CAN OPEN_DOOR_DRIVER X           | 0=éteint, 1=allumé                                                      |
| OpenDoorFrontPassenger     | Porte avant passager ouverte                                                     | CAN OPEN_DOOR_FRONT_PASSENGER X  | 0=éteint, 1=allumé                                                      |
| OpenDoorBackRightPassenger | Porte arrière droite ouverte                                                     | CAN OPEN_DOOR_BACK_R_PASSENGER X | 0=éteint, 1=allumé                                                      |
| OpenDoorBackLeftPassenger  | Porte arrière gauche ouverte                                                     | CAN OPEN_DOOR_BACK_L_PASSENGER X | 0=éteint, 1=allumé                                                      |
| AdaptiveCruiseControl      | Voyant qui s'allume quand "AdaptiveCruiseControl" est activé                     | CAN CRUISE_CONTROL X             | 0=éteint, 1=allumé                                                      |
| AirbagOn                   | Voyant qui s'allume quand "AirBag" est activé                                    | CAN AIRBAG_ON X                  | 0=éteint, 1=allumé                                                      |
| BonnetOpen                 | Voyant qui s'allume quand le capot est ouvert                                    | CAN BONNET_OPEN X                | 0=éteint, 1=allumé                                                      |
| BootOpen                   |  Voyant qui s'allume quand le coffre est ouvert                                  | CAN BOOT_OPEN X                  | 0=éteint, 1=allumé                                                      |
| CruiseControlOn            | Voyant qui s'allume quand le limitateur de vitesse est activé et met la vitesse à la valeur choisie                   | CAN CRUISE_CONTROL_ON X          | X=vitesse de croisière choisie                                                      |
| OitTemp                    | Temperature de l'huile dans le moteur                                            | CAN OIL_T X                      | x  entre 0 et  value_max                                                                     |
| oilLevel                    | Niveau de l'huile dans le moteur                                            | CAN OIL_L X                      | x  entre 0 et  value_max                                                                     |
| jaugeTemperature           | la température du moteur                                                         | CAN ENGINE_T X                   | x  jusqu'au  value_max                                                  | 
| SpeedLimit                 | Affichage de la limite de vitesse                                                | CAN SPEED_LIMIT X                | X=Limite de vitesse        
| ABS                        | ABS                                                                              | CAN ABS X                      | 0=éteint, 1=allumé                                                      |
|handbrake		| Frein à main enclanché								|CAN HANDBRAKE X			|0=éteint, 1=allumé							|
                                             |

## Bugs répertoriés
