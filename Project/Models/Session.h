#include "User.h"

class Session {
private:
    std::shared_ptr <Session> activeSession;
    User currentUser;
    Session();

public:
    const Session& activeSession();
};