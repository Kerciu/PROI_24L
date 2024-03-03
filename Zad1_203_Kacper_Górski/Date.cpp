#include <string>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include "Date.h"

// TODO: Figure out how to use scoped enum

Date::Date(int d, int m, int y) : day(d), month(m), year(y) { }

// Private methods
std::string Date::fillWithZeroes(int num) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << num;
    return ss.str();
}

std::string Date::getWeekDay(int d, int m, int y) {
    // Zeller's algorythm for getting week days
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    int K = y % 100;
    int J = y / 100;
    int h = (d + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + J * 5) % 7;

    std::string days[] = { "Sobota", "Niedziela", "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek" };

    return days[h];
}

std::string Date::convertMonth(int mon) const {
    std::string result;

    switch (mon) {
    case 1:
        result = "Styczen";
        break;
    case 2:
        result = "Luty";
        break;
    case 3:
        result = "Marzec";
        break;
    case 4:
        result = "Kwiecien";
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
        result = "Sierpien";
        break;
    case 9:
        result = "Wrzesien";
        break;
    case 10:
        result = "Pazdziernik";
        break;
    case 11:
        result = "Listopad";
        break;
    case 12:
        result = "Grudzien";
        break;
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
        result = "Wrzesnia";
        break;
    case 10:
        result = "Pazdziernika";
        break;
    case 11:
        result = "Listopada";
        break;
    case 12:
        result = "Grudnia";
        break;
    }
    return result;
}

bool Date::checkDayValue(int d) const {
    int maxDayInMonth;

    if (month == 2 && determineLeapYear(year)) {
        maxDayInMonth = 29;
    }
    else {
        static constexpr int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        maxDayInMonth = daysInMonth[static_cast<int>(month) - 1];
    }
    if (d > maxDayInMonth && d < 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Date::checkMonthValue(int mon) const {
    if (mon < 1 || mon > 12) {
        return false;
    }
    else { return true; }
}

bool Date::checkYearValue(int y) const {
    if (y > 0) { return true; }
    else { return false; }
}

bool Date::determineLeapYear(int y) const {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}


// Public Methods

//Getters
int Date::getDay(void) const {
    if (checkDayValue(day)) {
        return day;;
    }
    else { throw std::out_of_range("Day out of range!"); }
}
int Date::getMonthDigits(void) const {
    if (checkMonthValue(month)) {
        return month;
    }
    else { throw std::out_of_range("Month out of range!"); }
}
int Date::getYear(void) const {
    if (checkYearValue(year)) {
        return year;
    }
    else { throw std::out_of_range("Year out of range!"); }
}
std::string Date::getMonthName(void) const { return convertMonth(month); }

//Setters
void Date::setDay(int d) { 
    if (checkDayValue(d)) {
        day = d;
    }
    else { throw std::out_of_range("Day out of range!"); }
}
void Date::setMonth(int m) {
    if (checkMonthValue(m)) {
        month = m;
    }
    else { throw std::out_of_range("Month out of range!"); }
}
void Date::setYear(int y) {
    if (checkYearValue(y)) {
        year = y;
    }
    else { throw std::out_of_range("Year out of range!"); }
}

//Output methods
std::string Date::slashOutput(void) {
    return fillWithZeroes(day) + "/" + fillWithZeroes(month) + "/" + std::to_string(year);
}

std::string Date::hyphenOutput(void) {
    return fillWithZeroes(day) + "-" + fillWithZeroes(month) + "-" + std::to_string(year);
}

std::string Date::dotOutput(void) {
    return fillWithZeroes(day) + "." + fillWithZeroes(month) + "." + std::to_string(year);
}

std::string Date::verbalMonthOutput(void) {
    return std::to_string(day) + " " + convertMonthGenitive(month) + " " + std::to_string(year);
}

std::string Date::verbalDayOutput(void) {
    return getWeekDay(day, month, year) + " " + std::to_string(day) + "." + fillWithZeroes(month) + "." + std::to_string(year);
}