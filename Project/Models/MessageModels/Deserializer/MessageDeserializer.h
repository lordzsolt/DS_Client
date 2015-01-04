#include "../Message.h"

#include <string>
#include <memory>

class MessageDeserializer {
public:
    static std::shared_ptr<Message> deserializeMessage(std::string header, std::string body);
};