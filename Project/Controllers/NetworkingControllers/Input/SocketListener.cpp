#include "SocketListener.h"

SocketListener::SocketListener(std::string serverAddress, unsigned short port) {
    _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (_socket == INVALID_SOCKET) {
        //TODO: Add exception
        wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
    }

    sockaddr_in recvAddr;
    recvAddr.sin_family = AF_INET;
    recvAddr.sin_port = htons(port);
    recvAddr.sin_addr.s_addr = inet_addr(serverAddress.c_str());

    int iResult = connect(_socket, (SOCKADDR *)&recvAddr, sizeof (recvAddr));
    if (iResult == SOCKET_ERROR) {
        //TODO: Add exception
        wprintf(L"connects to server failed with error: %d\n",WSAGetLastError());
    }

    startListening();
}


void SocketListener::startListening() {
    u_long nonblockingMode = 1;

    ioctlsocket(_socket, FIONBIO, &nonblockingMode);

    fd_set readfds;
    struct timeval timeValues;

    //clear the set
    FD_ZERO(&readfds);
    // add our descriptors to the set
    FD_SET(_socket, &readfds);

    timeValues.tv_sec = 10;
    timeValues.tv_usec = 500000;
    int iResult = select(0, &readfds, NULL, NULL, &timeValues);

    if (iResult == SOCKET_ERROR) {
        wprintf(L"Select failed with error: %d\n",WSAGetLastError());
    }
    else {
        if (iResult == 0) {
            printf("Timeout occurred!  No data after 10.5 seconds.\n");
        }
        else {
            if (FD_ISSET(_socket, &readfds)) {
                readSocket();
                printf("Data was received\n");
            }
        }
        startListening();
    }
}


void SocketListener::readSocket() {
    wprintf(L"Something actually happened: %d\n",WSAGetLastError());
}
