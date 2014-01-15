#ifndef DOCTORROLE_H
#define DOCTORROLE_H

#include "../player.h"
#include "../abstractrole.h"

class doctorRole : public AbstractRole
{
public:
    doctorRole();
    void invokeAction(uint actionNumber, Player* target);
};

#endif // DOCTORROLE_H
