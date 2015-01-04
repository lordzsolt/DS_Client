#include "../Message.h"

#include <string>

class MessageDeserializer {
public:
    static Message* deserializeMessage(std::string header, std::string body);
};