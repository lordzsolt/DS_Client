#include "Message.h"
#include "../../Constants/ProtocolConstants.h"

#include <sstream>

Message::Message(MessageType const &type, int index, MessageTag const &tag): type(type), index(index), tag(tag) {
}

std::string Message::serialize(int length) {
    std::ostringstream stream;
    stream << index << "|";
    stream << getMessageType(type) << "|";
    stream << getMessageTag(tag) << "|";
    stream << length;
    return stream.str();
}