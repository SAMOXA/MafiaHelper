#include "gamecontroller.h"

GameController::GameController(QObject *parent) :
    QObject(parent)
{
    round = 0;
    phase = Linch;
    selectedRole = "";
    actionId = -1;
    selectedPlayer = 0;
    menu << "Убить";
    menu << "Лишить голоса";
    menu << "Закончить день";
    mode = Idle;
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

void GameController::menuClick(int actionId)
{
    if(phase==Linch && actionId == 2){
        phase = Night;
        mode = Action;
        selectedRoleIter = rolesOrder.begin();
        menu.clear();
        menu = roles[*selectedRoleIter]->getActions();
        selectedPlayer = roles[*selectedRoleIter]->getPlayer()->getId();
        this->actionId = -1;
        emit phaseChanged();
        emit actionsChanged();
        foreach (Player* t, players) {
            if(t->getStatus() == Player::Silenced){
                t->setStatus(Player::Alive);
            }
        }
        return;
    }
    if(mode == Idle || mode == Action){
        this->actionId = actionId;
        mode = Action;
    }
}

void GameController::click(int playerId)
{
    if(players[playerId]->getMode() == Player::Centered){
        players[playerId]->setMode(Player::None);
        return;
    }
    if(players[playerId]->getMode() == Player::Selected){
        players[playerId]->setMode(Player::None);
        mode = Idle;
        return;
    }
    if(phase == Linch && mode == Idle){
        selectedPlayer = playerId;
        mode = Who;
        players[playerId]->setMode(Player::Selected);
        emit modeChanged();
        return;
    }
    if(mode == Who){
        //Голос
        mode = Whom;
        players[playerId]->setMode(Player::Selected);
        emit modeChanged();
        mode = Idle;
        players[playerId]->setMode(Player::None);
        players[selectedPlayer]->setMode(Player::None);
        emit modeChanged();
        return;
    }
    if(phase == Linch && mode == Action){
        switch (actionId) {
        case 0:
            players[playerId]->setStatus(Player::Killed);
            actionId = -1;
            break;
        case 1:
            players[playerId]->setStatus(Player::Silenced);
            actionId = -1;
            break;
        default:
            break;
        }
        mode = Whom;
        players[playerId]->setMode(Player::Selected);
        emit modeChanged();
        mode = Idle;
        players[playerId]->setMode(Player::None);
        emit modeChanged();
        return;
    }

    if(phase == Night && mode == Action){
        players[selectedPlayer]->getRole()->invokeAction(actionId, players[playerId]);
        do{
            selectedRoleIter++;
            if(selectedRoleIter == rolesOrder.end()){
                foreach (Player* t, players) {
                    if(t->getStatus() == Player::WasKilled){
                        t->setStatus(Player::Killed);
                    }
                }
                round++;
                phase = Linch;
                menu.clear();
                menu << "Убить";
                menu << "Лишить голоса";
                menu << "Закончить день";
                emit roundChanged();
                emit phaseChanged();
                emit actionsChanged();
                return;
            }
            emit selectedRoleChanged();
            menu.clear();
            menu = roles[*selectedRoleIter]->getActions();
        }while(menu.size() == 0 || roles[*selectedRoleIter]->getPlayer()->getStatus() == Player::Killed);
        selectedPlayer = roles[*selectedRoleIter]->getPlayer()->getId();
        emit actionsChanged();
        mode = Whom;
        players[playerId]->setMode(Player::Selected);
        emit modeChanged();
        mode = Action;
        players[playerId]->setMode(Player::None);
        emit modeChanged();
        return;
    }
    if(mode == Item){
        mode = Whom;
        players[playerId]->setMode(Player::Selected);
        emit modeChanged();
        mode = Idle;
        players[playerId]->setMode(Player::None);
        emit modeChanged();
    }
    if(mode == Selected){
        changeOrder(selectedPlayer, playerId);
        mode = Whom;
        players[playerId]->setMode(Player::Selected);
        emit modeChanged();
        mode = Idle;
        players[playerId]->setMode(Player::None);
        emit modeChanged();
        return;
    }
    qDebug() << "7";
}

void GameController::longClick(int playerId)
{
    players[playerId]->setMode(Player::Centered);
}

void GameController::itemClick(int playerId)
{

}

void GameController::setSwap(int playerId)
{
    players[playerId]->setMode(Player::Centered);
    selectedPlayer = playerId;
    mode = Selected;
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
    rolesOrder << "Мафия";
    rolesOrder << "Путана";
    rolesOrder << "Ведьма";
    rolesOrder << "Доктор";
    rolesOrder << "Коммисар";
    //rolesOrder << "Мафия";
    //rolesOrder << "Мафия";
    rolesOrder << "Бессмертный";
    selectedRoleIter = rolesOrder.begin();
    AbstractRole* t;
    Player* p;
    t = new doctorRole;
    addRole("Доктор", t);
    p = new Player;
    p->setRole(t);
    t->setPlayer(p);
    p->setName("One");
    addPlayer(p);
    t = new immortalRole;
    addRole("Бессмертный", t);
    p = new Player;
    p->setRole(t);
    t->setPlayer(p);
    p->setName("Two");
    addPlayer(p);
    t = new mafiaRole;
    addRole("Мафия", t);
    p = new Player;
    p->setRole(t);
    t->setPlayer(p);
    p->setName("Three");
    addPlayer(p);
    t = new policemanRole;
    addRole("Коммисар", t);
    p = new Player;
    p->setRole(t);
    t->setPlayer(p);
    p->setName("Four");
    addPlayer(p);
    t = new prostituteRole;
    addRole("Путана", t);
    p = new Player;
    p->setRole(t);
    t->setPlayer(p);
    p->setName("Five");
    addPlayer(p);
    t = new regularRole;
    addRole("Житель", t);
    p = new Player;
    p->setRole(t);
    t->setPlayer(p);
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
    t->setPlayer(p);
    p->setName("Seven");
    addPlayer(p);
}
