#pragma once

#include "../../Constants/ProtocolConstants.h"

#include <string>

class Message {
public:
    Message(MessageType const &type, int32_t index, MessageTag const &tag);

    std::string serialize(int32_t length);
    virtual std::string serialize() = 0;

    int32_t index() const {
        return _index;
    }

    static unsigned int headerLength();

protected:
    MessageType _type;
    int32_t _index;
    MessageTag _tag;
};
