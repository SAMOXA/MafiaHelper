#include "gamecontroller.h"

GameController::GameController(QObject *parent) :
    QObject(parent)
{
}

void GameController::addRole(QString name, AbstractRole* ptr)
{

}

AbstractRole*GameController::removeRole(QString name)
{

}

void GameController::addPlayer(Player* p)
{

}

Player*GameController::removePlayer(int id)
{

}
