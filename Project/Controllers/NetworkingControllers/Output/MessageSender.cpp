#include "MessageSender.h"
#include "../../../Constants/ProtocolConstants.h"

MessageSender::MessageSender(std::string serverAddress, unsigned short port) {
    _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_socket == INVALID_SOCKET) {
        //TODO: Add some exception
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(serverAddress.c_str());

    int iResult = connect(_socket, (SOCKADDR *)&address, sizeof(address));
    if (iResult == SOCKET_ERROR) {
        wprintf(L"Connect to server failed with error: %d\n", WSAGetLastError());
        //TODO: Add some exception
    }
}


void MessageSender::sendMessage(std::string message) throw() {
    if (message.length() > kMaximumMessageLength) {
        throw "Message too long.";
    }

    int iResult = send(_socket, message.c_str(), static_cast<int>(message.length()), 0);
    if (iResult == SOCKET_ERROR)  {
        //TODO: Add exception
        wprintf(L"Message sending failed with error: %d\n", WSAGetLastError());
        //throw "Failed to send message";
    }
}