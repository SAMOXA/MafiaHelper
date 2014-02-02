#include "doctorrole.h"

doctorRole::doctorRole()
{
    roleName = "doctor";
    peace = true;
    player = 0;
    actions << "Вылечить";
}

void doctorRole::invokeAction(uint actionNumber, Player* target)
{
    if(actionNumber == 0){
        if(target->getStatus() == Player::WasKilled || target->getStatus() == Player::Silenced){
            target->setStatus(Player::Alive);
        }
    }
}
