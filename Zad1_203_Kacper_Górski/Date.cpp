#include <string>
#include "Date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) { }

// Private methods
std::string Date::convertMonth(int mon) const {
    // Convert month digit into polish names of the month

    std::string result;

    switch (mon) {
    case 1:
        result = "Stycze�";
        break;
    case 2:
        result = "Luty";
        break;
    case 3:
        result = "Marzec";
        break;
    case 4:
        result = "Kwiecie�";
        break;
    case 5:
        result = "Maj";
        break;
    case 6:
        result = "Czerwiec";
        break;
    case 7:
        result = "Lipiec";
        break;
    case 8:
        result = "Sierpie�";
        break;
    case 9:
        result = "Wrzesie�";
        break;
    case 10:
        result = "Pa�dziernik";
        break;
    case 11:
        result = "Listopad";
        break;
    case 12:
        result = "Grudzie�";
        break;
    default:
        result = "Niepoprawny miesi�c";
    }
    return result;
}

std::string Date::convertMonthGenitive(int mon) const {
    std::string result;

    switch (mon) {
    case 1:
        result = "Stycznia";
        break;
    case 2:
        result = "Lutego";
        break;
    case 3:
        result = "Marca";
        break;
    case 4:
        result = "Kwietnia";
        break;
    case 5:
        result = "Maja";
        break;
    case 6:
        result = "Czerwca";
        break;
    case 7:
        result = "Lipca";
        break;
    case 8:
        result = "Sierpnia";
        break;
    case 9:
        result = "Wrze�nia";
        break;
    case 10:
        result = "Pa�dziernika";
        break;
    case 11:
        result = "Listopada";
        break;
    case 12:
        result = "Grudnia";
        break;
    default:
        result = "Niepoprawnego miesi�ca";
    }
    return result;
}



// Public Methods

//Getters
int Date::getDay(void) const { return day; }
int Date::getMonthDigits(void) const { return month; }
int Date::getYear(void) const { return year; }
std::string Date::getMonthName(void) const { return convertMonth(month); }

//Setters
void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }
