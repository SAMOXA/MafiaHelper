#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QMap>
#include "abstractrole.h"
#include "player.h"

typedef QMap<QString, AbstractRole*> RolesMap;
typedef QMap<int, Player*> PlayersMap;

class GameController : public QObject
{
    Q_OBJECT
    Q_ENUMS(Phase)
    Q_PROPERTY(RolesMap roles READ getRoles NOTIFY rolesChanged)
    Q_PROPERTY(PlayersMap players READ getPlayers NOTIFY playersChanged)
    Q_PROPERTY(int selectedPlayer READ getSelectedPlayer NOTIFY selectedPlayerChanged)
    Q_PROPERTY(QString selectedRole READ setSelectedRole NOTIFY selectedRoleChanged)
    Q_PROPERTY(int round READ getRound NOTIFY roundChanged)
    Q_PROPERTY(Phase phase READ getPhase NOTIFY phaseChanged)
public:
    enum Phase{
        Night,
        Results,
        Linch
    };
    explicit GameController(QObject *parent = 0);
    RolesMap& getRoles(){ return roles; }
    PlayersMap& getPlayers(){ return players; }
    int getSelectedPlayer(){ return selectedPlayer; }
    QString setSelectedRole(){ return selectedRole; }
    int getRound(){ return round; }
    Phase getPhase(){ return phase; }

    void addRole(QString name, AbstractRole* ptr);
    AbstractRole* removeRole(QString name);
    void addPlayer(Player* p);
    Player* removePlayer(int id);

    Q_INVOKABLE QStringList getActions();
private:
    QMap <QString, AbstractRole*> roles;
    QMap <int, Player*> players;
    int selectedPlayer;
    QString selectedRole;
    int round;
    Phase phase;
signals:
    void rolesChanged();
    void playersChanged();
    void selectedPlayerChanged();
    void selectedRoleChanged();
    void roundChanged();
    void phaseChanged();
public slots:

};

#endif // GAMECONTROLLER_H
