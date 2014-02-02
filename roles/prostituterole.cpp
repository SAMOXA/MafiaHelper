#include "prostituterole.h"

prostituteRole::prostituteRole()
{
    roleName = "prostitute";
    peace = true;
    player = 0;
    actions << "Заткнуть";
}

void prostituteRole::invokeAction(uint actionNumber, Player* target)
{
    if(actionNumber == 0){
        target->setStatus(Player::Silenced);
    }
}
