#include "clsPerson.h"
#include "clsClient.h"
#include "clsClientData.h"
#include "clsATMMainScreen.h"

// Define static members
int clsPerson::_TotalPersons = 0;
int clsClient::_TotalClients = 0;

// Data static members
vector<clsClient> clsClientData::_Clients;
string clsClientData::_ClientsFile = CLIENTS_FILE;

bool clsATMMainScreen::_shouldExit = false;