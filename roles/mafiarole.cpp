#include "mafiarole.h"

mafiaRole::mafiaRole()
{
    roleName = "mafia";
    peace = false;
    man = 0;
    actions << "Убить";
}

void mafiaRole::invokeAction(uint actionNumber, Player* target)
{
    if(actionNumber == 0){
        if(target->canKilled()){
            target->setKilled(true);
        }
    }
}
