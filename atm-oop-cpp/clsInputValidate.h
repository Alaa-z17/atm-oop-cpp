#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <regex>

using namespace std;

template <class T>
class clsInputValidate
{
public:
    static T ReadNumber(string errorMessage = "Invalid Number, Enter again\n")
    {
        T number;
        while (!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMessage;
        }
        return number;
    }

    static T ReadNumberBetween(T from, T to, string errorMsg = "Number out of range. Enter again:\n")
    {
        T number = ReadNumber();
        while (number < from || number > to)
        {
            cout << errorMsg;
            number = ReadNumber();
        }
        return number;
    }

    static string ReadString(string message = "")
    {
        if (message != "")
            cout << message;
        string s;
        getline(cin >> ws, s);
        return s;
    }

    static bool IsNumberBetween(T number, T from, T to)
    {
        return (number >= from && number <= to);
    }

    static string ReadEmail()
    {
        string email;
        regex pattern(R"((\w+)(\.\w+)*@(\w+)(\.(\w+))+)");
        while (true)
        {
            email = ReadString();
            if (regex_match(email, pattern))
                break;
            else
                cout << "Invalid email. Try again: ";
        }
        return email;
    }

    static string ReadPhone()
    {
        string phone;
        regex pattern(R"((\+?\d{10,15}))");
        while (true)
        {
            phone = ReadString();
            if (regex_match(phone, pattern))
                break;
            else
                cout << "Invalid phone. Try again: ";
        }
        return phone;
    }
};
