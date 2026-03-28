#pragma once

#include "clsClientData.h"
#include <string>

class clsATMManager
{
private:
    static string _CurrentAccountNumber;   // or store the whole client object

public:
    // Authentication
    static bool login(const string& accountNumber, const string& pinCode);

    // Logout
    static void logout();

    // Transactions
    static bool withdraw(float amount);
    static bool deposit(float amount);
    static float getBalance();
    static string getCurrentClientFullName();
    static string getCurrentClientAccountNumber();
    static bool isLoggedIn() { return !_CurrentAccountNumber.empty(); }
};