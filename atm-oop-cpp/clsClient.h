#pragma once

#include "clsPerson.h"

class clsClient : public clsPerson
{
private:
    string _AccountNumber;
    string _PinCode;
    float  _Balance;

    static int _TotalClients;

public:
    // Constructors
    clsClient() : clsPerson(), _AccountNumber(""), _PinCode(""), _Balance(0)
    {
        _TotalClients++;
    }

    clsClient(string firstName, string lastName, string phone, string email, short age,
        string accountNumber, string pinCode, float balance)
        : clsPerson(firstName, lastName, phone, email, age),
        _AccountNumber(accountNumber), _PinCode(pinCode), _Balance(balance)
    {
        _TotalClients++;
    }

    ~clsClient()
    {
        _TotalClients--;
    }

    // Getters & Setters
    void setAccountNumber(string accountNumber) { _AccountNumber = accountNumber; }
    string getAccountNumber() const { return _AccountNumber; }

    void setPinCode(string pinCode) { _PinCode = pinCode; }
    string getPinCode() const { return _PinCode; }

    void setBalance(float balance) { _Balance = balance; }
    float getBalance() const { return _Balance; }

    // Implement pure virtual from clsPerson
    string getID() const override
    {
        return _AccountNumber;   // account number acts as unique ID
    }

    // Override printInfo
    void printInfo() const override
    {
        clsPerson::printInfo();
        cout << "Account Number : " << _AccountNumber << endl;
        cout << "PIN Code       : " << _PinCode << endl;
        cout << "Balance        : $" << fixed << setprecision(2) << _Balance << endl;
    }

    // Static method to get total clients count
    static int getTotalClients() { return _TotalClients; }

#ifdef _MSC_VER
    // Microsoft-specific properties
    __declspec(property(get = getAccountNumber, put = setAccountNumber)) string AccountNumber;
    __declspec(property(get = getPinCode, put = setPinCode)) string PinCode;
    __declspec(property(get = getBalance, put = setBalance)) float Balance;
#endif
};