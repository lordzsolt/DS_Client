#include "Models/User.h"

using namespace std;

int main() {
    string alma("Alma");
    User currentUser(1, alma);
    currentUser.sendMessage("korte");
    return 0;
}