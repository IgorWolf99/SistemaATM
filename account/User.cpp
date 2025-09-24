#include "User.h"

// ---------------- AddressAndContact ----------------
AddressAndContact::AddressAndContact() 
    : zipCode(""), number(""), city(""), state(""), phoneNumber(""), email("") {}

AddressAndContact::AddressAndContact(string zipCode, string number, string city, string state, string phoneNumber, string email) {
    this->zipCode = zipCode;
    this->number = number;
    this->city = city;
    this->state = state;
    this->phoneNumber = phoneNumber;
    this->email = email;
}

string AddressAndContact::getZipCode() { return zipCode; }
string AddressAndContact::getNumber() { return number; }
string AddressAndContact::getCity() { return city; }
string AddressAndContact::getState() { return state; }
string AddressAndContact::getPhoneNumber() { return phoneNumber; }
string AddressAndContact::getEmail() { return email; }

void AddressAndContact::setZipCode(string z) { zipCode = z; }
void AddressAndContact::setNumber(string n) { number = n; }
void AddressAndContact::setCity(string c) { city = c; }
void AddressAndContact::setState(string s) { state = s; }
void AddressAndContact::setPhoneNumber(string p) { phoneNumber = p; }
void AddressAndContact::setEmail(string e) { email = e; }


// ---------------- USER ----------------

User::User() : id(0), name(""), addressAndContact(), birthDate("") {}

User::User(int id, string name, AddressAndContact ac, string birthDate) {
    this->id = id;
    this->name = name;
    this->addressAndContact = ac;
    this->birthDate = birthDate;
}

int User::getId() { return id; }
string User::getName() { return name; }
AddressAndContact User::getAddresAndContact() { return addressAndContact; }
string User::getBirthDate() { return birthDate; }
bool User::getIsLogged() { return isLogged; }

void User::setIsLogged(bool auth) { isLogged = auth; }
void User::setId(int id) { this->id = id; }
void User::setName(string name) { this->name = name; }
void User::setAddressAndContact(AddressAndContact addressAndContact) { this->addressAndContact = addressAndContact; }
void User::setBirthDate(string birthDate) { this->birthDate = birthDate; }