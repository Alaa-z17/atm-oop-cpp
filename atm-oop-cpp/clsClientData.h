#pragma once
#include "Global.h"
#include "clsClient.h"
#include <vector>
#include <fstream>

class clsClientData
{
private:
    static vector<clsClient> _Clients;
    static string _ClientsFile;

    static string _convertClientToLine(const clsClient& client)
    {
        string line = "";
        line += client.getAccountNumber() + "|";
        line += client.getPinCode() + "|";
        line += to_string(client.getBalance()) + "|";
        line += client.getFirstName() + "|";
        line += client.getLastName() + "|";
        line += client.getPhone() + "|";
        line += client.getEmail() + "|";
        line += to_string(client.getAge());
        return line;
    }

    static clsClient _convertLineToClient(const string& line)
    {
        vector<string> v = clsString::Split(line, "|");
        // v[0]=AccountNumber, v[1]=PinCode, v[2]=Balance,
        // v[3]=FirstName, v[4]=LastName, v[5]=Phone, v[6]=Email, v[7]=Age
        return clsClient(v[3], v[4], v[5], v[6], stoi(v[7]),
            v[0], v[1], stof(v[2]));
    }

public:
    static void loadClients()
    {
        _Clients.clear();
        fstream file;
        file.open(_ClientsFile, ios::in);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                _Clients.push_back(_convertLineToClient(line));
            }
            file.close();
        }
    }

    static void saveClients()
    {
        fstream file;
        file.open(_ClientsFile, ios::out);
        if (file.is_open())
        {
            for (const auto& client : _Clients)
            {
                file << _convertClientToLine(client) << endl;
            }
            file.close();
        }
    }

    static const vector<clsClient>& getClients() { return _Clients; }

    static int findClientIndex(const string& accountNumber)
    {
        for (int i = 0; i < _Clients.size(); i++)
        {
            if (_Clients[i].getAccountNumber() == accountNumber)
                return i;
        }
        return -1;
    }

    static clsClient getClientByAccountNumber(const string& accountNumber)
    {
        int index = findClientIndex(accountNumber);
        if (index != -1)
            return _Clients[index];
        return clsClient();
    }

    static bool addClient(const clsClient& client)
    {
        if (findClientIndex(client.getAccountNumber()) != -1)
            return false;
        _Clients.push_back(client);
        saveClients();
        return true;
    }

    static bool updateClient(const clsClient& client)
    {
        int index = findClientIndex(client.getAccountNumber());
        if (index == -1)
            return false;
        _Clients[index] = client;
        saveClients();
        return true;
    }

    static bool deleteClient(const string& accountNumber)
    {
        int index = findClientIndex(accountNumber);
        if (index == -1)
            return false;
        _Clients.erase(_Clients.begin() + index);
        saveClients();
        return true;
    }

    static bool authenticateClient(const string& accountNumber, const string& pinCode)
    {
        clsClient client = getClientByAccountNumber(accountNumber);
        if (client.getAccountNumber() == "")
            return false;
        return client.getPinCode() == pinCode;
    }
};
