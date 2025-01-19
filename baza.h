#pragma once
#include <vector>
#include <string>
using namespace std;

class Ksiazka {
public:
    string tytul;
    string autor;
    bool wypozyczona = false;
    string wypozyczajacy = "";
};

class Biblioteka {
private:
    vector<Ksiazka> ksiazki;

public:
    Biblioteka(const string& nazwaPliku);  // Konstruktor przyjmujący nazwę pliku

    void dodajKsiazke(const Ksiazka& nowaKsiazka);
    void wyswietlKsiazki() const;
    bool wypozyczKsiazke(const string& tytul, const string& login);
    bool zwracanieKsiazki(const string& tytul, const string& login);

    void wczytajKsiazkiZPliku(const string& nazwaPliku);  // Funkcja do wczytywania książek z pliku
};

