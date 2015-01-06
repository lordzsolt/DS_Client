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

    int iResult = connect(soc, (SOCKADDR *)&addr, sizeof(addr));
    if (iResult == SOCKET_ERROR) {
        //TODO: Add some exception
    }
    std::cerr << soc;
    return soc;
}
