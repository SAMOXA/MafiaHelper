#include <QtGui/QGuiApplication>
#include <QtQml>
#include "qtquick2applicationviewer.h"
#include "pagestack.h"
#include "gamecontroller.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QtQuick2ApplicationViewer viewer;
    PageStack* ps = new PageStack;
    ps->addPageToSave(QString("GameField"));
    ps->addPageToSave(QString("MainMenu"));
    ps->setCurrentPage(QString("GameField"));
    qmlRegisterType<GameController>("Custom", 1, 0, "GameController");
    qmlRegisterType<Player>("Custom", 1, 0, "PlayerCpp");
    QQmlContext *root = viewer.rootContext();
    root->setContextProperty("pageStackBackend", ps);

    viewer.setMainQmlFile(QStringLiteral("qml/MafiaHelper/main.qml"));

    viewer.showExpanded();
    //viewer.showExpanded();
    return app.exec();
}
