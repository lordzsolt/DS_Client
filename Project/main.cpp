#include "Models/RecipientModels/User.h"

using namespace std;

int main() {
    string alma("Alma");
    User currentUser(1, alma);
    currentUser.sendMessage("alma");
    return 0;
}