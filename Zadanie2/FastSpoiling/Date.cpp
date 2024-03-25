#include <string>
#include <stdexcept>
#include <iomanip>
#include <sstream>
#include "Date.h"

// Constructor
Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
    if (!checkDayValue(day) || !checkMonthValue(month) || !checkYearValue(year))
    {
        throw std::out_of_range("Date values out of correct ranges!");
    }
}

// Private methods
std::string Date::fillWithZeroes(int num) const {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << num;
    return ss.str();
}

std::string Date::shortenYear(int y) const {
    std::string stringYear = std::to_string(y);
    return stringYear.substr(stringYear.length() - 2);
}

std::string Date::getWeekDay(int d, int m, int y) const {
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

int Date::getMaxDayInMonth(int mon, int y) const {
    static constexpr int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int maxDayInMonth = daysInMonth[mon - 1];

    if (mon == 2 && determineLeapYear(y)) {
        maxDayInMonth = 29;
    }
    return maxDayInMonth;
}

bool Date::checkDayValue(int d) const {
    int maxDayInMonth = getMaxDayInMonth(month, year);
    return (d <= maxDayInMonth && d > 0);
}

bool Date::checkMonthValue(int mon) const {
    return !(mon < 1 || mon > 12);
}

bool Date::checkYearValue(int y) const {
    return (y > 0 && y <= 9999);
}

bool Date::determineLeapYear(int y) const {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

// Public Methods

//Getters
int Date::getDay(void) const {
    return day;
}
int Date::getMonthDigits(void) const {
    return month;
}
int Date::getYear(void) const {
    return year;
}
std::string Date::getMonthName(void) const {
    return convertMonth(month);
}

//Setters
void Date::setDay(int d) {
    checkDayValue(d) ? day = d : throw std::out_of_range("Day out of range!");
}

void Date::setMonth(int m) {
    checkMonthValue(m) ? month = m : throw std::out_of_range("Month out of range!");
}

void Date::setYear(int y) {
    checkYearValue(y) ? year = y : throw std::out_of_range("Year out of range!");
}

//Output methods
std::string Date::slashOutput(void) const {
    return fillWithZeroes(day) + "/" + fillWithZeroes(month) + "/" + std::to_string(year);
}

std::string Date::hyphenOutput(void) const {
    return fillWithZeroes(day) + "-" + fillWithZeroes(month) + "-" + std::to_string(year);
}

std::string Date::dotOutput(void) const {
    return fillWithZeroes(day) + "." + fillWithZeroes(month) + "." + std::to_string(year);
}

std::string Date::shortenedYearOutput(void) const {
    return std::to_string(day) + "." + fillWithZeroes(month) + "." + shortenYear(year);
}

std::string Date::verbalMonthOutput(void) const {
    return std::to_string(day) + " " + convertMonthGenitive(month) + " " + std::to_string(year);
}

std::string Date::verbalDayOutput(void) const {
    return getWeekDay(day, month, year) + " " + std::to_string(day) + "." + fillWithZeroes(month) + "." + std::to_string(year);
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator>(const Date& other) const {
    if (year > other.year) { return true; }
    else if (year < other.year) { return false; }
    else {
        if (month > other.month) { return true; }
        else if (month < other.month) { return false; }
        else {
            return day > other.day;
        }
    }
}