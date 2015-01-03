#include "Message.h"
#include "../../Constants/ProtocolConstants.h"

#include <sstream>

Message::Message(MessageType const &type, int32_t index, MessageTag const &tag): _type(type), _index(index), _tag(tag) {
}

std::string Message::serialize(int32_t length) {
    std::ostringstream stream(std::stringstream::out | std::stringstream::binary);

    stream.write(reinterpret_cast<char*>(&_index), sizeof(_index));
    int32_t messageType = getMessageType(_type);
    stream.write(reinterpret_cast<char*>(&messageType), sizeof(messageType));
    int32_t messageTag = getMessageTag(_tag);
    stream.write(reinterpret_cast<char*>(&messageTag), sizeof(messageTag));
    stream.write(reinterpret_cast<char*>(&length), sizeof(length));

    return stream.str();
}