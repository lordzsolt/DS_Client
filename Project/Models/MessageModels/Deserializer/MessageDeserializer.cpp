#include "MessageDeserializer.h"

#include "../../../Constants/ProtocolConstants.h"
#include "../Messages/LoginMessage.h"


Message* MessageDeserializer::deserializeMessage(std::string header, std::string body) {
    auto headerIntPtr = reinterpret_cast<const int32_t*>(header.data());

    int32_t index = headerIntPtr[1];
    int32_t type = headerIntPtr[2];
    int32_t tag = headerIntPtr[3];

    Message *result = nullptr;

    if (type == getMessageType(MessageType::Log_In)) {
        LoginMessage message(index, (MessageTag) tag, body);
        return &message;
    }

    switch (type) {
        case getMessageType(MessageType::Log_In): {
//            result = LoginMessage(index, (MessageTag) tag, body);
        }
        case getMessageType(MessageType::Register): {

        }
        case getMessageType(MessageType::Private_Message): {

        }
        case getMessageType(MessageType::Group_Message): {

        }
        default: {
            //TODO: Throw an exception
        }
    }

    return result;
}