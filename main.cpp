#include <QtGui/QGuiApplication>
#include <QtQml>
#include "qtquick2applicationviewer.h"
#include "pagestack.h"
#include "gamecontroller.h"

#include "roles/doctorrole.h"
#include "roles/immortalrole.h"
#include "roles/mafiarole.h"
#include "roles/policemanrole.h"
#include "roles/prostituterole.h"
#include "roles/regularrole.h"
#include "roles/sleepwalkerrole.h"
#include "roles/witchrole.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    GameController* gc = new GameController;
//////////////////////////////////////////
    AbstractRole* t;
    Player* p;
    t = new doctorRole;
    gc->addRole("Доктор", t);
    p = new Player;
    p->setRole(t);
    gc->addPlayer(p);
    t = new immortalRole;
    gc->addRole("Бессмертный", t);
    p = new Player;
    p->setRole(t);
    gc->addPlayer(p);
    t = new mafiaRole;
    gc->addRole("Мафия", t);
    p = new Player;
    p->setRole(t);
    gc->addPlayer(p);
    t = new policemanRole;
    gc->addRole("Коммисар", t);
    p = new Player;
    p->setRole(t);
    gc->addPlayer(p);
    t = new prostituteRole;
    gc->addRole("Путана", t);
    p = new Player;
    p->setRole(t);
    gc->addPlayer(p);
    t = new regularRole;
    gc->addRole("Житель", t);
    p = new Player;
    p->setRole(t);
    gc->addPlayer(p);
//    t = new sleepwalkerRole;
//    gc->addRole("Лунатик", t);
//    p = new Player;
//    p->setRole(t);
//    gc->addPlayer(p);
    t = new witchRole;
    gc->addRole("Ведьма", t);
    p = new Player;
    p->setRole(t);
    gc->addPlayer(p);
//////////////////////////////////////////
    PageStack* ps = new PageStack;
    ps->addPageToSave(QString("GameField"));
    ps->addPageToSave(QString("MainMenu"));
    ps->setCurrentPage(QString("GameField"));
    qmlRegisterType<GameController>("Custom", 1, 0, "GameController");
    QQmlContext *root = viewer.rootContext();
    root->setContextProperty("pageStackBackend", ps);
    root->setContextProperty("gameControllerBackend", gc);

    viewer.setMainQmlFile(QStringLiteral("qml/MafiaHelper/main.qml"));

    viewer.showExpanded();
    //viewer.showExpanded();
    return app.exec();
}
