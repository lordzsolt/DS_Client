#include "LoginMessage.h"

LoginMessage::LoginMessage(int index, MessageTag tag, std::string &username, std::string &password)
        : username(username), password(password) {
    Message::Message(getMessageType(Log_In), index, tag);
}