#pragma once

#include "clsScreen.h"
#include "clsATMManager.h"

class clsLoginScreen : public clsScreen
{
public:
    void show() override
    {
        _showHeader("Login Screen");

        bool loginSuccess = false;
        do {
            string accountNumber = clsInputValidate<string>::ReadString("Enter Account Number: ");
            string pinCode = clsInputValidate<string>::ReadString("Enter PIN Code: ");

            if (clsATMManager::login(accountNumber, pinCode))
            {
                loginSuccess = true;
                cout << "\nLogin successful! Welcome, " << clsATMManager::getCurrentClientFullName() << ".\n";
                _pauseScreen();
            }
            else
            {
                cout << "\nInvalid account number or PIN. Try again.\n";
            }
        } while (!loginSuccess);
    }
};