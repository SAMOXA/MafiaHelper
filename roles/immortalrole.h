#ifndef IMMORTALROLE_H
#define IMMORTALROLE_H

#include "../player.h"
#include "../abstractrole.h"

class immortalRole : public AbstractRole
{
public:
    immortalRole();
    void invokeAction(uint actionNumber, Player* target);
};

#endif // IMMORTALROLE_H
