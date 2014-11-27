#pragma once

#include "../Models/ErrorMessage.h"
#include "../Models/RecipientModels/User.h"

#include "NetworkingControllers/Networking.h"

#include <string>
#include <memory>
#include <unordered_set>

class Session {
private:
    std::unique_ptr<User> _currentUser;
    Networking _networking;

public:
    Session();

    std::unique_ptr<User> const &get_currentUser() const {
        return _currentUser;
    }

    bool login(std::string username, std::string password, ErrorMessage& error);
    bool signup(std::string username, std::string password, std::string rePassword, ErrorMessage& error);
    bool sendMessage(std::string message, std::unordered_set<int> recipientIds);
};