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

    std::string fillWithZeroes(int num);
    std::string getWeekDay(int d, int m, int y);
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

    std::string slashOutput(int d, int m, int y);
    std::string hyphenOutput(int d, int m, int y);
    std::string dotOutput(int d, int m, int y);
    std::string verbalMonthOutput(int d, int m, int y);
    std::string verbalDayOutput(int d, int m, int y);

};

