#pragma once
#include <string>
#include <vector>
using namespace std;

class User {
private:
    string imie;
    string nazwisko;
    string haslo;
    string login;
    vector<string> historiaWypozyczen;

public:
    User(string Imie, string Nazwisko, string Login, string Haslo);
    void setHaslo(string Haslo);
    void setLogin(string Login);
    void setNazwisko(string Nazwisko);
    void setImie(string Imie);
    bool sprawdzDane(string wpisanyLogin, string wpisaneHaslo) const;
    void pokazDane() const;
    void dodajDoHistorii(const string& tytul);
    void pokazHistorie() const;
};
