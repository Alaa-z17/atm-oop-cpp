#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <ctime>

#include "Libraries/clsString.h"
#include "Libraries/clsDate.h"
#include "Libraries/clsInputValidate.h"

using namespace std;

// File path
const string CLIENTS_FILE = "Data/Clients.txt";

// System boot function
void SystemBoot();