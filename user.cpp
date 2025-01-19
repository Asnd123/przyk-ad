#include "user.h"
#include <iostream>
#include <string>
#include<vector>
using namespace std;

User :: User(string Imie, string Nazwisko, string Login, string Haslo):
imie(Imie), nazwisko(Nazwisko), login(Login), haslo(Haslo){}

void User::setLogin(string Login) {
    login = Login;
}
void User::setHaslo(string Haslo) {
    haslo = Haslo;
}
void User::setNazwisko(string Nazwisko) {
    nazwisko = Nazwisko;
}
void User::setImie(string Imie) {
    imie = Imie;
}

bool User::sprawdzDane(string wpisanyLogin, string wpisaneHaslo) const {
    return wpisanyLogin == login && wpisaneHaslo == haslo;
}
void User::pokazDane() const {
    cout << "Imię: " << imie << endl;
    cout << "Nazwisko: " << nazwisko << endl;
    cout << "Login: " << login << endl;
}

void User::dodajDoHistorii(const string& tytul){
    historiaWypozyczen.push_back(tytul);
}

void User::pokazHistorie() const{
    if(historiaWypozyczen.empty()){
        cout<<"Brak wypożyczonych książek w historii." <<endl;
        return;
    }
    cout <<"Historia wypożyczeń: "<<endl;
    for(const auto& tytul : historiaWypozyczen){
        cout<<"- "<<tytul<<endl;
    }
}
