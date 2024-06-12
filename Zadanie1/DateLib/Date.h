#pragma once

class Date {

private:
    int day;
    int month;
    int year;

    std::string fillWithZeroes(int num);
    std::string shortenYear(int y);
    std::string getWeekDay(int d, int m, int y);
    std::string convertMonth(int mon) const;
    std::string convertMonthGenitive(int mon) const;
    int getMaxDayInMonth(int mon, int y) const;
    bool checkDayValue(int d) const;
    bool checkMonthValue(int mon) const;
    bool checkYearValue(int y) const;
    bool determineLeapYear(int y) const;

public:
    Date(int d, int m, int y);

    int getDay(void) const;
    int getMonthDigits(void) const;
    int getYear(void) const;
    std::string getMonthName(void) const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    std::string slashOutput(void);
    std::string hyphenOutput(void);
    std::string dotOutput(void);
    std::string shortenedYearOutput(void);
    std::string verbalMonthOutput(void);
    std::string verbalDayOutput(void);

};

