

static class SocketFactory {
public:
    static SOCKET createSocket(std::string address, unsigned short port) {
        SOCKET socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (socket == INVALID_SOCKET) {
            //TODO: Add some exception
            wprintf(L"socket failed with error: %ld\n", WSAGetLastError());
        }

        sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_port = htons(port);
        address.sin_addr.s_addr = inet_addr(serverAddress.c_str());

        int iResult = connect(socket, (SOCKADDR *)&address, sizeof(address));
        if (iResult == SOCKET_ERROR) {
            wprintf(L"Connect to server failed with error: %d\n", WSAGetLastError());
            //TODO: Add some exception
        }
        return socket;
    }
};