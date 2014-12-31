#include <winsock.h>
#include "Networking.h"

#include "../../Constants/ProtocolConstants.h"

Networking::Networking() {
    int iResult;
    WSADATA wsaData;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
        return;
    }

    _messenger = Messenger(kServerAddress, kServerPort);
}


void Networking::login(std::string username, std::string password, NetworkCallback callback) const {
    MessengerCallback lamdaCallback = [] (bool success) {
        callback(success);
    };
    _messenger.sendLogin(username, password, lamdaCallback);
}


void Networking::signup(std::string username, std::string password, NetworkCallback callback) const {

}


void Networking::privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const {

}


void Networking::groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const {

}