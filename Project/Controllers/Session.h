#pragma once

#include "../Models/RecipientModels/User.h"
#include "NetworkingControllers/Networking.h"

#include <memory>

class Session {
private:
    std::unique_ptr<User> _currentUser;
    Networking _networking;

public:
    Session() = default;

    std::unique_ptr<User> const &getCurrentUser() const {
        return _currentUser;
    }

    Networking &getNetworking() {
        return _networking;
    }
};