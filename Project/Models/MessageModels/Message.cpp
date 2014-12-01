#include "Message.h"

Message::Message(MessageType const &type, int index, MessageTag const &tag): type(type), index(index), tag(tag) {
}

virtual std::string Message::serialize(int length) = 0 {
    std::ostringstream stream;
    stream << length << "|";
    stream << type << "|";
    stream << tag << "|";
    return stream.str();
}