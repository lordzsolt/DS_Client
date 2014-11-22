#include "ProtocolConstants.h"

std::string presharedKey = "fJMRP043kyC1PlL7Fp8WkV4OxHbspai";


int getTag(MessageTag tag) {
    static int tags[] = {
            1 << 0,
            1 << 1,
            1 << 2,
            1 << 3
    };
    return tags[static_cast<int>(tag)];
}

int getType(MessageType type) {
    static int types[] = {
            1 << 0,
            1 << 1,
            1 << 2,
            1 << 3,
            1 << 4
    };
    return types[static_cast<int>(type)];
}