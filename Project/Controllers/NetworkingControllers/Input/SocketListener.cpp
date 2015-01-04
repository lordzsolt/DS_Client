#include "SocketListener.h"

#include <sstream>
#include <vector>

using namespace std;

SocketListener::SocketListener(SOCKET socket, SocketListenerCallback callback, unsigned int headerLength)
        : _socket(socket),
          _callback(callback),
          _headerLength(headerLength)
{
}


void SocketListener::stopListening() {
    printf("Listening stopped");
    _listen = false;
}


void SocketListener::startListening() {
    _listen = true;
    listen();
}


void SocketListener::listen () {

    if (!_listen) {
        return;
    }

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
            }
        }
        listen();
    }
}


void SocketListener::readSocket() {
    if (!_waitForOtherHalfOfMessage) {
        //This is a new message
        readNewMessageFromSocket();
    }
    else {
        //This is the other half of the previous message (stored in _body)
        appendCurrentMessageFromSocket();
    }
}


void SocketListener::readNewMessageFromSocket() {
    _header.resize(_headerLength);
    int iResult = recv(_socket, &_header[0], _headerLength, 0);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }
    _currentMessageExpectedLength = *reinterpret_cast<const int32_t*>(_header.data());

    _body.resize(_currentMessageExpectedLength);
    iResult = recv(_socket, &_body[0], _currentMessageExpectedLength, 0);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }
    else {
        if (iResult == _currentMessageExpectedLength) {
            wholeMessageArrived();
        }
        else {
            _waitForOtherHalfOfMessage = true;
        }
    }
}


void SocketListener::appendCurrentMessageFromSocket() {
    unsigned int leftoverLength = _currentMessageExpectedLength - _body.length();

    string leftover(leftoverLength, '0');

    int iResult = recv(_socket, &leftover[0], leftoverLength, 0);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }
    else {
        _body += leftover;
        if (_body.length() == _currentMessageExpectedLength) {
            wholeMessageArrived();
        }
        else {
            _waitForOtherHalfOfMessage = true;
        }
    }
}


void SocketListener::wholeMessageArrived() {
    _waitForOtherHalfOfMessage = false;
    _callback(_header, _body);
    _body.clear();
    _header.clear();
    _currentMessageExpectedLength = 0;
}
