#include "User.h"

#include <iostream>

using namespace std;

void User::sendMessage(std::string message) {

    cout << getName() << ": " << message;
}
