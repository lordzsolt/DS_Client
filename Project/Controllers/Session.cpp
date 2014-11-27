#include "Session.h"

using namespace std;

Session::Session() {
    _networking = Networking();
};

bool Session::login(std::string username, std::string password, ErrorMessage &error) {
    return true;
}


bool Session::signup(std::string username, std::string password, std::string rePassword, ErrorMessage& error) {
    return true;
}


bool Session::sendMessage(std::string message, std::unordered_set<int> recipientIds) {
    return true;
}
