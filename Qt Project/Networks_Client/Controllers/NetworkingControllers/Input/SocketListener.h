#pragma once

#include <winsock2.h>
#include <string>
#include <functional>
//#include <atomic>

using SocketListenerCallback = std::function<void(std::string header, std::string message)>;

class SocketListener {

public:
    SocketListener(SOCKET socket, SocketListenerCallback callback, unsigned int headerLength);

    void startListening();
    void stopListening();

private:
    SOCKET _socket;
    SocketListenerCallback _callback;
    unsigned int _headerLength;
    bool _listen = false; //Should be atomic...
    bool _waitForOtherHalfOfMessage;

    std::string _header;
    std::string _body;
    int32_t _currentMessageExpectedLength;

    void listen();
    void readSocket();
    void readNewMessageFromSocket();
    void appendCurrentMessageFromSocket();
    void wholeMessageArrived();
};
