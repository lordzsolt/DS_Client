#pragma once

#include "SocketListener.h"

#include <vector>

class Networking {
private:
    std::vector<SocketListener> _listeners;

};