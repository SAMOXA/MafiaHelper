#include "player.h"

Player::Player(QObject *parent) :
    QObject(parent)
{
}
AbstractRole* Player::getRole() const
{
    return role;
}

void Player::setRole(AbstractRole* value)
{
    role = value;
}
bool Player::canSpeak() const
{
    return silence;
}

void Player::setSilence(bool value)
{
    silence = value;
}
bool Player::isKilled() const
{
    return killed;
}

void Player::setKilled(bool value)
{
    killed = value;
}

bool Player::canKilled() const
{
    return role->getName() == "immortal";
}



