#pragma once

#include "../Models/RecipientModels/User.h"
#include "NetworkingControllers/Networking.h"

#include <memory>

class Session {
private:
    std::unique_ptr<User> _currentUser;
    Networking _networking;

public:
    Session();

    std::unique_ptr<User> const &getCurrentUser() const {
        return _currentUser;
    }

    Networking const &getNetworking() const {
        return _networking;
    }
};