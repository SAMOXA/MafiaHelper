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
    void setMan(Player* man){ this->man = man; }
    Player* getMan() const { return man; }
protected:
    QStringList actions;
    QString roleName;
    bool peace;
    Player* man;
signals:

public slots:

};

#endif // ABSTRACTROLE_H
