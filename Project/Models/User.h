#pragma once

#include "Recipient.h"

class User : public Recipient {
//TODO: Add addition fields like profile image, username? password?

public:

    User(int id, const std::string& name) : Recipient(id, name) {
    }

    virtual void sendMessage(std::string message) override;
};
