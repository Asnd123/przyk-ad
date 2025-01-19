#include <iostream>
#include "baza.h"
#include "user.h"

using namespace std;

int main()
{
    Biblioteka biblioteka;
    User admin("Michał", "Bibliotekarz", "admin", "admin123");
    User Michal("Michał", "Bagiński", "Michal1004", "$Nauka2025");
    User Jakub("Jakub", "Klyszczyński", "Asnd123", "Studia#2024");
    User Maks("Maks", "Szwejkowski", "eloMaks", "Wiedza2023!");
    User nowy("", "", "", "");
    string login, haslo, imie, nazwisko, tytul, autor;
    int zadanie;
    char akcja;

    cout << "Witaj w Bibliotece!" << endl;

    while (true) {
        cout << "Masz konto? Zaloguj się po kliknięciu Z" << endl;
        cout << "Nie masz konta? Zarejestruj się po kliknięciu R" << endl;
        cout << "Naciśnij Q, żeby zakończyć program" << endl;
        cin >> akcja;

        if (akcja == 'Q' || akcja == 'q') {
            cout << "Dziękujemy za wybranie naszej biblioteki.\nDo widzenia!" << endl;
            break;
        }

        if (akcja == 'Z' || akcja == 'z') {
            cout << "Login: ";
            cin >> login;
            cout << "Hasło: ";
            cin >> haslo;
            bool logowanie = admin.sprawdzDane(login, haslo) ||
                             Michal.sprawdzDane(login, haslo) ||
                             Jakub.sprawdzDane(login, haslo) ||
                             Maks.sprawdzDane(login, haslo) ||
                             nowy.sprawdzDane(login, haslo);

            if (logowanie) {
                cout << "Zalogowano pomyślnie!" << endl;
                if (login == "admin") {
                    do {
                        cout << "\n1. Wyświetl dostępne książki" << endl;
                        cout << "2. Dodaj książkę" << endl;
                        cout << "3. Historia wypożyczeń użytkowników" << endl;
                        cout << "4. Wyloguj" << endl;
                        cout << "Wybierz czynności: ";
                        cin >> zadanie;
                        cin.ignore();

                        if (zadanie == 1) {
                            biblioteka.wyswietlKsiazki();
                        } else if (zadanie == 2) {
                            Ksiazka nowaKsiazka;
                            cout << "Podaj autora: ";
                            getline(cin, autor);
                            cout << "Podaj tytuł: ";
                            getline(cin, tytul);
                            nowaKsiazka.autor = autor;
                            nowaKsiazka.tytul = tytul;
                            biblioteka.dodajKsiazke(nowaKsiazka);
                        } else if (zadanie == 3) {

                        } else if (zadanie == 4) {
                            cout << "Wylogowano pomyślnie" << endl;
                            break;
                        } else {
                            cout << "Nieobsługiwane żądanie. Spróbuj ponownie" << endl;
                        }
                    } while (true);
                }
                else {
                    do {
                        cout << "\n1. Wyświetl dostępne książki" << endl;
                        cout << "2. Wypożycz książkę" << endl;
                        cout << "3. Zwróć książkę" << endl;
                        cout << "4. Wyświetl historię wypożyczeń" << endl;
                        cout << "5. Wyloguj" << endl;
                        cout << "Wybierz czynność: ";
                        cin >> zadanie;
                        cin.ignore();

                        if (zadanie == 1) {
                            biblioteka.wyswietlKsiazki();
                        } else if (zadanie == 2) {
                            biblioteka.wyswietlKsiazki();
                            cout << "Podaj tytuł książki, którą chcesz wypożyczyć: ";
                            getline(cin, tytul);

                            if (biblioteka.wypozyczKsiazke(tytul, login)) {
                                cout << "Wypożyczono książkę: " << tytul << endl;
                                if (admin.sprawdzDane(login, haslo)) admin.dodajDoHistorii(tytul);
                                if (Michal.sprawdzDane(login, haslo)) Michal.dodajDoHistorii(tytul);
                                if (Jakub.sprawdzDane(login, haslo)) Jakub.dodajDoHistorii(tytul);
                                if (Maks.sprawdzDane(login, haslo)) Maks.dodajDoHistorii(tytul);
                                if (nowy.sprawdzDane(login, haslo)) nowy.dodajDoHistorii(tytul);
                            } else {
                                cout << "Nie udało się wypożyczyć książki. Sprawdź, czy jest dostępna." << endl;
                            }
                        } else if (zadanie == 3) {
                            cout << "Podaj tytuł książki, którą chcesz zwrócić: ";
                            getline(cin, tytul);

                            if (biblioteka.zwracanieKsiazki(tytul, login)) {
                                cout << "Zwrócono książkę: " << tytul << endl;
                            } else {
                                cout << "Nie udało się zwrócić książki. Sprawdź, czy była wypożyczona." << endl;
                            }
                        } else if (zadanie == 4) {
                            if (admin.sprawdzDane(login, haslo)) admin.pokazHistorie();
                            if (Michal.sprawdzDane(login, haslo)) Michal.pokazHistorie();
                            if (Jakub.sprawdzDane(login, haslo)) Jakub.pokazHistorie();
                            if (Maks.sprawdzDane(login, haslo)) Maks.pokazHistorie();
                            if (nowy.sprawdzDane(login, haslo)) nowy.pokazHistorie();
                        } else if (zadanie == 5) {
                            cout << "Wylogowano pomyślnie." << endl;
                            break;
                        } else {
                            cout << "Nieprawidłowe żądanie, spróbuj ponownie." << endl;
                        }
                    } while (true);
                }

            } else {
                cout << "Niepoprawny login lub hasło." << endl;
            }
        } else if (akcja == 'R' || akcja == 'r') {
            cout << "Imię: ";
            cin >> imie;
            nowy.setImie(imie);
            cout << "Nazwisko: ";
            cin >> nazwisko;
            nowy.setNazwisko(nazwisko);
            cout << "Nazwa użytkownika/login: ";
            cin >> login;
            nowy.setLogin(login);
            cout << "Podaj hasło do konta: ";
            cin >> haslo;
            nowy.setHaslo(haslo);
            cout << "Konto zostało utworzone!" << endl;
            nowy.pokazDane();
        } else {
            cout << "Nieprawidłowe żądanie, spróbuj ponownie." << endl;
        }
    }

    return 0;
}
