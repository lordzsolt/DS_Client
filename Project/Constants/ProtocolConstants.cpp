#include "ProtocolConstants.h"

std::string kServerAddress = "127.0.0.1";
unsigned short kServerPort = 12345;

std::string presharedKey = "fJMRP043kyC1PlL7Fp8WkV4OxHbspai";

int getMessageType(MessageType type) {
    static int types[] = {
            1 << 0,
            1 << 1,
            1 << 2,
            1 << 3,
            1 << 4,
            1 << 5
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


unsigned int kMaximumMessageLength = 4096;

unsigned int kMaximumMessageIndex = 4096;