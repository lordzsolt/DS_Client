#pragma once

#include "string"

class Recipient {
public:
    Recipient(int id, const std::string& name) : id(id), name(name) {
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    virtual void sendMessage(std::string message) = 0;

protected:
    int id;
    std::string name;
};