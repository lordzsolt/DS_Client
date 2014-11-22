#pragma once

#include "Recipient.h"

#include "User.h"

#include <set>

class Group : public Recipient {
private:
    std::set<User*> users;

public:

    Group(int id, const std::string& name) : Recipient(id, name) {
    }

    virtual void sendMessage(std::string message) override;
};
