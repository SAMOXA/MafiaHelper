#ifndef PROSTITUTEROLE_H
#define PROSTITUTEROLE_H

#include "../player.h"
#include "../abstractrole.h"

class prostituteRole : public AbstractRole
{
public:
    prostituteRole();
    void invokeAction(uint actionNumber, Player* target);
};

#endif // PROSTITUTEROLE_H
