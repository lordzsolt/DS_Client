#pragma once

#include <winsock2.h>
#include <string>


class SocketListener {


public:
    SocketListener() {
    }

    SocketListener(std::string serverAddress, unsigned short port);

private:
    SOCKET _socket;
};