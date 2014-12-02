#include "../Message.h"

#include <string>

enum class MessageTag : int;

class LoginMessage : public Message {
public:

    LoginMessage(int index, MessageTag const &tag, std::string &username, std::string &password);

    std::string serialize();

protected:
    std::string username;
    std::string password;
};

