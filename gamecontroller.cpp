#include "gamecontroller.h"

GameController::GameController(QObject *parent) :
    QObject(parent)
{
    round = 0;
    phase = Linch;
    selectedRole = "Ведьма";
}

void GameController::addRole(QString name, AbstractRole* ptr)
{
    Q_ASSERT(!roles.contains(name));
    roles[name] = ptr;
    emit rolesChanged();
}

AbstractRole*GameController::removeRole(QString name)
{
    Q_ASSERT(roles.contains(name));
    AbstractRole* t;
    t = roles[name];
    roles.remove(name);
    emit rolesChanged();
    return t;
}

void GameController::addPlayer(Player* p)
{
    Q_ASSERT(!players.contains(p->getId()));
    players[p->getId()] = p;
    emit playersChanged();
}

Player*GameController::removePlayer(int id)
{
    Q_ASSERT(players.contains(id));
    Player* t;
    t = players[id];
    players.remove(id);
    emit playersChanged();
    return t;
}

QStringList GameController::getActions()
{
    return roles[selectedRole]->getActions();
}
