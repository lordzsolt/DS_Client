#include <winsock.h>
#include <string>

class SocketFactory {
public:
    static SOCKET createSocket(std::string address, unsigned short port);
};