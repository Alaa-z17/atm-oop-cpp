#include "clsATMManager.h"
#include "clsClientData.h"

string clsATMManager::_CurrentAccountNumber = "";

bool clsATMManager::login(const string& accountNumber, const string& pinCode)
{
    if (clsClientData::authenticateClient(accountNumber, pinCode))
    {
        _CurrentAccountNumber = accountNumber;
        return true;
    }
    return false;
}

void clsATMManager::logout()
{
    _CurrentAccountNumber = "";
}

bool clsATMManager::withdraw(float amount)
{
    if (!isLoggedIn()) return false;
    clsClient client = clsClientData::getClientByAccountNumber(_CurrentAccountNumber);
    if (client.getBalance() < amount) return false;
    client.setBalance(client.getBalance() - amount);
    if (clsClientData::updateClient(client))
        return true;
    return false;
}

bool clsATMManager::deposit(float amount)
{
    if (!isLoggedIn()) return false;
    clsClient client = clsClientData::getClientByAccountNumber(_CurrentAccountNumber);
    client.setBalance(client.getBalance() + amount);
    if (clsClientData::updateClient(client))
        return true;
    return false;
}

float clsATMManager::getBalance()
{
    if (!isLoggedIn()) return -1;
    clsClient client = clsClientData::getClientByAccountNumber(_CurrentAccountNumber);
    return client.getBalance();
}

string clsATMManager::getCurrentClientFullName()
{
    if (!isLoggedIn()) return "";
    clsClient client = clsClientData::getClientByAccountNumber(_CurrentAccountNumber);
    return client.getFullName();
}

string clsATMManager::getCurrentClientAccountNumber()
{
    return _CurrentAccountNumber;
}