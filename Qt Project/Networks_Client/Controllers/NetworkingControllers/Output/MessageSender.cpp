#include "MessageSender.h"
#include "../../../Constants/ProtocolConstants.h"

MessageSender::MessageSender(SOCKET socket)
: _socket(socket)
{
}


void MessageSender::sendMessage(std::string message) const throw() {
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