#pragma once

class Date {

private:
    int day;
    int month;
    int year;

    std::string fillWithZeroes(int num) const;
    std::string shortenYear(int y) const;
    std::string getWeekDay(int d, int m, int y) const;
    std::string convertMonth(int mon) const;
    std::string convertMonthGenitive(int mon) const;
    int getMaxDayInMonth(int mon, int y) const;
    bool checkDayValue(int d) const;
    bool checkMonthValue(int mon) const;
    bool checkYearValue(int y) const;
    bool determineLeapYear(int y) const;

public:
    Date();
    Date(int d, int m, int y);

    int getDay(void) const;
    int getMonthDigits(void) const;
    int getYear(void) const;
    std::string getMonthName(void) const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    std::string slashOutput(void) const;
    std::string hyphenOutput(void) const;
    std::string dotOutput(void) const;
    std::string shortenedYearOutput(void) const;
    std::string verbalMonthOutput(void) const;
    std::string verbalDayOutput(void) const;

    bool isDefaultDate(void) const;

    bool operator==(const Date& other) const;
    bool operator>(const Date& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};


