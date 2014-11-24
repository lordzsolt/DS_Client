#include "Group.h"

void Group::sendMessage(std::string message) {
    for (User* user : this->users) {
        user->sendMessage(message);
    }
}