#pragma once

#include "clsScreen.h"
#include "clsATMManager.h"

class clsCheckBalanceScreen : public clsScreen
{
public:
    void show() override
    {
        if (!clsATMManager::isLoggedIn())
        {
            cout << "\n No client logged in.\n";
            _pauseScreen();
            return;
        }

        _showHeader("Check Balance");

        cout << "\nAccount Number: " << clsATMManager::getCurrentClientAccountNumber() << endl;
        cout << "Account Holder: " << clsATMManager::getCurrentClientFullName() << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << clsATMManager::getBalance() << endl;

        _pauseScreen();
    }
};