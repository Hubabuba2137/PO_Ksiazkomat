#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

std::string trim(const std::string& str);

class Bibliotekarz;
class Ksiazka;
class BazaKsiazek;
//class DaneOsobowe;
class Czytelnik;
class BazaUzytkownikow;
class Skrytka;
class BazaSkrytek;
class Wypozyczenie;
class BazaWypozyczen;



class Ksiazka {
    friend class BazaKsiazek;
    friend ostream& operator<<(ostream& os, const Ksiazka& ksiazka);
	int id;

public:
	string tytul;
	string autor;
	string okladka;
	int ISBN;
    Ksiazka();
    Ksiazka(string t, string au, int isbn, string okl);
};

class BazaKsiazek {
	vector<Ksiazka> lista_ksiazek;
	string nazwa_pliku = "baza_ksiazek.txt";

	void loadFromFile(); 
	void saveToFile(); 
public:
	BazaKsiazek();
	void setBooks();
	const vector<Ksiazka>& getBooks() const;
	void add(string t, string au, int isbn, string okl);
	void usun_ksiazke(int isbn);
	bool wyszukaj_czy_jest(int isbn) const;
	bool wyszukaj_czy_jest(string tyt) const;
	Ksiazka wyszukaj(int isbn) const;
	Ksiazka wyszukaj(const std::string& tyt) const;
};

class DaneOsobowe {
	friend class Czytelnik;
	friend class BazaUzytkownikow;

public:
	string imie;
	string nazwisko;
	string email;
	string adres;
	int numer_tel;


	DaneOsobowe();
	DaneOsobowe(string i, string n, string e, string a, int tel);
};

class Czytelnik {
	friend class BazaUzytkownikow;
	friend class BazaWypozyczen;
	friend ostream& operator<<(ostream& os, const Czytelnik& czytelnik);

	int id;
	//DaneOsobowe dane_osobowe; // Pole klasy Czytelnik
	//chwilowo usuwam dane osobowe bo nie dzia³aj¹

	string imie;
	string nazwisko;
	string email;
	string adres;
	int numer_tel;
	string login;
	string haslo;
	bool blokada=false;

public:
	Czytelnik(string i, string n, string e, string a, int tel, string l, string h);
	Czytelnik();

	string getImie();
	string getNazwisko();
	string getEmail();
	string getAdres();
	int getNum();
	string getLogin();
	int getID();

	bool invertBlodaka();

	void wypozycz(int isbn, string login, BazaKsiazek baza_ksiazek, BazaWypozyczen baza_wyp, BazaSkrytek baza_skrytek);
	bool checkPass(const string& pass) const;
};

class BazaUzytkownikow {
	friend class Czytelnik;
	friend class Bibliotekarz;

	vector<Czytelnik> lista_czytelnikow;
	vector<Czytelnik> lista_zablokowanych;

	string nazwa_pliku = "baza_czytelnikow.txt";
	string nazwa_pliku_blokady = "baza_czytelnikow_blokada.txt";

public:
	BazaUzytkownikow();

	void loadFromFile();
	void saveToFile();

	void loadBlockedFromFile();
	void saveBlockedToFile();

	void setUsers();
	void add(string i, string n, string e, string a, int tel, string l, string h);
	bool wyszukaj_czy_jest(const string& login) const;
	bool wyszukaj_czy_jest_zabl(const string& login);
	Czytelnik wyszukaj(const string& login) const;
	void usun(const string& login);

	vector<Czytelnik> getlista_czytelnikow();
	vector<Czytelnik> getlista_zablokowanych();

	void blockUser(const string& login);
	void unblockUser(const string& login);
};

class Bibliotekarz {
	string login;
	string haslo;
	void sendEmail(string email, string login, string tyt, string dat, int num);
public:
	Bibliotekarz();
	void dodanie_ksiazki(string t, string au, int isbn, string okl, BazaKsiazek baza);
	void usuniecie_ksiazki(Ksiazka k, BazaKsiazek baza);
	void akceptacja_wyp(BazaWypozyczen& baza_wyp, int isbn, BazaSkrytek& baza_skrytek, BazaUzytkownikow& baza_uz, BazaKsiazek& baza_ks);
	//void przyjecie_zwr();
};

class Skrytka {
	friend class BazaSkrytek;
	friend ostream& operator<<(ostream& os, const Skrytka& skrytka);

	int id;
	bool wolna;
	int numer_wypozyczenia;

public:
	void setID(int id);

	int getID();
	int getNumerWypozyczenia();

	Skrytka();
	Skrytka(int id, bool wolna, int numer_wypozyczenia);
};

class BazaSkrytek {
	string nazwa_pliku = "baza_skrytek.txt";

	void loadFromFile(); // Wczytanie bazy z pliku
	void saveToFile();   // Zapis ca³ej bazy do pliku

public:
	vector<Skrytka> lista_skrytek;

	BazaSkrytek(int num);
	void setSkrytki();
	void add();
	void zajmij(int numer, int isbn);
	void zwolnij(int id);
	void usun_skrytke(int id);
	bool wyszukaj_czy_jest(int id) const;
	Skrytka wyszukaj(int id) const;
	int getFirstFree();
};

class Wypozyczenie {
	friend ostream& operator<<(ostream& os, const Wypozyczenie& wypozyczenie);
	friend class BazaWypozyczen;
	friend class BazaKsiazek;
	friend class BazaUzytkownikow;
	friend class BazaSkrytek;
	friend class Bibliotekarz;

	int numer_skrytki;
	string login_czytelnika;
public:
	int isbn_ksiazki;
	string data_wypozyczenia;
	string data_oddania;

	string getLogin();
	int getISBN();
	Wypozyczenie(string dat_wyp, string dat_od, int skr, int num_ks, string log);
	void end_wyp();

	void prolong(int num, string data);
};

class BazaWypozyczen {
	//mamy dwie listy wypozyczen, pierwsza to lista wypozyczen, druga to lista wypozyczen w poczekalni (do akceptacji przez bibliotekarza
	//po akceptacji przenosimy wypozyczenie do listy wypozyczen

	friend class Czytelnik;
	friend class Bibliotekarz;

	string nazwa_pliku = "baza_wypozyczen.txt";
	string nazwa_pliku_pocz = "baza_wypozyczen_poczekalnia.txt";
	string nazwa_pliku_zwrotow = "baza_zwrotow.txt";

	void loadFromFile();
	void saveToFile();

	void loadFromFile_pocz();
	void saveToFile_pocz();

	void saveToFileZwroty();

	void add(string dat_wyp, string dat_od, int skr, int num_ks, string log);
public:
	BazaWypozyczen();

	vector<Wypozyczenie> lista_wypozyczen;
	vector<Wypozyczenie> lista_wypozyczen_pocz;
	vector<Wypozyczenie> lista_wypozyczen_zwroty;

	vector<Wypozyczenie> getlista_wypozyczen_pocz();
	vector<Wypozyczenie> getlista_wypozyczen_zwroty();

	void setWyp();
	void saveWyp();

	void przyznanieWyp(string login, int isbn, BazaSkrytek baza_skrytek);
	bool isBookBorrowed(int isbn) const;
	void end_wyp(int num_ks);

	void loadFromFileZwroty();
	void przeniesDoZwrotow(int isbn);
	void setZwroty();
	void usunZwrot(int isbn);

	void checkAndBlockLateUsers(BazaUzytkownikow& baza_uzytkownikow);
};
