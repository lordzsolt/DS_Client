#include "LoginMessage.h"

#include "../../../Constants/ProtocolConstants.h"

#include <sstream>

LoginMessage::LoginMessage(int index, MessageTag const &tag, std::string &username, std::string &password)
: Message(MessageType::Log_In, index, tag), username(username), password(password) {
}


std::string LoginMessage::serialize() {
    std::ostringstream bodyStream;
    bodyStream << kMessageKeyUsername << "=" << username;
    bodyStream << "&";
    bodyStream << kMessageKeyPassword << "=" << password;
    std::string body = bodyStream.str();

    std::string header = Message::serialize(body.length());

    std::string message = header + body;
    return message;

}