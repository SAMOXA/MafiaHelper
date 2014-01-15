#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <abstractrole.h>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

    AbstractRole* getRole() const;
    void setRole(AbstractRole* value);

    bool canSpeak() const;
    void setSilence(bool value);

    bool isKilled() const;
    void setKilled(bool value);

    bool canKilled() const;

private:
    AbstractRole* role;
    bool silence;
    bool killed;
signals:

public slots:

};

#endif // PLAYER_H
