#pragma once

#include "clsScreen.h"
#include "clsATMManager.h"

class clsDepositScreen : public clsScreen
{
private:
    static float _readDepositAmount()
    {
        float amount;
        cout << "Enter deposit amount: $";
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

        _showHeader("Deposit");

        cout << "Current Balance: $" << fixed << setprecision(2) << clsATMManager::getBalance() << endl;
        float amount = _readDepositAmount();

        if (clsATMManager::deposit(amount))
        {
            cout << "\n Deposit successful!\n";
            cout << "   Amount: $" << amount << endl;
            cout << "   New Balance: $" << fixed << setprecision(2) << clsATMManager::getBalance() << endl;
        }
        else
        {
            cout << "\n Invalid deposit amount.\n";
        }

        _pauseScreen();
    }
};