#ifndef POLICEMANROLE_H
#define POLICEMANROLE_H

#include "../player.h"
#include "../abstractrole.h"

class policemanRole : public AbstractRole
{
public:
    policemanRole();
    void invokeAction(uint actionNumber, Player* target);
};

#endif // POLICEMANROLE_H
