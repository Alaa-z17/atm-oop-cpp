#pragma once

#include "clsScreen.h"
#include "clsQuickWithdrawScreen.h"

class clsATMMainScreen : public clsScreen
{
private:
    clsClient _client;

    enum enMainMenuOptions
    {
        eQuickWithdraw = 1,
        eNormalWithdraw,
        eDeposit,
        eCheckBalance,
        eLogout
    };

    enMainMenuOptions _showMainMenu()
    {
        _clearScreen();
        _showHeader("ATM Main Menu");
        cout << "  1. Quick Withdraw" << endl;
        cout << "  2. Normal Withdraw" << endl;
        cout << "  3. Deposit" << endl;
        cout << "  4. Check Balance" << endl;
        cout << "  5. Logout" << endl;
        cout << "===========================================" << endl;
        cout << "Choose option (1-5): ";
        short choice = clsInputValidate<short>::ReadNumberBetween(1, 5);
        return static_cast<enMainMenuOptions>(choice);
    }

public:
    clsATMMainScreen(clsClient& client) : _client(client) {}

    void show() override
    {
        enMainMenuOptions choice;
        do {
            choice = _showMainMenu();
            switch (choice)
            {
            case eQuickWithdraw:
            {
                clsQuickWithdrawScreen quickScreen(_client);
                quickScreen.show();
                // After quick withdraw, refresh client data (balance might have changed)
                _client = clsClientData::getClientByAccountNumber(_client.getAccountNumber());
                break;
            }
            case eNormalWithdraw:
                // Placeholder
                cout << "\nNormal Withdraw - Coming soon.\n";
                _pauseScreen();
                break;
            case eDeposit:
                // Placeholder
                cout << "\nDeposit - Coming soon.\n";
                _pauseScreen();
                break;
            case eCheckBalance:
                // Placeholder
                cout << "\nYour balance is: $" << fixed << setprecision(2) << _client.getBalance() << endl;
                _pauseScreen();
                break;
            case eLogout:
                cout << "\nLogging out...\n";
                break;
            }
        } while (choice != eLogout);
    }
};