#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include "Session.h"
#include "NetworkingControllers/Networking.h"
#include "UIControllers/WindowController.h"

#include <memory>

class ApplicationController
{
private:
    Session _session;
    Networking _networking;
    WindowController _windowController;

    ApplicationController();
    ApplicationController(ApplicationController const&);
    void operator=(ApplicationController const&);

    void messageRecieved(std::shared_ptr<Message> message);

public:
    ~ApplicationController() = default;

    static ApplicationController& currentApplication();

    const WindowController& windowController() const;
    const Networking& networking() const;
    const Session& session() const;
};

#endif // APPLICATIONCONTROLLER_H
