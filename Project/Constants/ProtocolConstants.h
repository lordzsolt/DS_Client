#include <string>

extern std::string presharedKey;


enum class MessageType : int {
    Register,
    Log_In,
    Log_Out,
    Send_Message,
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
