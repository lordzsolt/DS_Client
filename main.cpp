#include <QCoreApplication>

#include "Controllers/ApplicationController.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ApplicationController& application = ApplicationController::currentApplication();

    ArithmeticsCallback callback = [](std::string serializedResult) {
        std::cerr << "No callback provided";
    };


    application.networking().functionMessage(FunctionType::Add,
                                             "alma",
                                             callback);

    return a.exec();
}
