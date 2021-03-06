#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include "Hugo/hugo_scene.h"
#include "Henri/henri_scene.h"
#include "Jonas/jonas_scene.h"
#include "Florian/sceneflorian.h"
#include "Lea/lea_scene.h"
#include "Leo/leo_scene.h"
#include "Karim/karim_scene.h"
#include "Loto/loto_scene.h"
#include "Inna/inna_scene.h"
#include "Youcef/youcef_scene.h"
#include "Harout/harout_scene.h"
#include "Kodjo/kodjo_scene.h"
#include "Maroua/maroua_scene.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void acceleration(int);
    void simulation(int);
    ~MainWindow();

private slots:
    void connexion();
    void reception();
    void update_km();
    void resizeEvent(QResizeEvent *event);
private:
   // Compteur * c;
    scene_globale *dashboard;
    Ui::MainWindow *ui;
    QTcpServer * server;
    QTcpSocket * socket;
    QTimer *updateTimer;
};

#endif // MAINWINDOW_H
