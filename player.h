#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <abstractrole.h>

class Player : public QObject
{
    Q_OBJECT
    Q_ENUMS(Mode)
    Q_ENUMS(Status)
    Q_PROPERTY(int id READ getId NOTIFY idChanged)
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)
    Q_PROPERTY(QString role READ getRoleString NOTIFY roleChanged)
    Q_PROPERTY(Mode mode READ getMode NOTIFY modeChanged)
    Q_PROPERTY(Status status READ getStatus NOTIFY statusChanged)

public:
    enum Mode{
        None,
        Selected,
        Centered,
    };
    enum Status{
        Alive,
        WasKilled,
        Killed,
        Silenced
    };

    explicit Player(QObject *parent = 0);

    AbstractRole* getRole() const;
    QString getRoleString() const;
    void setRole(AbstractRole* value);

    bool canKilled() const;

    int getId() const;
    int getFreeId();

    QString getName() const;
    void setName(const QString& value);

    int getVotes() const;
    void incVotes();
    void decVotes();
    void resetVotes();

    Q_INVOKABLE void saveCoords(qreal x, qreal y);
    Q_INVOKABLE qreal restoreX();
    Q_INVOKABLE qreal restoreY();
    Q_INVOKABLE void saveScale(qreal scale);
    Q_INVOKABLE qreal restoreScale();
    Mode getMode() const;
    void setMode(const Mode& value);
    Status getStatus() const;
    void setStatus(const Status& value);

private:
    AbstractRole* role;
    int id;
    static int freeId;
    QString name;
    int votes;

    qreal x, y; //Coords
    qreal scale;
    Mode mode;
    Status status;
signals:
    void nameChanged();
    void roleChanged();
    void idChanged();
    void modeChanged();
    void statusChanged();
public slots:

};

#endif // PLAYER_H
