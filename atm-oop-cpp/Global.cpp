#include "Global.h"
#include "clsClientData.h"
#include "clsScreen.h"

void SystemBoot()
{
    // Load clients from file (if file doesn't exist, empty vector)
    clsClientData::loadClients();

    // If no clients exist, create a default client for testing
    if (clsClientData::getClients().empty())
    {
        // Create a default client: Account A1000, PIN 1234, Balance $1000
        clsClient defaultClient("John", "Doe", "1234567890", "john@example.com", 30,
            "A1000", "1234", 1000.0f);
        clsClientData::addClient(defaultClient);
        cout << "\n===========================================\n";
        cout << " No clients found. Default client created:\n";
        cout << " Account Number: A1000\n";
        cout << " PIN: 1234\n";
        cout << " Balance: $1000\n";
        cout << "===========================================\n\n";
        clsScreen::_pauseScreen();  // You'll need to include a pause function, or just wait
    }
}