#include "SocketListener.h"

class MessageReceiver {
public:
    MessageReceiver() {
    }

    MessageReceiver(std::string serverAddress, unsigned short port);

private:
    SocketListener _listener;

};