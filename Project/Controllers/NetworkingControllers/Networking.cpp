#include "Networking.h"

#include <winsock.h>
#include <functional>

#include "../../Constants/ProtocolConstants.h"

Networking::Networking() : Networking(initializeWSA()) {
}


Networking::Networking(nullptr_t t) : _messenger(kServerAddress, kServerPort) {
}


nullptr_t Networking::initializeWSA() {
    int iResult;
    WSADATA wsaData;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %d\n", iResult);
    }
    return nullptr;
}


void Networking::login(std::string username, std::string password, NetworkingCallback callback) {
    MessengerCallback lamdaCallback = [&callback] (bool success) {
        callback(success);
    };
    _messenger.sendLogin(username, password, lamdaCallback);
}


void Networking::signup(std::string username, std::string password, NetworkingCallback callback) const {

}


void Networking::privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const {

}


void Networking::groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const {

}