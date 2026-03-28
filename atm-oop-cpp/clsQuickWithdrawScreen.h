#pragma once

#include "clsScreen.h"
#include "clsATMManager.h"
#include "clsClientData.h"

class clsQuickWithdrawScreen : public clsScreen
{
private:
    enum enQuickWithdrawAmounts
    {
        eAmount20 = 20,
        eAmount50 = 50,
        eAmount100 = 100,
        eAmount200 = 200,
        eAmount400 = 400,
        eAmount600 = 600,
        eAmount800 = 800,
        eAmount1000 = 1000,
        eExit = 0
    };

    static enQuickWithdrawAmounts _showMenu()
    {
        _clearScreen();
        _showHeader("Quick Withdraw");

        cout << "===========================================" << endl;
        cout << "  Available Withdrawal Amounts:" << endl;
        cout << "===========================================" << endl;
        cout << "  1. $20" << endl;
        cout << "  2. $50" << endl;
        cout << "  3. $100" << endl;
        cout << "  4. $200" << endl;
        cout << "  5. $400" << endl;
        cout << "  6. $600" << endl;
        cout << "  7. $800" << endl;
        cout << "  8. $1000" << endl;
        cout << "  9. Exit" << endl;
        cout << "===========================================" << endl;
        cout << "Choose an option (1-9): ";

        short choice = clsInputValidate<short>::ReadNumberBetween(1, 9);

        switch (choice)
        {
        case 1: return eAmount20;
        case 2: return eAmount50;
        case 3: return eAmount100;
        case 4: return eAmount200;
        case 5: return eAmount400;
        case 6: return eAmount600;
        case 7: return eAmount800;
        case 8: return eAmount1000;
        default: return eExit;
        }
    }

public:
    void show() override
    {
        if (!clsATMManager::isLoggedIn())
        {
            cout << "\n❌ No client logged in.\n";
            _pauseScreen();
            return;
        }

        enQuickWithdrawAmounts choice;
        do {
            choice = _showMenu();
            if (choice != eExit)
            {
                float amount = static_cast<float>(choice);
                if (clsATMManager::withdraw(amount))
                {
                    cout << "\n Withdrawal successful!\n";
                    cout << "   Amount: $" << amount << endl;
                    cout << "   New Balance: $" << fixed << setprecision(2) << clsATMManager::getBalance() << endl;
                }
                else
                {
                    cout << "\n Insufficient balance or transaction error.\n";
                }
                _pauseScreen();
            }
        } while (choice != eExit);
    }
};