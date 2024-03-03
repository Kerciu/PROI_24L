#include <string>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include "Date.h"

// TODO: Figure out how to use scoped enum

Date::Date(int d, Month m, int y) : day(d), month(m), year(y) { }

// Private methods
std::string Date::fillWithZeroes(int num); {
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

    std::string days[] = { "Sobota", "Niedziela", "Poniedzia³ek", "Wtorek", "Œroda", "Czwartek", "Pi¹tek" };

    return days[h];
}

std::string Date::convertMonth(Month mon) const {
    std::string result;

    switch (mon) {
    case Month::January:
        result = "Styczeñ";
        break;
    case Month::February:
        result = "Luty";
        break;
    case Month::March:
        result = "Marzec";
        break;
    case Month::April:
        result = "Kwiecieñ";
        break;
    case Month::May:
        result = "Maj";
        break;
    case Month::June:
        result = "Czerwiec";
        break;
    case Month::July:
        result = "Lipiec";
        break;
    case Month::August:
        result = "Sierpieñ";
        break;
    case Month::September:
        result = "Wrzesieñ";
        break;
    case Month::October:
        result = "PaŸdziernik";
        break;
    case Month::November:
        result = "Listopad";
        break;
    case Month::December:
        result = "Grudzieñ";
        break;
    }
    return result;
}

std::string Date::convertMonthGenitive(Month mon) const {
    std::string result;

    switch (mon) {
    case Month::January:
        result = "Stycznia";
        break;
    case Month::February:
        result = "Lutego";
        break;
    case Month::March:
        result = "Marca";
        break;
    case Month::April:
        result = "Kwietnia";
        break;
    case Month::May:
        result = "Maja";
        break;
    case Month::June:
        result = "Czerwca";
        break;
    case Month::July:
        result = "Lipca";
        break;
    case Month::August:
        result = "Sierpnia";
        break;
    case Month::September:
        result = "Wrzeœnia";
        break;
    case Month::October:
        result = "PaŸdziernika";
        break;
    case Month::November:
        result = "Listopada";
        break;
    case Month::December:
        result = "Grudnia";
        break;
    }
    return result;
}

// TODO: Make check[..]Value functions

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

bool Date::checkMonthValue(Month mon) const {
    if (mon < 1 || mon > 12) {
        return false;
    }
    else { return true; }
}

bool Date::checkYearValue(int y) const {
    if (y >= 0) { return true; }
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
int Date::getDay(void) const { return day; }
Date::Month Date::getMonthDigits(void) const { return month; }
int Date::getYear(void) const { return year; }
std::string Date::getMonthName(void) const { return convertMonth(month); }

//Setters
void Date::setDay(int d) { 
    if (checkDayValue(d)) {
        day = d;
    }
    else { throw std::out_of_range("Day out of range!"); }
}
void Date::setMonth(Month m) {
    if (checkMonthValue(m)) {
        month = m;
    }
    else { throw std::out_of_range("Month out of range!"); }
}
void Date::setYear(int y) {
    if (checkDayValue(y)) {
        year = y;
    }
    else { throw std::out_of_range("Year out of range!"); }
}

//Output methods
std::string Date::slashOutput(int d, int m, int y) {
    return fillWithZeroes(d) + "/" + fillWithZeroes(m) + "/" + std::to_string(y);
}

std::string Date::hyphenOutput(int d, int m, int y) {
    return fillWithZeroes(d) + "-" + fillWithZeroes(m) + "-" + std::to_string(y);
}

std::string Date::dotOutput(int d, int m, int y) {
    return fillWithZeroes(d) + "." + fillWithZeroes(m) + "." + std::to_string(y);
}

std::string Date::verbalMonthOutput(int d, int m, int y) {
    return std::to_string(d) + " " + convertMonthGenitive(m) + " " + std::to_string(y);
}

std::string Date::verbalDayOutput(int d, int m, int y) {
    return getWeekDay(d, m, y) + " " + std::to_string(d) + "." + fillWithZeroes(m) + "." + std::to_string(y);
}