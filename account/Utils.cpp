#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

// Entrada de inteiro
int inputInt(const string& message) {
    int value;
    while (true) {
        cout << message;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer
            return value;
        } else {
            cout << "Valor inválido. Digite um número inteiro." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Entrada de double
double inputDouble(const string& message) {
    string input;
    double value;
    while (true) {
        cout << message;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Substitui vírgula por ponto
        for (char &c : input) {
            if (c == ',') c = '.';
        }

        try {
            value = stod(input);
            return value;
        } catch (...) {
            cout << "Valor inválido. Tente novamente usando apenas números e vírgula ou ponto." << endl;
        }
    }
}

// Formatação de moeda
string formatCurrency(double value) {
    stringstream ss;
    ss << fixed << setprecision(2) << value;
    string str = ss.str();

    // Troca ponto por vírgula (padrão BR)
    size_t pos = str.find('.');
    if (pos != string::npos) {
        str.replace(pos, 1, ",");
    }

    return "R$ " + str;
}