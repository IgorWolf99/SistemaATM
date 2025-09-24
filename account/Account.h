#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "User.h"
#include "ConsoleInterface.h"

class Account {
private:
    int numberAccount;
    User &user;          
    int pin;
    double balance;

public: 
    // Construtores
    Account(User &userRef); 
    Account(int numberAccount, User &userRef, int pin, double balance); 

    // Métodos
    void deposit(double amount);    
    virtual bool withdraw(double amount);       
    virtual void currentBalance();             
    bool transferBalance(Account &accDestination, double amount);

    // Getters
    int getNumberAccount();
    User &getUser();        
    int getPin();
    double getBalance();

    // Setters
    void setNumberAccount(int n);
    void setUser(User &u);  
    void setBalance(double b);
};

// ------------------ Savings ------------------
class Savings : public Account {
private:
    double feePercentage;

public:
    Savings(User &userRef); 
    Savings(int numberAccount, User &userRef, int pin, double balance, double fee = 0.02); 

    bool withdraw(double amount) override;
    void currentBalance() override;   

    double getFeePercentage();
    void setFeePercentage(double valor);    
};

// ------------------ Checking ------------------
class Checking : public Account {
public:
    Checking(User &userRef); 
    Checking(int numberAccount, User &userRef, int pin, double balance); 

    void currentBalance() override;   
};

#endif
