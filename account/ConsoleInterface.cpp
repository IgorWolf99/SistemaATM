#include "ConsoleInterface.h"

// Menus fixos
    void ConsoleInterface::MainMenu() {
        cout << "\n---------------------------------\n"
            << "| O que você gostaria de fazer? |\n"
            << "---------------------------------\n"
            << "| 1. Depósito                   |\n"
            << "| 2. Saque                      |\n"
            << "| 3. Verificar Saldo            |\n"
            << "| 4. Transferência              |\n"
            << "| 5. [Sair]                     |\n"
            << "---------------------------------\n" << endl;
    }

    void ConsoleInterface::AccountTypeMenu() {
        cout << "\n---------------------------------\n"
            << "| Qual o tipo de conta?         |\n"
            << "---------------------------------\n"
            << "| 1. Conta corrente             |\n"
            << "| 2. Poupança                   |\n"
            << "| 3. Voltar ao Menu             |\n"
            << "---------------------------------\n" << endl;
    }

    void ConsoleInterface::TransferTypeMenu() {
        cout << "\n-------------------------------------\n"
            << "| Selecione o tipo de transferência |\n"
            << "-------------------------------------\n"
            << "| 1. Conta Corrente para Poupança   |\n"
            << "| 2. Poupança para Conta Corrente   |\n"
            << "| 3. Voltar ao Menu                 |\n"
            << "-------------------------------------\n" << endl;
    }

    void ConsoleInterface::welcomeMessage() {
    cout << "\n---------------------------------\n"
         << "|        SEJA BEM-VINDO!        |\n"
         << "---------------------------------" << endl;
    }

// Mensagens Dinamicas
    void ConsoleInterface::ErrorMessage(const string &msg) {
        cout << "Erro: " << msg << endl;
    }

    void ConsoleInterface::SuccessMessage(const string &msg) {
        cout << "Sucesso: " << msg << endl;
    }

    void ConsoleInterface::RequestInput(const string &msg) {
        cout << msg;
    }