#include "GroupMessage.h"

#include "../../../Constants/ProtocolConstants.h"

#include <sstream>

GroupMessage::GroupMessage(int index, MessageTag const &tag, const int recipientId, const std::string &message)
        : Message(MessageType::Group_Message, index, tag), recipientId(recipientId), message(message) {
}

std::string GroupMessage::serialize() {
    std::ostringstream bodyStream;
    bodyStream << kMessageKeyRecipientId << "=" << recipientId;
    bodyStream << "&";
    bodyStream << kMessageKeyMessage << "=" << message;
    std::string body = bodyStream.str();

    std::string header = Message::serialize(body.length());
    std::string message = header + body;
    return message;
}