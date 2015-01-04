#include <sstream>
#include "SocketListener.h"

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
    //TODO: Update this to make it more C++ like.
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
    char* header = (char*)malloc(_headerLength * sizeof(char));

    int iResult = recv(_socket, header, _headerLength, 0);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }
    _header = string(header);
    _currentMessageExpectedLength = (int)header[0] + ((int)header[1] << 8) + ((int)header[2]<<16) + ((int)header[3]<<24);

    printf("Expected message length: %i", _currentMessageExpectedLength);

    char* message = (char*)malloc(_currentMessageExpectedLength * sizeof(char));
    iResult = recv(_socket, message, _currentMessageExpectedLength, 0);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }
    else {
        _body = string(message);
        if (_body.length() == _currentMessageExpectedLength) {
            wholeMessageArrived();
        }
        else {
            _waitForOtherHalfOfMessage = true;
        }
    }
}


void SocketListener::appendCurrentMessageFromSocket() {
    int leftoverLength = _currentMessageExpectedLength - _body.length();

    char* buffer = (char*)malloc(leftoverLength * sizeof(char));
    int iResult = recv(_socket, buffer, leftoverLength, 0);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    }
    else {
        _body.append(buffer);
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
    _callback(_body);
    _body.clear();
    _currentMessageExpectedLength = 0;
}
