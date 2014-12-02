#pragma once

#include "../../Constants/ProtocolConstants.h"

#include <string>

class Message {
public:
    Message(MessageType const &type, int index, MessageTag const &tag);

    std::string serialize(int length);
    virtual std::string serialize() = 0;
protected:
    MessageType type;
    int index;
    MessageTag tag;
};