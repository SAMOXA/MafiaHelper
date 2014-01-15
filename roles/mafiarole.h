#ifndef MAFIAROLE_H
#define MAFIAROLE_H

#include "../player.h"
#include "../abstractrole.h"

class mafiaRole : public AbstractRole
{
public:
    mafiaRole();
    void invokeAction(uint actionNumber, Player* target);
};

#endif // MAFIAROLE_H
