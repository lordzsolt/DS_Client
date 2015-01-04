#include "MessageDeserializer.h"

#include "../../../Constants/ProtocolConstants.h"
#include "../Messages/LoginMessage.h"


using namespace std;

shared_ptr<Message> MessageDeserializer::deserializeMessage(std::string header, std::string body) {
    auto headerIntPtr = reinterpret_cast<const int32_t*>(header.data());

    int32_t index = headerIntPtr[1];
    int32_t type = headerIntPtr[2];
    int32_t tag = headerIntPtr[3];

    MessageType messageType = static_cast<MessageType>(type);
    switch (messageType) {
        case MessageType::Log_In: {
            LoginMessage loginMessage(index, static_cast<MessageTag>(tag), body);
            return make_shared<LoginMessage>(loginMessage);
        }
        case MessageType::Register: {

        }
        case MessageType::Private_Message: {

        }
        case MessageType::Group_Message: {

        }
        default: {
            //TODO: Throw an exception
        }
    }
}