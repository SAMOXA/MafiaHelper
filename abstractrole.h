#ifndef ABSTRACTROLE_H
#define ABSTRACTROLE_H

#include <QObject>
#include <QStringList>

class Player;

class AbstractRole : public QObject
{
    Q_OBJECT
public:
    explicit AbstractRole(QObject *parent = 0):
        QObject(parent)
    {}
    virtual ~AbstractRole(){}
    virtual void invokeAction(uint actionNumber, Player* target) = 0;
    QString getName() const { return roleName; }
    bool getPeace(){ return peace; }
    void setPlayer(Player* man){ this->player = man; }
    Player* getPlayer() const { return player; }
    QStringList& getActions(){ return actions; }
protected:
    QStringList actions;
    QString roleName;
    bool peace;
    Player* player;
signals:

public slots:

};

#endif // ABSTRACTROLE_H
