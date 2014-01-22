#include "witchrole.h"

witchRole::witchRole()
{
    roleName = "witch";
    peace = true;
    player = 0;
    actions << "Убить";
    actions << "Круг защиты";
}

void witchRole::invokeAction(uint actionNumber, Player* target)
{
    if(actionNumber == 0){
        if(target->canKilled()){
            target->setKilled(true);
        }
    }
    if(actionNumber == 1){
        emit reset();
    }
}
