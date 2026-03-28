#pragma once

#include "clsScreen.h"

class clsATMMainScreen : public clsScreen
{
public:
    void show() override
    {
        _showHeader("ATM Main Menu");
        cout << "Main menu coming soon...\n";
        _pauseScreen();
    }
};