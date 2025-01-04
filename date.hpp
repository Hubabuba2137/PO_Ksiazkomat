#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>


//funckja pobiera aktualny czas i zwraca go jako string
std::string getCurrentDateTime() {
    // Pobranie aktualnego czasu
    auto now = std::chrono::system_clock::now();
    std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);

    // Konwersja do struktury tm za pomoc� localtime_s
    std::tm nowTm = {};
    localtime_s(&nowTm, &nowTimeT); // Bezpieczna wersja localtime

    // Formatowanie daty i czasu
    std::ostringstream oss;
    oss << std::put_time(&nowTm, "%Y-%m-%d;%H:%M");
    return oss.str();
}


//funkcja dodaje do aktualnej daty podan� liczb� dni i zwraca j� jako string
std::string addDaysToDate(int daysToAdd) {
    // Pobranie aktualnego czasu
    auto now = std::chrono::system_clock::now();

    // Dodanie dni
    auto newTime = now + std::chrono::hours(24 * daysToAdd);
    std::time_t newTimeT = std::chrono::system_clock::to_time_t(newTime);

    // Konwersja do struktury tm za pomoc� localtime_s
    std::tm newTm = {};
    localtime_s(&newTm, &newTimeT); // Bezpieczna wersja localtime

    // Formatowanie daty i czasu
    std::ostringstream oss;
    oss << std::put_time(&newTm, "%Y-%m-%d;%H:%M");
    return oss.str();
}


//funkcja sprawdza czy podana data jest dat� przesz��
bool isPastDate(const std::string& dateTimeStr) {
    // Zamiana �rednika na spacj� (u�atwia parsowanie)
    std::string formattedDateTime = dateTimeStr;

    if (formattedDateTime.back() == '*') {
        //obs�u�enie przypadku prolongaty - gwiazdki na ko�cu
        formattedDateTime.pop_back();
    }

    std::replace(formattedDateTime.begin(), formattedDateTime.end(), ';', ' ');

    // Parsowanie stringa na struktur� tm
    std::tm inputTm = {};
    std::istringstream iss(formattedDateTime);
    iss >> std::get_time(&inputTm, "%Y-%m-%d %H:%M");
    if (iss.fail()) {
        std::cerr << "B��d: Nieprawid�owy format daty i czasu." << std::endl;
        return false;
    }

    // Konwersja struktury tm na std::time_t
    std::time_t inputTime = std::mktime(&inputTm);
    if (inputTime == -1) {
        std::cerr << "B��d: Nie mo�na przetworzy� daty i czasu." << std::endl;
        return false;
    }

    // Pobranie aktualnego czasu
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Por�wnanie
    return inputTime < currentTime;
}


string replaceDay(int daysToAdd, string date) {
	string days = date.substr(8, 2);
    int daysInt = stoi(days);
    daysInt += daysToAdd;
    if (daysInt < 10) {
		days = "0" + to_string(daysInt);
	}
    else {
		days = to_string(daysInt);
	}

    return date.substr(0, 8) + days + date.substr(10, 6);
}
