#include "player.h"
//TODO make h. only
int Player::freeId = 0;

Player::Player(QObject *parent) :
    QObject(parent)
{
    id = freeId++;
    status = Alive;
    mode = None;
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

bool Player::canKilled() const
{
    return role->getName() != "immortal";
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
int Player::getVotes() const
{
    return votes;
}

void Player::incVotes()
{
    votes++;
}

void Player::decVotes()
{
    votes--;
}

void Player::resetVotes()
{
    votes = 0;
}

void Player::saveCoords(qreal x, qreal y)
{
    this->x = x;
    this->y = y;
}

qreal Player::restoreX()
{
    return x;
}

qreal Player::restoreY()
{
    return y;
}

void Player::saveScale(qreal scale)
{
    this->scale = scale;
}

qreal Player::restoreScale()
{
    return scale;
}

Player::Mode Player::getMode() const
{
    return mode;
}

void Player::setMode(const Mode& value)
{
    mode = value;
    emit modeChanged();
}
Player::Status Player::getStatus() const
{
    return status;
}

void Player::setStatus(const Status& value)
{
    status = value;
    emit statusChanged();
}

