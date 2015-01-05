#pragma once

#include "../Models/RecipientModels/User.h"
#include "NetworkingControllers/Networking.h"

#include <memory>

class Session {
private:
    std::unique_ptr<User> _currentUser;
    Networking _networking;

    Session() = default;
    Session(Session const&);
    void operator=(Session const&);

public:
    static Session& activeSession() {
        static Session instance;
        return instance;
    }

    std::unique_ptr<User> const &getCurrentUser() const {
        return _currentUser;
    }

    Networking &networking() {
        return _networking;
    }
};
