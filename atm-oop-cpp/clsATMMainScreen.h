#pragma once

#include "clsScreen.h"
#include "clsATMManager.h"
#include "clsQuickWithdrawScreen.h"
#include "clsNormalWithdrawScreen.h"
#include "clsDepositScreen.h"
#include "clsCheckBalanceScreen.h"

class clsATMMainScreen : public clsScreen
{
private:
    enum enMainMenuOptions
    {
        eQuickWithdraw = 1,
        eNormalWithdraw,
        eDeposit,
        eCheckBalance,
        eLogout,
        eExitProgram
    };

    static bool _shouldExit;   // static to track exit request

    enMainMenuOptions _showMainMenu()
    {
        _clearScreen();
        _showHeader("ATM Main Menu");
        cout << "  Welcome, " << clsATMManager::getCurrentClientFullName() << "\n";
        cout << "===========================================" << endl;
        cout << "  1. Quick Withdraw" << endl;
        cout << "  2. Normal Withdraw" << endl;
        cout << "  3. Deposit" << endl;
        cout << "  4. Check Balance" << endl;
        cout << "  5. Logout" << endl;
        cout << "  6. Exit Program" << endl;
        cout << "===========================================" << endl;
        cout << "Choose option (1-6): ";
        short choice = clsInputValidate<short>::ReadNumberBetween(1, 6);
        return static_cast<enMainMenuOptions>(choice);
    }

public:
    void show() override
    {
        _shouldExit = false;   // reset on each entry
        enMainMenuOptions choice;
        do {
            choice = _showMainMenu();
            switch (choice)
            {
            case eQuickWithdraw:
            {
                clsQuickWithdrawScreen quickScreen;
                quickScreen.show();
                break;
            }
            case eNormalWithdraw:
            {
                clsNormalWithdrawScreen normalScreen;
                normalScreen.show();
                break;
            }
            case eDeposit:
            {
                clsDepositScreen depositScreen;
                depositScreen.show();
                break;
            }
            case eCheckBalance:
            {
                clsCheckBalanceScreen balanceScreen;
                balanceScreen.show();
                break;
            }
            case eLogout:
                clsATMManager::logout();
                cout << "\n Logged out successfully. Returning to login screen...\n";
                _pauseScreen();
                return;   // exit this screen, go back to login
            case eExitProgram:
                clsATMManager::logout();
                cout << "\nThank you for using the ATM. Goodbye!\n";
                _pauseScreen();
                _shouldExit = true;
                return;
            }
        } while (true);
    }

    static bool shouldExit() { return _shouldExit; }
};

