#include <string>
#include <stdexcept>
#include "Date.h"

// TODO: Figure out how to use scoped enum

Date::Date(int d, Month m, int y) : day(d), month(m), year(y) { }

// Private methods
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

bool Date::checkDayValue(int d) const { }

bool Date::checkMonthValue(Month mon) const {
    if (mon < 1 || mon > 12) {
        return false;
    }
    else { return true; }
}

bool Date::checkYearValue(int y) const { }

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

    // TODO: Need to break this func into setDay() and checkDayValue() func

    int maxDayInMonth;

    if (month == 2 && determineLeapYear(year)) {
        maxDayInMonth = 29;
    }
    else {
        static constexpr int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        maxDayInMonth = daysInMonth[static_cast<int>(month) - 1];
    }
    if (d <= maxDayInMonth) {
        day = d;
    }
    else {
        throw std::out_of_range("This month is out of range!");
    }
}
void Date::setMonth(Month m) { month = m; }
void Date::setYear(int y) { year = y; }
