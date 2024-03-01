#include <iostream>
#include <string>

class Date {
private:
    int day, month, year;

    std::string convertMonth(int mon) {
        // Convert month digit into polish names of the month

        std::string result;

        switch (mon) {
        case 1:
            result = "Styczeń";
            break;
        case 2:
            result = "Luty";
            break;
        case 3:
            result = "Marzec";
            break;
        case 4:
            result = "Kwiecień";
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
            result = "Sierpień";
            break;
        case 9:
            result = "Wrzesień";
            break;
        case 10:
            result = "Październik";
            break;
        case 11:
            result = "Listopad";
            break;
        case 12:
            result = "Grudzień";
            break;
        default:
            result = "Niepoprawny miesiąc";
        }
        return result;
    }

public:
    // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) { }

    // Getters
    int getDay(void) const { return day; }
    int getMonthDigits(void) const { return month; }
    int getYear(void) const { return year; }
    std::string getMonthName(void) { return convertMonth(month); }

    //Setters
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { month = y; }
};

int main()
{   
    std::cout << "Hello World!\n";
}
