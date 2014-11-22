#include "Session.h"

const Session& Session::activeSession() {
    if (!this->activeSession) {
        this->activeSession = Session();
    }
    return this->activeSession;
}