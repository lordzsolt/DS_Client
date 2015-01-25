#include "Networking.h"

#include <winsock.h>
#include <functional>

#include "../../Constants/ProtocolConstants.h"

Networking::Networking(NotificationCallback callback)
    : Networking(callback, initializeWSA()) {
}


Networking::Networking(NotificationCallback callback, nullptr_t t)
    : _messenger(kServerAddress, kServerPort, callback) {
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


void Networking::login(std::string username, std::string password, NetworkingCallback callback) const {
    MessengerCallback lamdaCallback = [callback] (std::shared_ptr<Message> message) {
        if (callback) {
            callback(true);
        }
    };
    _messenger.sendLogin(username, password, lamdaCallback);
}


void Networking::signup(std::string username, std::string password, NetworkingCallback callback) const {

}


void Networking::privateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const {

}


void Networking::groupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkingCallback callback) const {

}
