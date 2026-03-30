# 🏧 ATM System – C++ OOP Project

A complete ATM (Automated Teller Machine) simulation built in C++ that demonstrates advanced OOP concepts. The system allows clients to log in, withdraw money (quick or custom amounts), deposit funds, and check their balance. Data is persisted in a text file, and the architecture follows a clean separation of presentation, business, and data layers.

## 🎥 Video Tutorial
[![Student Management System C++ Tutorial](https://img.youtube.com/vi/5O0PEIFeCiI/0.jpg)](https://youtu.be/5O0PEIFeCiI)

## ✨ Features

- **Client Authentication** – Login with account number and PIN.
- **Quick Withdraw** – Predefined amounts ($20, $50, $100, $200, $400, $600, $800, $1000).
- **Normal Withdraw** – Withdraw any custom amount (subject to balance).
- **Deposit** – Add money to the account.
- **Check Balance** – View current balance and account details.
- **Data Persistence** – All client data is saved in `Clients.txt`.
- **Automatic Default Client** – On first run, a default client (A1000 / 1234) is created.
- **Logout & Exit** – Return to login screen or exit the program.

## 🧠 OOP Concepts Demonstrated

| Concept          | Implementation                                      |
|------------------|-----------------------------------------------------|
| Classes & Objects| Every entity is a class (Person, Client, Manager, Screens). |
| Encapsulation    | Private members with getters/setters in `clsClient`. |
| Inheritance      | `clsClient` inherits from `clsPerson`. |
| Polymorphism     | Virtual functions `printInfo()`, `getID()`; override in `clsClient`. |
| Abstraction      | `clsScreen` is an abstract base class for all screens. |
| Static Members   | Counters for total persons/clients; manager’s current account. |
| Properties       | `__declspec(property)` for MSVC (optional). |
| Friend Classes   | `clsScreen` is friend of `clsClientData` (to allow pause). |
| Separate Layers  | Presentation (screens), Business (`clsATMManager`), Data (`clsClientData`). |
| File I/O         | Reading/writing clients to text file. |
| Vectors          | Dynamic storage of clients in memory. |

## 📁 Project Structure

```text
atm-oop-cpp/
├── atm-oop-cpp.cpp # Entry point
├── Global.h / Global.cpp # Common includes and boot function
├── Statics.cpp # Static member definitions
├── Clients.txt # Data file (created at runtime)
├── Libraries/ # Utility libraries
│ ├── clsString.h # String utilities
│ ├── clsDate.h # Date validation
│ └── clsInputValidate.h # Input validation (template)
├── Business Layer
│ ├── clsPerson.h # Base class
│ ├── clsClient.h # Client entity
│ └── clsATMManager.h/.cpp # Business logic (login, withdraw, etc.)
├── Data Layer
│ └── clsClientData.h # File I/O for clients
└── Screens/ # Presentation layer
├── clsScreen.h # Base screen class
├── clsLoginScreen.h
├── clsATMMainScreen.h
├── clsQuickWithdrawScreen.h
├── clsNormalWithdrawScreen.h
├── clsDepositScreen.h
└── clsCheckBalanceScreen.h

```

## 🚀 Setup & Compilation

### Prerequisites

- C++ compiler (g++, MSVC, Clang)
- Windows (for `system("cls")`) – modify `clsScreen.h` for Linux/Mac.

### Build and Run

```bash
# Clone the repository
git clone https://github.com/your-username/atm-oop-cpp.git
cd atm-oop-cpp

# Compile
g++ -o atm-system *.cpp

# Run
./atm-system
On Windows, open the project in Visual Studio and build.

🔐 Default Login
If no Clients.txt exists, the system creates a default client:

Account Number: A1000

PIN: 1234

Balance: $1000

📄 License
This project is licensed under the MIT License – see the LICENSE file for details.
