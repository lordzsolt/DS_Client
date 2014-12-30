#pragma once

#include <string>

extern std::string kServerAddress;
extern unsigned short kServerPort;

extern std::string presharedKey;


enum class MessageType : int {
    Register,
    Log_In,
    Log_Out,
    Status_Update,
    Private_Message,
    Group_Message,
    Send_File
};

int getMessageType(MessageType type);


enum class MessageTag : int {
    New,
    Acknowledge,
    Corrupt,
    Missing
};

int getMessageTag(MessageTag tag);


extern std::string kMessageKeyUsername;
extern std::string kMessageKeyPassword;
extern std::string kMessageKeyRecipientId;
extern std::string kMessageKeyMessage;


extern unsigned int kMaximumMessageLength;