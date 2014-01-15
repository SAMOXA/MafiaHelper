#ifndef WITCHROLE_H
#define WITCHROLE_H

#include "../player.h"
#include "../abstractrole.h"

class witchRole : public AbstractRole
{
Q_OBJECT
public:
    explicit witchRole();
    void invokeAction(uint actionNumber, Player* target);
signals:
    void reset();
};

#endif // WITCHROLE_H
