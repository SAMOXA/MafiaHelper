#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <abstractrole.h>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId)
    Q_PROPERTY(bool silence READ canSpeak NOTIFY silenceChanged)
    Q_PROPERTY(bool killed READ isKilled NOTIFY killedChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
public:
    explicit Player(QObject *parent = 0);

    AbstractRole* getRole() const;
    void setRole(AbstractRole* value);

    bool canSpeak() const;
    void setSilence(bool value);

    bool isKilled() const;
    void setKilled(bool value);

    bool canKilled() const;

    int getId();
    int getFreeId();

    QString getName() const;
    void setName(const QString& value);

private:
    AbstractRole* role;
    int id;
    static int freeId;
    bool silence;
    bool killed;
    QString name;
signals:
    void silenceChanged();
    void killedChanged();
    void nameChanged();
public slots:

};

#endif // PLAYER_H
