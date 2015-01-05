#-------------------------------------------------
#
# Project created by QtCreator 2015-01-05T00:34:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Networks_Client
TEMPLATE = app

PRECOMPILED_HEADER = _pch.h

LIBS += -lws2_32

SOURCES += main.cpp\
    mainwindow.cpp \
    Constants/ProtocolConstants.cpp \
    Controllers/NetworkingControllers/Input/MessageReceiver.cpp \
    Controllers/NetworkingControllers/Input/SocketListener.cpp \
    Controllers/NetworkingControllers/Output/MessageSender.cpp \
    Controllers/NetworkingControllers/Messenger.cpp \
    Controllers/NetworkingControllers/Networking.cpp \
    Controllers/ThreadControllers/SynchronizedQueue.cpp \
    Controllers/Session.cpp \
    Factories/SocketFactory.cpp \
    Models/MessageModels/Deserializer/MessageDeserializer.cpp \
    Models/MessageModels/Messages/GroupMessage.cpp \
    Models/MessageModels/Messages/LoginMessage.cpp \
    Models/MessageModels/Messages/PrivateMessage.cpp \
    Models/MessageModels/Messages/RegisterMessage.cpp \
    Models/MessageModels/Message.cpp \
    Models/RecipientModels/Group.cpp \
    Models/RecipientModels/User.cpp \
    Models/ErrorMessage.cpp

HEADERS  += mainwindow.h \
    Constants/ProtocolConstants.h \
    Controllers/NetworkingControllers/Input/MessageReceiver.h \
    Controllers/NetworkingControllers/Input/SocketListener.h \
    Controllers/NetworkingControllers/Output/MessageSender.h \
    Controllers/NetworkingControllers/Messenger.h \
    Controllers/NetworkingControllers/Networking.h \
    Controllers/ThreadControllers/SynchronizedQueue.h \
    Controllers/Session.h \
    Factories/SocketFactory.h \
    Models/MessageModels/Deserializer/MessageDeserializer.h \
    Models/MessageModels/Messages/GroupMessage.h \
    Models/MessageModels/Messages/LoginMessage.h \
    Models/MessageModels/Messages/PrivateMessage.h \
    Models/MessageModels/Messages/RegisterMessage.h \
    Models/MessageModels/Message.h \
    Models/RecipientModels/Group.h \
    Models/RecipientModels/Recipient.h \
    Models/RecipientModels/User.h \
    Models/ErrorMessage.h

FORMS    += mainwindow.ui
