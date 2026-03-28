#include "Global.h"
#include "clsLoginScreen.h"
#include "clsATMMainScreen.h"   // to be created later

int main()
{
    SystemBoot();

    // Show login screen
    clsLoginScreen loginScreen;
    loginScreen.show();

    // After successful login, show ATM main screen
    clsATMMainScreen mainScreen;
    mainScreen.show();

    return 0;
}