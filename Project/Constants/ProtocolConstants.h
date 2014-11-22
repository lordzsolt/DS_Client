#include <string>

extern std::string presharedKey;

enum class MessageTag : int {
    New,
    Acknowledge,
    Corrupt,
    Missing
};

int getTag(MessageTag tag);


enum class MessageType : int {
    Register,
    Log_In,
    Log_Out,
    Send_Message,
    Send_File
};

int getType(MessageType type);