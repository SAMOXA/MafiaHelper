#ifndef REGULARROLE_H
#define REGULARROLE_H

#include "../player.h"
#include "../abstractrole.h"

class regularRole : public AbstractRole
{
public:
    regularRole();
    void invokeAction(uint actionNumber, Player* target);
};

#endif // REGULARROLE_H
