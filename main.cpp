#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

struct Przyjaciel {
    int id;
    string imie, nazwisko, adres, telefon, mail;
};

int konwersjaStringNaInt(string liczbaJakoString) {
    int liczbaJakoInt;
    istringstream iss(liczbaJakoString);
    iss >> liczbaJakoInt;
    return liczbaJakoInt;
}

string konwersjaNaMaleLitery (string wyraz) {
    int dlugoscWyrazu = wyraz.length();

    for(int i = 0; i < dlugoscWyrazu ; i++) {
        char znakASCII=wyraz[i];

        if ((znakASCII>64)&&(znakASCII<91)) {
            znakASCII+=32;
            wyraz[i]=znakASCII;
        }
    }
    return wyraz;
}

int dodajPrzyjaciela(Przyjaciel przyjaciele[], int iloscPrzyjaciol) {
    string imie, nazwisko, adres, telefon, mail;

    cout << "Podaj imie: ";
    cin.sync();
    getline(cin,imie);
    cout << "Podaj nazwisko: ";
    cin.sync();
    getline(cin,nazwisko);
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin,telefon);
    cout << "Podaj adres e-mail: ";
    cin >> mail;
    cout << "Podaj adres zamieszkania: ";
    cin.sync();
    getline(cin,adres);

    int idNowegoPrzyjaciela=iloscPrzyjaciol+1;

    przyjaciele[iloscPrzyjaciol].id = idNowegoPrzyjaciela;
    przyjaciele[iloscPrzyjaciol].imie = imie;
    przyjaciele[iloscPrzyjaciol].nazwisko = nazwisko;
    przyjaciele[iloscPrzyjaciol].telefon = telefon;
    przyjaciele[iloscPrzyjaciol].mail = mail;
    przyjaciele[iloscPrzyjaciol].adres = adres;

    fstream plik;
    plik.open("ksiazka.txt",ios::out | ios::app);

    if(plik.good()) {
        plik<<idNowegoPrzyjaciela<<endl;
        plik<<imie<<endl;
        plik<<nazwisko<<endl;
        plik<<telefon<<endl;
        plik<<mail<<endl;
        plik<<adres<<endl;

        plik.close();

        cout << "Dane przyjaciela zapisano pomyslnie" << endl;
        Sleep(1000);
    } else {
        cout << "Nie mozna otworzyc pliku ksiazka.txt..." << endl;
        Sleep(1000);
    }
    iloscPrzyjaciol++;

    return iloscPrzyjaciol;
}

void wyswietlPrzyjaciol(Przyjaciel przyjaciele[], int iloscPrzyjaciol) {

    for(int i=0; i<iloscPrzyjaciol; i++) {
        cout << endl << "ID tego przyjaciela: " << przyjaciele[i].id<< endl;
        cout << endl << "Imie: " << przyjaciele[i].imie<< endl;
        cout << "Nazwisko: " << przyjaciele[i].nazwisko<< endl;
        cout << "Numer telefonu: " << przyjaciele[i].telefon<< endl;
        cout << "Adres e-mail: " << przyjaciele[i].mail<< endl;
        cout << "Adres zamieszkania: " << przyjaciele[i].adres<< endl << endl;
        cout << "-------------------------------------" << endl;
    }

    cout << endl << "Wcisnij dowolny przycisk!" << endl;
    getch();
}

void wyszukajPoImieniu(Przyjaciel przyjaciele[], int iloscPrzyjaciol) {
    string szukaneImie;
    cout << "Podaj imie przyjaciela: ";
    cin.sync();
    getline(cin,szukaneImie);

    int i = 0;

    while (i<iloscPrzyjaciol) {
        string imiePrzyjaciela = przyjaciele[i].imie;
        imiePrzyjaciela=konwersjaNaMaleLitery(imiePrzyjaciela);
        szukaneImie = konwersjaNaMaleLitery(szukaneImie);
        if (imiePrzyjaciela == szukaneImie) {
            cout << endl << "ID tego przyjaciela: " << przyjaciele[i].id<< endl;
            cout << endl << "Imie: " << przyjaciele[i].imie<< endl;
            cout << "Nazwisko: " << przyjaciele[i].nazwisko<< endl;
            cout << "Numer telefonu: " << przyjaciele[i].telefon<< endl;
            cout << "Adres e-mail: " << przyjaciele[i].mail<< endl;
            cout << "Adres zamieszkania: " << przyjaciele[i].adres<< endl << endl;
            cout << "-------------------------------------" << endl;
        }
        i++;
    }
    cout << "Wcisnij dowolny przycisk!" << endl;
    getch();

}

