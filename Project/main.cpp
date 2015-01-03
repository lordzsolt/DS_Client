#include "Constants/ProtocolConstants.h"
#include "Controllers/Session.h"
#include "Controllers/NetworkingControllers/Networking.h"
#include "Models/MessageModels/Messages/LoginMessage.h"
#include "Models/MessageModels/Messages/RegisterMessage.h"

#include <iostream>
#include <iomanip>
#include <unistd.h>


using namespace std;

int main() {

    Session activeSession;
    string password = "123456";
    string username;
    Networking networking = activeSession.getNetworking();
    do {
        cout << endl << "Username = ";
        cin >> username;
        NetworkingCallback lamdaCallback = [] (bool success) {
            cout << "Success";
        };
        networking.login(username, password, lamdaCallback);
    } while (username != "X");

    return 0;
}