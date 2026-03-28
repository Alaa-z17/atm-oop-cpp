#include "Global.h"
#include "clsLoginScreen.h"
#include "clsATMMainScreen.h"

int main()
{
    SystemBoot();

    bool running = true;
    while (running)
    {
        // Show login screen
        clsLoginScreen loginScreen;
        loginScreen.show();

        // After login, show main screen
        clsATMMainScreen mainScreen;
        mainScreen.show();

        // Check if user chose to exit the program
        if (clsATMMainScreen::shouldExit())
        {
            running = false;
        }
    }

    return 0;
}