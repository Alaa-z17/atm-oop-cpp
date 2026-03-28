#include "Global.h"
#include "clsClientData.h"

void SystemBoot()
{
    // Load clients from file
    clsClientData::loadClients();
}