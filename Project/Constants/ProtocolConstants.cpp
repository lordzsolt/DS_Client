#include "ProtocolConstants.h"

std::string kServerAddress = "127.0.0.1";
unsigned short kServerPort = 12345;

std::string presharedKey = "fJMRP043kyC1PlL7Fp8WkV4OxHbspai";

constexpr int32_t getMessageType(MessageType type) {
//    static int32_t types[] = {
//            1 << 0,
//            1 << 1,
//            1 << 2,
//            1 << 3,
//            1 << 4,
//            1 << 5
//    };
//    return types[static_cast<int32_t>(type)];

    return 1 << static_cast<int>(type);
}

constexpr int32_t getMessageTag(MessageTag tag) {
//    static int32_t tags[] = {
//            1 << 0,
//            1 << 1,
//            1 << 2,
//            1 << 3
//    };
//    return tags[static_cast<int>(tag)];

    return 1 << static_cast<int>(tag);
}


std::string kMessageDelimiter = "&";
std::string kMessageKeyUsername = "_username";
std::string kMessageKeyPassword = "_password";
std::string kMessageKeyRecipientId = "recipientId";
std::string kMessageKeyMessage = "message";


unsigned int kMaximumMessageLength = 4096;

unsigned int kMaximumMessageIndex = 4096;