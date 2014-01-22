#include "player.h"
//TODO make h. only
int Player::freeId = 0;

Player::Player(QObject *parent) :
    QObject(parent)
{
    id = freeId++;
    silence = false;
    killed = false;
}

AbstractRole* Player::getRole() const
{
    return role;
}

QString Player::getRoleString() const
{
    return role->getName();
}

void Player::setRole(AbstractRole* value)
{
    role = value;
    emit roleChanged();
}
bool Player::canSpeak() const
{
    return silence;
}

void Player::setSilence(bool value)
{
    silence = value;
    emit silenceChanged();
}
bool Player::isKilled() const
{
    return killed;
}

void Player::setKilled(bool value)
{
    killed = value;
    killedChanged();
}

bool Player::canKilled() const
{
    return role->getName() == "immortal";
}

int Player::getId() const
{
    return id;
}

int Player::getFreeId()
{
    return freeId;
}
QString Player::getName() const
{
    return name;
}

void Player::setName(const QString& value)
{
    name = value;
    nameChanged();
}
