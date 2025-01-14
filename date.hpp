#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <ctime>


//funckja pobiera aktualny czas i zwraca go jako string
std::string getCurrentDateTime() {
    // Pobranie aktualnego czasu
    auto now = std::chrono::system_clock::now();
    std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);

    // Konwersja do struktury tm za pomocą localtime_s
    std::tm nowTm = {};
    localtime_s(&nowTm, &nowTimeT); // Bezpieczna wersja localtime

    // Formatowanie daty i czasu
    std::ostringstream oss;
    oss << std::put_time(&nowTm, "%Y-%m-%d;%H:%M");
    return oss.str();
}


//funkcja dodaje do aktualnej daty podaną liczbę dni i zwraca ją jako string
std::string addDaysToDate(const std::string& date, int daysToAdd) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        throw std::invalid_argument("Invalid date format. Use YYYY-MM-DD.");
    }

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;

    // Dodaj dni
    tm.tm_mday += daysToAdd;
    std::mktime(&tm);

    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    return std::string(buffer);
}


//funkcja sprawdza czy podana data jest datą przeszłą
bool isPastDate(const std::string& dateTimeStr) {
    // Zamiana średnika na spację (ułatwia parsowanie)
    std::string formattedDateTime = dateTimeStr;

    if (formattedDateTime.back() == '*') {
        //obsłużenie przypadku prolongaty - gwiazdki na końcu
        formattedDateTime.pop_back();
    }

    std::replace(formattedDateTime.begin(), formattedDateTime.end(), ';', ' ');

    // Parsowanie stringa na strukturę tm
    std::tm inputTm = {};
    std::istringstream iss(formattedDateTime);
    iss >> std::get_time(&inputTm, "%Y-%m-%d %H:%M");
    if (iss.fail()) {
        std::cerr << "Błąd: Nieprawidłowy format daty i czasu." << std::endl;
        return false;
    }

    // Konwersja struktury tm na std::time_t
    std::time_t inputTime = std::mktime(&inputTm);
    if (inputTime == -1) {
        std::cerr << "Błąd: Nie można przetworzyć daty i czasu." << std::endl;
        return false;
    }

    // Pobranie aktualnego czasu
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Porównanie
    return inputTime < currentTime;
}


bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        throw std::invalid_argument("Invalid month");
    }
}

std::string replaceDay(const std::string& dateTime, int newDay) {
    if (dateTime.length() != 16 || dateTime[4] != '-' || dateTime[7] != '-' || dateTime[10] != ';' || dateTime[13] != ':') {
        std::cerr << "[ERROR] Invalid date-time format: " << dateTime << std::endl;
        throw std::invalid_argument("Invalid date-time format. Use YYYY-MM-DD;HH:MM.");
    }

    // Parsuj część daty
    int year = std::stoi(dateTime.substr(0, 4));
    int month = std::stoi(dateTime.substr(5, 2));
    int day = std::stoi(dateTime.substr(8, 2));

    // Parsuj część godziny
    std::string timePart = dateTime.substr(11); // Zaczynamy od indeksu 11
    int hours = std::stoi(timePart.substr(0, 2));
    int minutes = std::stoi(timePart.substr(3, 2));

    // Dodajemy dni, uwzględniając miesiące
    while (newDay > getDaysInMonth(month, year)) {
        newDay -= getDaysInMonth(month, year);
        month++;
        if (month > 12) { // Przejście na nowy rok
            month = 1;
            year++;
        }
    }

    // Zbuduj nowy ciąg w formacie YYYY-MM-DD;HH:MM
    char buffer[17];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d;%02d:%02d", year, month, newDay, hours, minutes);
    return std::string(buffer);
}
