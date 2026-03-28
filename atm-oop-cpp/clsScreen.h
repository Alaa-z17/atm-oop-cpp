#pragma once

#include "Global.h"

class clsScreen
{
protected:
    // Common methods for all screens
    static void _clearScreen()
    {
        system("cls");  // For Windows
        // system("clear"); // For Linux/Mac
    }

    static void _pauseScreen()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    static void _showHeader(const string& title)
    {
        _clearScreen();
        cout << "\n===========================================" << endl;
        cout << "      " << title << endl;
        cout << "===========================================" << endl;
    }

    // Helper to read a single character (Y/N)
    static char _readConfirm(const string& message = "Are you sure? (y/n): ")
    {
        char confirm;
        cout << message;
        cin >> confirm;
        cin.ignore();
        return tolower(confirm);
    }

public:
    // Pure virtual function – each screen must implement show()
    virtual void show() = 0;
};