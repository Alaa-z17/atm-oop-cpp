#pragma once

#include "clsScreen.h"
#include "clsATMManager.h"

class clsNormalWithdrawScreen : public clsScreen
{
private:
    static float _readWithdrawAmount()
    {
        float amount;
        cout << "Enter withdrawal amount: $";
        amount = clsInputValidate<float>::ReadNumber();
        return amount;
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

        _showHeader("Normal Withdraw");

        cout << "Current Balance: $" << fixed << setprecision(2) << clsATMManager::getBalance() << endl;
        float amount = _readWithdrawAmount();

        if (clsATMManager::withdraw(amount))
        {
            cout << "\n Withdrawal successful!\n";
            cout << "   Amount: $" << amount << endl;
            cout << "   New Balance: $" << fixed << setprecision(2) << clsATMManager::getBalance() << endl;
        }
        else
        {
            cout << "\n Insufficient balance or invalid amount.\n";
        }

        _pauseScreen();
    }
};