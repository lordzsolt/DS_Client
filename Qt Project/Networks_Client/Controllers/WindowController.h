#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "../../Models/MessageModels/Message.h"

#include <memory>

class WindowController
{
public:
    WindowController();
    ~WindowController();

    void updateWithMessage(std::shared_ptr<Message> message);


};

#endif // WINDOWCONTROLLER_H
