#include "Account.h"
#include "Utils.h"   
#include <iostream>
using namespace std;

ConsoleInterface ci;

// ------------------ Account ------------------

Account::Account(User &userRef) : numberAccount(0), user(userRef), pin(0), balance(0.0) {} 
Account::Account(int numberAccount , User &userRef, int pin, double balance) 
    : numberAccount(numberAccount), user(userRef), pin(pin), balance(balance) {} 

// Métodos
void Account::deposit(double amount){
    if (!user.getIsLogged()) { 
        ci.ErrorMessage("Usuário não está logado!");
        return;
    }
    setBalance(getBalance() + amount);
    ci.SuccessMessage("Depósito de " + formatCurrency(amount) + " realizado!");
}

bool Account::withdraw(double amount){
    if (!user.getIsLogged()) { 
        ci.ErrorMessage("Usuário não está logado!");
        return false;
    }
    if (amount > getBalance()) {
        ci.ErrorMessage("Fundos Insuficientes!");
        return false;
    }
    setBalance(getBalance() - amount);
    ci.SuccessMessage("Saque de " + formatCurrency(amount) + " realizado!");
    return true;
}

bool Account::transferBalance(Account &accDestination, double amount){
    if (!user.getIsLogged()) { 
        ci.ErrorMessage("Usuário não está logado!");
        return false;
    }
    if (amount > getBalance()){
        ci.ErrorMessage("Fundos Insuficientes!");
        return false;
    }
    
    setBalance(getBalance() - amount);
    accDestination.setBalance(accDestination.getBalance() + amount );
    ci.SuccessMessage("Transferência de " + formatCurrency(amount) + " realizada!");
}

void Account::currentBalance(){
    if (!user.getIsLogged()) { 
        ci.ErrorMessage("Usuário não está logado!");
        return;
    }
    cout << "Saldo da conta: " << formatCurrency(getBalance()) << endl;
}

// Getters
int Account::getNumberAccount(){ return numberAccount; }
User &Account::getUser() { return user; } 
int Account::getPin(){ return pin; }
double Account::getBalance(){ return balance; }

// Setters
void Account::setNumberAccount(int n) { numberAccount = n; }
void Account::setUser(User &u) { user = u; } 
void Account::setBalance(double b) { balance = b; }

// ------------------ Savings ------------------

Savings::Savings(User &userRef) : Account(userRef), feePercentage(0.02) {} 
Savings::Savings(int numberAccount, User &userRef, int pin, double balance, double fee)
    : Account(numberAccount, userRef, pin, balance), feePercentage(fee) {} 

bool Savings::withdraw(double amount){
    if (!getUser().getIsLogged()) { 
        ci.ErrorMessage("Usuário não está logado!");
        return false;
    }
    double value = amount + (amount * feePercentage);
    if (value > getBalance()) {
        ci.ErrorMessage("Fundos Insuficientes!");
        return false;
    }
    setBalance(getBalance() - value);
    ci.SuccessMessage("Saque de " + formatCurrency(value) + " realizado (incluindo taxa)!");
    return true;
}

void Savings::currentBalance(){
    if (!getUser().getIsLogged()) { 
        ci.ErrorMessage("Usuário não está logado!");
        return;
    }
    cout << "Conta Poupança: " << formatCurrency(getBalance()) << endl;
}

double Savings::getFeePercentage(){ return feePercentage; }
void Savings::setFeePercentage(double value){ feePercentage = value; }

// ------------------ Checking ------------------

Checking::Checking(User &userRef) : Account(userRef) {} 
Checking::Checking(int numberAccount, User &userRef, int pin, double balance)
    : Account(numberAccount, userRef, pin, balance) {} 

void Checking::currentBalance(){
    if (!getUser().getIsLogged()) { 
        ci.ErrorMessage("Usuário não está logado!");
        return;
    }
    cout << "Conta Corrente: " << formatCurrency(getBalance()) << endl;
}
