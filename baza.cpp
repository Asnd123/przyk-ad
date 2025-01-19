#include "baza.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Biblioteka::Biblioteka(const string& nazwaPliku) {
    wczytajKsiazkiZPliku(nazwaPliku);  // Wczytanie książek z pliku przy tworzeniu obiektu
}

void Biblioteka::dodajKsiazke(const Ksiazka& nowaKsiazka) {
    ksiazki.push_back(nowaKsiazka);
    cout << "Dodano ksiazke: " << nowaKsiazka.tytul << " autora: " << nowaKsiazka.autor << "\n";
}

void Biblioteka::wyswietlKsiazki() const {
    bool Dostepne = false;
    cout << "Dostępne książki:\n";
    for (const Ksiazka& k : ksiazki) {
        if (!k.wypozyczona) {
            cout << "Tytuł: " << k.tytul << " Autor: " << k.autor << endl;
            Dostepne = true;
        }
    }
    if (!Dostepne) {
        cout << "Brak dostępnych książek.\n";
    }
}

bool Biblioteka::wypozyczKsiazke(const string& tytul, const string& login) {
    for (auto& k : ksiazki) {
        if (k.tytul == tytul) {
            if (k.wypozyczona) {
                cout << "Książka jest już wypożyczona przez: " << k.wypozyczajacy << endl;
                return false;
            }
            k.wypozyczona = true;
            k.wypozyczajacy = login;
            return true;
        }
    }
    cout << "Nie znaleziono książki o tytule: " << tytul << endl;
    return false;
}

bool Biblioteka::zwracanieKsiazki(const string& tytul, const string& login) {
    for (auto& k : ksiazki) {
        if (k.tytul == tytul) {
            if (!k.wypozyczona) {
                cout << "Ta książka nie jest wypożyczona." << endl;
                return false;
            }
            if (k.wypozyczajacy != login) {
                cout << "Nie możesz zwrócić książki, ponieważ jest wypożyczona przez innego użytkownika." << endl;
                return false;
            }
            k.wypozyczona = false;
            k.wypozyczajacy = "";
            return true;
        }
    }
    cout << "Nie znaleziono książki o tytule: " << tytul << endl;
    return false;
}

void Biblioteka::wczytajKsiazkiZPliku(const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku: " << nazwaPliku << endl;
        return;
    }

    string linia;
    while (getline(plik, linia)) {
        stringstream ss(linia);
        string tytul, autor;

        // Zakładamy, że tytuł i autor są rozdzieleni przecinkiem
        getline(ss, tytul, ',');
        getline(ss, autor);

        Ksiazka ksiazka;
        ksiazka.tytul = tytul;
        ksiazka.autor = autor;

        dodajKsiazke(ksiazka);  // Dodajemy książkę do biblioteki
    }

    plik.close();
}

