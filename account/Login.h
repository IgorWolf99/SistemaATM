#ifndef  LOGINACCOUNT_H
#define LOGINACCOUNT_H

#include <string>
#include <fstream>
#include <iostream>
#include "Utils.h"
#include "User.h"

using namespace std;

class Login{
    private:
        int numberAccount;
        int pin;
        User &user;

    public:
        Login();
        Login(User &user);

    bool loginLoop();    
    bool authenticate(int numberAccount, int pin);
    

};

#endif