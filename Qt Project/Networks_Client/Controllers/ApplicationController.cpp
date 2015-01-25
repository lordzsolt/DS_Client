#include "ApplicationController.h"

#include "../Models/MessageModels/Message.h"

#include <iostream>

using namespace std::placeholders;

ApplicationController::ApplicationController()
    : _networking(bind(&ApplicationController::messageRecieved, this, _1))
{

}


ApplicationController& ApplicationController::currentApplication() {
    static ApplicationController instance;
    return instance;
}


const WindowController& ApplicationController::windowController() const
{
    return _windowController;
}

const Networking& ApplicationController::networking() const
{
    return _networking;
}


const Session& ApplicationController::session() const
{
    return _session;
}


void ApplicationController::messageRecieved(std::shared_ptr<Message> message)
{
    _windowController.updateWithMessage(message);
}
