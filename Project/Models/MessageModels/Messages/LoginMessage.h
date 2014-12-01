#include "../Message.h"

#include <string>

class MessageTag;

class LoginMessage :public Message {
public:

    LoginMessage(int index, MessageTag tag, std::string &username, std::string &password);

protected:
    std::string username;
    std::string password;
};