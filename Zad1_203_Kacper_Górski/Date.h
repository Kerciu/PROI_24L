#pragma once

class Date {

private:
    enum class Month {
        January = 1, February, March, April, May, June, July,
        August, September, October, November, December
    };

    int day;
    Month month;
    int year;

    std::string convertMonth(Month mon) const;
    std::string convertMonthGenitive(Month mon) const;
    bool checkDayValue(int d) const;
    bool checkMonthValue(Month mon) const;
    bool checkYearValue(int y) const;
    bool determineLeapYear(int y) const;

public:
    Date(int d, Month m, int y);

    int getDay(void) const;
    Month getMonthDigits(void) const;
    int getYear(void) const;
    std::string getMonthName(void) const;

    void setDay(int d);
    void setMonth(Month m);
    void setYear(int y);
};

