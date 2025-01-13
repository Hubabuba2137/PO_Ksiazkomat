# PO_biblioteka
Książkomat to taki paczkomat ale dla książek. Wypożyczasz książki i odbierasz je w skrytce a potem też je tam oddajesz.

Getting started:

Najpierw należy utworzyć nowy projekt w VS, najlepiej pusty. Następnie kopiujemy do niego: static, templates, Klasy.cpp, Klasy.h, date.hpp, server.cpp, send_email.exe i baza_ksiazek.txt.
Następnie pklikamy widok, terminal. W nim wpisujemy:

    vcpkg integrate install

Następnie przechodzimy do właściwości projektu (prawy przycisk na ikonkę rozwiązania projektu - sln) i w sekcji vcpkg, zezwalamy na użycie manifestu.
Potem ponownie otwieramy terminal i w nim wpisujemy:

    vcpkg new --application
    vcpkg add port crow

Po udanym zainstalowaniu należy skompilować rozwiązanie (f7). Przy powodzeniu wyłączyć i włączyć ponownie VS (aby pozbyć się podkreśleń i informacji o błędach).
Możemy teraz uruchomić program w VS i powinno otworzyć się okno terminala, po czym w przeglądarce wpisać:

    localhost:8080


Wybrane mechanizmy:

    Tworzenie konta - wprowadza się dane na stronie, system sprawdza w bazie czy nie ma już takiego użytkownika, jeżeli nie to dodaje nowy obiekt do listy użytkowników i wzywa   funkcję do zapisu pliku z użytkownikami.


  Logowanie - system sprawdza czy dane logowania są zgodne z tymi co w bazie użytkowników. Jeżeli dane logowania do dane admina to system przekierowywuje na stronę bibliotekarza.
  Jeżeli użytkownik jest zablokowany (jego dane znajdują się w pliku "baza_czytelnikow_bloakda.txt") to ystem uniemożliwia zalogowanie i informuje o potrzebie zwrócenia książki i uiszczeniu opłaty u bibliotekarza.


  Wyszukanie - można albo przejść na stronę do wyszukiwania albo kliknąć w książkę na stronie głównej. Zalogowany użytkownik może, po wyszukaniu, wypożyczyć książkę.


  Wypożyczenie - zalogowany użytkownik klika przycisk "wypożycz" po wyszukaniu książki. System sprawdza czy książka już nie jest wypożyczona, jeżeli nie to uruchamiana jest funkcja Czytelnik::wypozycz, która po sprawdzeniu czy książka istnieje, uruchamia funkcję BazaWypożyczeń::przyznanieWyp. Funkcja ta po sprawdzeniu, dodaje wypożcyzenie do poczekalni.
  Następnie bibliotekkarz może zaakceptować wypożyczenie u siebie na stronie do zarządzania wypożyczeniami (bib_wyp.html), wywołując funkcję Bibliotekarz::akceptacja_wyp, która tworzy właściwe wypożyczenie (pobiera i ustawia daty itd.). Funkcja ta też wywołują inną funkcję Bibliotekarz::sendEmail. Po zaakceptowaniu wypożyczenia, znajduje się ono potem na profilu użytkownika.
  Wysyłanie emaila polega na dodaniu najpierw danych do pliku email.txt o formacie: "email/login/tytul_ksiazki/data_oddania/numer_skrytki", po czym uruchamia plik send_email.exe.
  Jest to skrypt w pythonie, który wczytuje potrzebne dane i wysyłka emaila (nie działało uruchamianie pliku.py to zrobiłem .exe)

Dane:

  Wszystkie dane są przechowywane w plikach txt w odpowiednich formatach. Kolejność danych i sposób ich rozdzielania jest kluczony!
    Mamy:
    
      - baza_czytelnikow.txt - zawiera dane czytelników (niezablokowanych) w formacie: "id imie nazwisko email adres telefon login haslo".
      
      - baza_czytelnikow_bloakda.txt - zawiera dane czytelników zablokowanych w takim samym formacie co poprzednio.
      
      - baza_ksiazek.txt - zawiera dane książek w formacie - "id, tytuł, autor, numer_isbn, nazwa_pliku_okłdaki.jpg"
      
      - baza_skrytek.txt - zawiera spis wszystkich skrytek, tego czy są wolne i jakie książki w nich są, w formacie: "id wolne (1-tak, 0-nie) isbn_skiążki(-1 to brak)"
      
      - baza_wypozyczen.txt - zawiera aktualne wypożyczenia w formacie: "data_wypożyczenia;godzina dataoddania;godzina skrytka isbn login"
      
      - baza_wypozyczen_poczekalnia.txt - zawiera książki wypożyczone przez użytkowników, czekające na akceptacje (umieszczenie w książkomacie) przez bibliotekarza, 
          w formacie: "isbn login"
          
      - baza_zwrotow.txt - zawiera książki zwrócone przez użytkowników, czekające na zebranie ich przez bibliotekarza, w formacie: "isbn login".

Kod stron internetowych znajduje się w folderze template (wymóg crow.h).
Obrazy (okładki) znajdują się w folderze static (zalecenie crow.h).
