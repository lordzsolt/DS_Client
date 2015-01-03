#pragma once

#include <winsock2.h>
#include <string>


class SocketListener {

public:
    SocketListener(std::string serverAddress, unsigned short port);

    void startListening();

private:
    SOCKET _socket;
    void readSocket();
};