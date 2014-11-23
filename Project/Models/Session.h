#include "User.h"

class Session {
private:
    std::shared_ptr <Session> activeSession;
    User currentUser;
    Session();

public:
    static const Session& activeSession();

    bool login(std::string username, std::string password);
};