import smtplib
import random
from email.message import EmailMessage

#kod źródłowy pliku send_email.exe
#serwer nie uruchamiał tego pliku
#to zrobiłem .exe, który działa
#essa

# Dane konta Gmail
SMTP_SERVER = "smtp.gmail.com"
SMTP_PORT = 587
EMAIL_ADDRESS = "ksiazkomat0@gmail.com"
APP_PASSWORD = "easd zwgk gkfc ezdq"

def key():
    val = ""
    for x in range(4):
        val += str(random.randint(0,9))
    return val

def wyslij_email(odbiorca, temat, tresc):
    """Funkcja wysyłająca wiadomość email."""
    msg = EmailMessage()
    msg['From'] = EMAIL_ADDRESS
    msg['To'] = odbiorca
    msg['Subject'] = temat
    msg.set_content(tresc)

    try:
        with smtplib.SMTP(SMTP_SERVER, SMTP_PORT) as server:
            server.starttls()
            server.login(EMAIL_ADDRESS, APP_PASSWORD)
            server.send_message(msg)
            print(f"Wiadomość wysłana do {odbiorca}")
    except Exception as e:
        print(f"Błąd podczas wysyłania wiadomości do {odbiorca}: {e}")

def wyslij_powiadomienia_z_pliku(plik):
    """Wczytuje dane z pliku, wysyła wiadomości i usuwa przetworzone linie."""
    try:
        # Wczytaj wszystkie linie z pliku
        with open(plik, 'r', encoding='utf-8') as file:
            linie = file.readlines()

        # Lista linii, które pozostaną w pliku po przetworzeniu
        pozostale_linie = []

        for linia in linie:
            linia = linia.strip()
            if linia:
                try:
                    # Rozdzielenie danych z linii
                    email, login, tytul_ksiazki, data_oddania, numer_skrytki = linia.split('/')

                    # Przygotowanie wiadomości
                    temat = "Informacja o wypożyczeniu książki"
                    tresc = (f"Dziękujemy {login} za wypożyczenie \"{tytul_ksiazki}\".\n"
                             f"Możesz ją odebrać w skrytce {numer_skrytki} z kodem odbioru: {key()}\n"
                             f"Oddaj ją do {data_oddania}.")

                    # Wysłanie wiadomości
                    wyslij_email(email, temat, tresc)
                except Exception as e:
                    print(f"Błąd podczas przetwarzania linii: {linia}\nSzczegóły: {e}")
                    pozostale_linie.append(linia)  # Zachowaj linię, jeśli wystąpił błąd
            else:
                pozostale_linie.append(linia)

        # Nadpisz plik tylko z pozostałymi liniami
        with open(plik, 'w', encoding='utf-8') as file:
            file.write('\n'.join(pozostale_linie))

    except FileNotFoundError:
        print(f"Plik {plik} nie istnieje.")
    except Exception as e:
        print(f"Wystąpił błąd podczas przetwarzania pliku {plik}: {e}")

# Wywołanie funkcji
wyslij_powiadomienia_z_pliku("email.txt")