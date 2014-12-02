#include "Constants/ProtocolConstants.h"
#include "Controllers/Session.h"
#include "Models/MessageModels/Messages/LoginMessage.h"

#include <iostream>

using namespace std;

int main() {
    Session activeSession();
    std::string username("Anyad");
    std::string password("Szia");
    LoginMessage message(0,MessageTag::New, username, password);
    cout << message.serialize();
//    if (!activeSession.login()) {
//
//    }
    return 0;
}