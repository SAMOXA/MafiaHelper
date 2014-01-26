#include "gamecontroller.h"

GameController::GameController(QObject *parent) :
    QObject(parent)
{
    round = 0;
    phase = Linch;
    selectedRole = "Мафия";
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
    playersOrder.push_back(p);
    emit playersChanged();
}

Player*GameController::removePlayer(int id)
{
    Q_ASSERT(players.contains(id));
    Player* t;
    t = players[id];
    players.remove(id);
    playersOrder.removeAt(playersOrder.indexOf(t));
    emit playersChanged();
    return t;
}

QStringList GameController::getActions()
{
    return roles[selectedRole]->getActions();
}

QVariantList GameController::getPlayers()
{
    QVariantList t;
    foreach (Player* p, playersOrder) {
        t << QVariant::fromValue(p);
    }
    return t;
}

int GameController::getPlayersCount()
{
    return players.size();
}

void GameController::changeOrder(int index1, int index2)
{
    Player* t = playersOrder[index1];
    playersOrder[index1] = playersOrder[index2];
    playersOrder[index2] = t;
    emit playersChanged();
}


#include "roles/doctorrole.h"
#include "roles/immortalrole.h"
#include "roles/mafiarole.h"
#include "roles/policemanrole.h"
#include "roles/prostituterole.h"
#include "roles/regularrole.h"
#include "roles/sleepwalkerrole.h"
#include "roles/witchrole.h"
void GameController::cppSideInit()
{
    AbstractRole* t;
    Player* p;
    t = new doctorRole;
    addRole("Доктор", t);
    p = new Player;
    p->setRole(t);
    p->setName("One");
    addPlayer(p);
    t = new immortalRole;
    addRole("Бессмертный", t);
    p = new Player;
    p->setRole(t);
    p->setName("Two");
    addPlayer(p);
    t = new mafiaRole;
    addRole("Мафия", t);
    p = new Player;
    p->setRole(t);
    p->setName("Three");
    addPlayer(p);
    t = new policemanRole;
    addRole("Коммисар", t);
    p = new Player;
    p->setRole(t);
    p->setName("Four");
    addPlayer(p);
    t = new prostituteRole;
    addRole("Путана", t);
    p = new Player;
    p->setRole(t);
    p->setName("Five");
    addPlayer(p);
    t = new regularRole;
    addRole("Житель", t);
    p = new Player;
    p->setRole(t);
    p->setName("Six");
    addPlayer(p);
//    t = new sleepwalkerRole;
//    addRole("Лунатик", t);
//    p = new Player;
//    p->setRole(t);
//    addPlayer(p);
    t = new witchRole;
    addRole("Ведьма", t);
    p = new Player;
    p->setRole(t);
    p->setName("Seven");
    addPlayer(p);
}
