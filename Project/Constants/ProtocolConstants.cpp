#include "ProtocolConstants.h"

std::string presharedKey = "fJMRP043kyC1PlL7Fp8WkV4OxHbspai";

int getMessageType(MessageType type) {
    static int types[] = {
            1 << 0,
            1 << 1,
            1 << 2,
            1 << 3,
            1 << 4
    };
    return types[static_cast<int>(type)];
}

int getMessageTag(MessageTag tag) {
    static int tags[] = {
            1 << 0,
            1 << 1,
            1 << 2,
            1 << 3
    };
    return tags[static_cast<int>(tag)];
}

std::string kMessageKeyUsername = "username";
std::string kMessageKeyPassword = "password";
std::string kMessageKeyRecipientId = "recipientId";
std::string kMessageKeyMessage = "message";