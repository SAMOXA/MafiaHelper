#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QMap>
#include <QVariantList>
#include <QVector>
#include "abstractrole.h"
#include "player.h"

class GameController : public QObject
{
    Q_OBJECT
    Q_ENUMS(Phase)
    Q_ENUMS(Mode)
    Q_PROPERTY(QVariantList players READ getPlayers NOTIFY playersChanged)
    Q_PROPERTY(QStringList actions READ getActions NOTIFY actionsChanged)
    Q_PROPERTY(Mode mode READ getMode NOTIFY modeChanged)
    Q_PROPERTY(QString selectedRole READ getSelectedRole NOTIFY selectedRoleChanged)
    Q_PROPERTY(int round READ getRound NOTIFY roundChanged)
    Q_PROPERTY(Phase phase READ getPhase NOTIFY phaseChanged)
public:
    enum Phase{
        Night,
        Results,
        Linch
    };
    enum Mode{
        Idle,
        Action,
        Who,
        Whom,
        Item,
        Selected
    };

    explicit GameController(QObject *parent = 0);
    QVariantList getPlayers();
    QString getSelectedRole(){ return *selectedRoleIter; }
    int getRound() const { return round; }
    Phase getPhase() const { return phase; }
    Mode getMode() const { return mode; }
    QStringList getActions() { return menu; }

    void addRole(QString name, AbstractRole* ptr);
    AbstractRole* removeRole(QString name);
    void addPlayer(Player* p);
    Player* removePlayer(int id);


    Q_INVOKABLE int getPlayersCount();
    Q_INVOKABLE void menuClick(int actionId);
    Q_INVOKABLE void click(int playerId);
    Q_INVOKABLE void longClick(int playerId);
    Q_INVOKABLE void itemClick(int playerId);
    Q_INVOKABLE void setSwap(int playerId);
    Q_INVOKABLE void changeOrder(int index1, int index2);
    Q_INVOKABLE void cppSideInit();


private:
    QMap <QString, AbstractRole*> roles;
    QMap <int, Player*> players;
    QVector <Player*> playersOrder;
    QVector <QString> rolesOrder;
    QStringList menu;
    QString selectedRole;
    QVector <QString>::iterator selectedRoleIter;
    int round;
    Phase phase;
    Mode mode;
    int actionId;
    int selectedPlayer;
signals:
    void rolesChanged();
    void playersChanged();
    void selectedPlayerChanged();
    void selectedRoleChanged();
    void roundChanged();
    void phaseChanged();
    void actionsChanged();
    void modeChanged();
    void actionIdChanged();
public slots:

};

#endif // GAMECONTROLLER_H
