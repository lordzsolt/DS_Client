#include "SocketFactory.h"

SOCKET SocketFactory::createSocket(std::string address, unsigned short port) {
    SOCKET soc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (soc == INVALID_SOCKET) {
        //TODO: Add some exception
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(address.c_str());


    std::cerr << "Connection called" << "\n";

    int iResult = connect(soc, (SOCKADDR *)&addr, sizeof(addr));
    if (iResult == SOCKET_ERROR) {
        std::cerr << "Connection failed with error: " << WSAGetLastError() << "\n";
        //TODO: Add some exception
    }

    std::cerr << "Connection should've been accepted" << "\n";
    return soc;
}



SOCKET SocketFactory::createServerSocket(std::string address, unsigned short port)
{
    SOCKET soc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (soc == INVALID_SOCKET) {
        //TODO: Add some exception
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(address.c_str());

    int iResult = 0;
    iResult = bind(soc, (SOCKADDR *)&addr, sizeof(addr));
    if (iResult == SOCKET_ERROR) {
        //TODO: Add some exception
    }

    iResult = listen(soc, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        std::cout << "\r" << "Trying to establish connection...";
    }

    return soc;
}
