#pragma once

#include "ErrorMessage.h"
#include "RecipientModels/User.h"

#include <string>

class Session {
private:
    User _currentUser;

public:
    Session();

    bool login(std::string username, std::string password, ErrorMessage& error);
    bool register(std::string username, std::string password, std::string rePassword, ErrorMessage& error);
};