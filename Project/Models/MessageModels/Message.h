#include "../../Constants/ProtocolConstants.h"

#include <string>
#include <sstream>

class Message {
public:
    Message(MessageType const &type, int index, MessageTag const &tag);

    virtual std::string serialize(int length) = 0;

protected:
    MessageType type;
    int index;
    MessageTag tag;
};