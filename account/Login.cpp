#include "Login.h"
#include "crypto/sha256.h"
#include <iostream>
#include <fstream>

using namespace std;

Login::Login(User &user) : numberAccount(0), pin(0), user(user) {}

//  Metodo de autenticação 
bool Login::authenticate(int numberAccount, int pinAccount) {
    ifstream file("loginsSalvos.txt");
    if (!file.is_open()) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return false;
    }

    string accLbl, pinLbl, pin;
    int acc = 0;
    
    while (file >> accLbl >> pinLbl) {
        try {
            acc = stoi(accLbl.substr(accLbl.find(':') + 1));
            pin = pinLbl.substr(pinLbl.find(':') + 1);     // pega soo hash do arquivo
        } catch (const invalid_argument& e) {
            cerr << "Linha mal formatada no arquivo!" << endl;
            continue; // pula linha inválida
        }

        string hashPin = SimpleSHA256::sha256(to_string(pinAccount)); // Criar Hash da senha
        if (numberAccount == acc && hashPin == pin) {
            user.setIsLogged(true);
            cout << "Login realizado!" << endl;
            return true; }
    }

    return false;
}

//  loop de login 
bool Login::loginLoop() {
    bool sair = false;
    while (!sair) {
        int numAcc = inputInt("Digite o número da sua conta: ");
        int pinAcc = inputInt("Digite a senha da sua conta: ");

        if (authenticate(numAcc, pinAcc)) {
            return true; // login correto
        }
        cout << "Dados incorretos!" << endl;

        char resp;
        cout << "Tentar novamente? [S/N]: ";
        cin >> resp;
        resp = toupper(resp);

        if (resp == 'N') {
            cout << "Saindo do sistema..." << endl;
            exit(0); // encerra o programa
        } else if (resp != 'S') {
            cout << "Digite um valor válido (S ou N)." << endl;
        }
    }
    return false; // nunca chega aqui mas necessaario para compilação
}
