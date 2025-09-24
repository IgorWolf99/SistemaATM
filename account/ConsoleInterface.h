#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H


#include <iostream>
#include <string>

using namespace std;

class ConsoleInterface {
    public:
    // MENUS FIXOS
        void MainMenu();
        void AccountTypeMenu();
        void TransferTypeMenu();
        void welcomeMessage();

    // Mensagens dinamicas
        void ErrorMessage(const string &msg);
        void SuccessMessage(const string &msg);
        void RequestInput(const string &msg);

};

#endif
