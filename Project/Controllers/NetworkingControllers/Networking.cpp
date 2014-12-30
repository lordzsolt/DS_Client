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

    _sender = MessageSender(kServerAddress, kServerPort);
    _listener = SocketListener(kServerAddress, kServerPort);
}


void Networking::login(std::string username, std::string password, NetworkCallback callback) const {

}


void Networking::signup(std::string username, std::string password, NetworkCallback callback) const {

}


void Networking::sendPrivateMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const {

}


void Networking::sendGroupMessage(std::string message, std::unordered_set<int> recipientIds, NetworkCallback callback) const {

}