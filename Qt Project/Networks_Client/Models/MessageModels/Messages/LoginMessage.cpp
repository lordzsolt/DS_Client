#include "LoginMessage.h"

#include "../../../Constants/ProtocolConstants.h"

#include <sstream>

using namespace std;

LoginMessage::LoginMessage(int index, MessageTag const &tag, std::string &username, std::string &password)
        : Message(MessageType::Log_In, index, tag), _username(username), _password(password)
{
}


LoginMessage::LoginMessage(int index, MessageTag const &tag, std::string &body)
        : Message(MessageType::Log_In, index, tag)
{
    //TODO: Implement
//    tokenizer<char_separator<char>> tokens(body, separator);
//    for (const auto& t : tokens) {
//        if (t == kMessageKeyUsername) {
//            _username = t;
//        }
//        else if (t == kMessageKeyPassword) {
//            _password = t;
//        }
//    }
}


std::string LoginMessage::serialize() {
    std::ostringstream bodyStream;
    bodyStream << kMessageKeyUsername << "=" << _username;
    bodyStream << "&";
    bodyStream << kMessageKeyPassword << "=" << _password;
    std::string body = bodyStream.str();

    std::string header = Message::serialize(body.length());

    std::string message = header + body;
    return message;
}
