#pragma once

#include "clsScreen.h"
#include "clsClientData.h"

class clsLoginScreen : public clsScreen
{
private:
    static clsClient _LoggedInClient;

    static bool _login(const string& accountNumber, const string& pinCode)
    {
        if (clsClientData::authenticateClient(accountNumber, pinCode))
        {
            _LoggedInClient = clsClientData::getClientByAccountNumber(accountNumber);
            return true;
        }
        return false;
    }

public:
    void show() override
    {
        _showHeader("Login Screen");

        string accountNumber;
        string pinCode;
        bool loginSuccess = false;

        do {
            accountNumber = clsInputValidate<string>::ReadString("Enter Account Number: ");
            pinCode = clsInputValidate<string>::ReadString("Enter PIN Code: ");

            if (_login(accountNumber, pinCode))
            {
                loginSuccess = true;
                cout << "\n✅ Login successful! Welcome, " << _LoggedInClient.getFullName() << ".\n";
                _pauseScreen();
            }
            else
            {
                cout << "\n❌ Invalid account number or PIN. Try again.\n";
            }
        } while (!loginSuccess);
    }

    static const clsClient& getLoggedInClient()
    {
        return _LoggedInClient;
    }

    static void setLoggedInClient(const clsClient& client)
    {
        _LoggedInClient = client;
    }
};

// Static member definition (placed in a .cpp file, but we can add to Statics.cpp)
// We'll put in Statics.cpp later