#include "ConsoleInterface.h"
#include "Account.h"
#include "Login.h"
#include "User.h"
#include "Utils.h"
#include <windows.h>

#include <iostream>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);  // Força saída em UTF-8 no Windows para que acentos sejam exibidos corretamente

    ConsoleInterface ci;
    
    // Valores pré-definidos para a utilização do sistema----
    AddressAndContact contato("01001-000", "123", "São Paulo", "SP", "+55 11 91234-5678", "joao.silva@example.com");
    User user1(1, "João Silva", contato, "12/09/1999");
    Savings accSavigns(5435, user1, 213, 2000.0);
    Checking accChecking(5435, user1, 213, 100.0);
    // ------------------------------------------------------


    Login login(user1);
    login.loginLoop();
    ci.welcomeMessage();


    bool sair = false;
    while (!sair) {
        ci.MainMenu();
        int opc = inputInt("Digite um número: ");

        switch (opc) {
            case 1: {  // DEPÓSITO
                ci.AccountTypeMenu();
                int opc1 = inputInt("Tipo de conta: ");

                if (opc1 == 1) {
                    double amount = inputDouble("Digite o valor que deseja Depositar: R$ ");
                    accChecking.deposit(amount);
                    break;
                }
                if (opc1 == 2) {
                    double amount = inputDouble("Digite o valor que deseja Depositar: R$ ");
                    accSavigns.deposit(amount);
                    break;
                }
                if (opc1 == 3) {
                    cout << "Voltando ao menu principal...\n";
                    break;
                }

                cout << "Opção inválida!\nPor favor, digite uma opção válida.";
                break;
            }

            case 2: {  // SAQUE
                ci.AccountTypeMenu();
                int opc2 = inputInt("Tipo de conta: ");

                if (opc2 == 1) {
                    double amount2 = inputDouble("Digite o valor que deseja Sacar: R$ ");
                    accChecking.withdraw(amount2);
                    break;
                }

                if (opc2 == 2) {
                    double amount2 = inputDouble("Digite o valor que deseja Sacar: R$ ");
                    accSavigns.withdraw(amount2);
                    break;
                }

                if (opc2 == 3) {
                    cout << "Voltando ao menu principal...\n";
                    break;
                }

                cout << "Opção inválida!\n";
                break;
            }

            case 3:  // SALDO
                accChecking.currentBalance();
                accSavigns.currentBalance();
                break;

            case 4: {  // TRANSFERÊNCIA
                ci.TransferTypeMenu();
                int opc4 = inputInt("Digite a opção desejada: ");

                if (opc4 == 1) {
                    double amount4 = inputDouble("Digite o valor que deseja transferir: R$ ");
                    accChecking.transferBalance(accSavigns, amount4);
                    break;
                }
                if (opc4 == 2) {
                    double amount4 = inputDouble("Digite o valor que deseja transferir: R$ ");
                    accSavigns.transferBalance(accChecking, amount4);
                    break;
                }
                if (opc4 == 3) {
                    cout << "Voltando ao menu principal...\n";
                    break;
                }

                cout << "Opção inválida!\n";
                break;
            }

            case 5:
                sair = true;
                break;

            default:
                cout << "Opção inválida!\nPor favor, digite uma opção válida.";
                break;
        }
    }

    cout << "Obrigado, volte sempre!" << endl;
    return 0;
}
