#include "../Message.h"

#include <string>

class MessageDeserializer {
public:
    Message& deserializeMessage(std::string header, std::string body);
};