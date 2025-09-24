#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <string>
using namespace std;

class AddressAndContact {
private:
    string zipCode;
    string number;
    string city;
    string state;
    string phoneNumber;
    string email;

public:
    // Construtores
    AddressAndContact();
    AddressAndContact(string zipCode, string number, string city, string state, string phoneNumber, string email);

    // Getters
    string getZipCode();
    string getNumber();
    string getCity();
    string getState();
    string getPhoneNumber();
    string getEmail();

    // Setters
    void setZipCode(string z);
    void setNumber(string n);
    void setCity(string c);
    void setState(string s);
    void setPhoneNumber(string p);
    void setEmail(string e);
};


class User {
private:
    int id;
    string name;
    AddressAndContact addressAndContact;
    string birthDate;
    bool isLogged = false; 

public:
    // Construtores
    User();
    User(int id, string name, AddressAndContact ac, string birthDate);

    // Getters
    int getId();
    string getName();
    AddressAndContact getAddresAndContact();
    string getBirthDate();
    bool getIsLogged();    

    // Setters
    void setId(int id);
    void setName(string name);
    void setAddressAndContact(AddressAndContact addressAndContact);
    void setBirthDate(string birthDate);
    void setIsLogged(bool auth); 
};

#endif