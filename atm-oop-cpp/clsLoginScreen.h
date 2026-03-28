#pragma once

#include "clsScreen.h"
#include "../clsClientData.h"

class clsLoginScreen : public clsScreen
{
private:
    static clsClient _currentClient;  // stores the authenticated client

    static string _readAccountNumber()
    {
        return clsInputValidate<string>::ReadString("Enter Account Number: ");
    }

    static string _readPinCode()
    {
        return clsInputValidate<string>::ReadString("Enter PIN Code: ");
    }

public:
    static clsClient getCurrentClient()
    {
        return _currentClient;
    }

    void show() override
    {
        _showHeader("ATM Login System");

        string accountNumber = _readAccountNumber();
        string pinCode = _readPinCode();

        if (clsClientData::authenticateClient(accountNumber, pinCode))
        {
            _currentClient = clsClientData::getClientByAccountNumber(accountNumber);
            cout << "\nLogin successful. Welcome " << _currentClient.getFullName() << "!\n";
            _pauseScreen();

            // Proceed to main screen
            // We'll create and show the main screen here
            // For now, we'll just return and let main handle it
        }
        else
        {
            cout << "\nInvalid account number or PIN. Please try again.\n";
            _pauseScreen();
            show();  // recursive call to try again (but could lead to infinite loop; better with loop)
        }
    }
};

// Define the static member
clsClient clsLoginScreen::_currentClient;