void wyszukajPoNazwisku(Przyjaciel przyjaciele[], int iloscPrzyjaciol) {
    string szukaneNazwisko;
    cout << "Podaj nazwisko przyjaciela: ";
    cin.sync();
    getline(cin,szukaneNazwisko);

    int i = 0;

    while (i<iloscPrzyjaciol) {
        string nazwiskoPrzyjaciela = przyjaciele[i].nazwisko;
        nazwiskoPrzyjaciela=konwersjaNaMaleLitery(nazwiskoPrzyjaciela);
        szukaneNazwisko = konwersjaNaMaleLitery(szukaneNazwisko);
        if (nazwiskoPrzyjaciela == szukaneNazwisko) {
            cout << endl << "ID tego przyjaciela: " << przyjaciele[i].id<< endl;
            cout << endl << "Imie: " << przyjaciele[i].imie<< endl;
            cout << "Nazwisko: " << przyjaciele[i].nazwisko<< endl;
            cout << "Numer telefonu: " << przyjaciele[i].telefon<< endl;
            cout << "Adres e-mail: " << przyjaciele[i].mail<< endl;
            cout << "Adres zamieszkania: " << przyjaciele[i].adres<< endl << endl;
            cout << "-------------------------------------" << endl;
        }
        i++;
    }
    cout << "Wcisnij dowolny przycisk!" << endl;
    getch();
}


int wczytajPrzyjaciolZPliku(Przyjaciel przyjaciele[], int iloscPrzyjaciol=0) {

    string linia;
    int numerLinii=iloscPrzyjaciol*6+1;
    int aktualnyNumer=1;

    fstream plik;
    plik.open("ksiazka.txt", ios::in);

    if(plik.good()==false) cout<<"Nie mozna otworzyc pliku!";

    while(getline(plik, linia)) {
        if(aktualnyNumer==numerLinii) przyjaciele[iloscPrzyjaciol].id=konwersjaStringNaInt(linia);
        if(aktualnyNumer==numerLinii+1) przyjaciele[iloscPrzyjaciol].imie=linia;
        if(aktualnyNumer==numerLinii+2) przyjaciele[iloscPrzyjaciol].nazwisko=linia;
        if(aktualnyNumer==numerLinii+3) przyjaciele[iloscPrzyjaciol].telefon=linia;
        if(aktualnyNumer==numerLinii+4) przyjaciele[iloscPrzyjaciol].mail=linia;
        if(aktualnyNumer==numerLinii+5) przyjaciele[iloscPrzyjaciol].adres=linia;
        if(aktualnyNumer%6==0) {
            iloscPrzyjaciol++;
            numerLinii=iloscPrzyjaciol*6+1;
        }
        aktualnyNumer++;
    }
    plik.close();
    return iloscPrzyjaciol;
}

int main() {
    Przyjaciel przyjaciele[1000];
    int iloscPrzyjaciol = 0;

    iloscPrzyjaciol = wczytajPrzyjaciolZPliku(przyjaciele,iloscPrzyjaciol);

    char wybor;

    while(true) {
        system("cls");
        cout << "-------------------------------------" << endl;
        cout << "Witaj w aplikacji Ksiazka Adresowa!" << endl;
        cout << "-------------------------------------" << endl<< endl;
        cout << "1. Dodaj nowego przyjaciela" << endl;
        cout << "2. Wyszukiwanie po imieniu" << endl;
        cout << "3. Wyszukiwanie po nazwisku" << endl;
        cout << "4. Wyswietl wszystkich przyjaciol" << endl;
        cout << "9. Zakoncz program" << endl;
        wybor=getch();
        cout << "Wybrales " << wybor << endl;
        Sleep(250);

        switch (wybor) {
        case '1':
            iloscPrzyjaciol = dodajPrzyjaciela(przyjaciele, iloscPrzyjaciol);
            break;
        case '2':
            if(iloscPrzyjaciol==0) {
                cout << "Ksiazka adresowa jest pusta, najpierw dodaj przyjaciela" << endl;
                Sleep(1500);
            } else wyszukajPoImieniu(przyjaciele, iloscPrzyjaciol);
            break;
        case '3':
            if(iloscPrzyjaciol==0) {
                cout << "Ksiazka adresowa jest pusta, najpierw dodaj przyjaciela" << endl;
                Sleep(1500);
            } else wyszukajPoNazwisku(przyjaciele, iloscPrzyjaciol);
            break;
        case '4':
            wyswietlPrzyjaciol(przyjaciele, iloscPrzyjaciol);
            break;
        case '9':
            cout << "Do zobaczenia!" << endl;
            exit(0);
            break;
        default:
            cout << "Wybierz poprawny numer z menu" << endl;
            Sleep(500);
        }
    }
    return 0;
}
