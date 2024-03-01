#pragma once

class Date {

private:
    int day, month, year;

    std::string convertMonth(int mon) const;
    std::string convertMonthGenitive(int mon) const;

public:
    Date(int d, int m, int y);

    int getDay(void) const;
    int getMonthDigits(void) const;
    int getYear(void) const;
    std::string getMonthName(void) const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
};

