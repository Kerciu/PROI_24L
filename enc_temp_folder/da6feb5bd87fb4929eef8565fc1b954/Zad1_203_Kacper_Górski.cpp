#include <iostream>
#include "Date.h"

int main()
{   
    Date date(15, 7, 2004);
    std::cout << "Dzien: " << date.getDay() << std::endl;
    std::cout << "Miesiac: " << date.getMonthName() << " (" << date.getMonthDigits() << ")" << std::endl;
    std::cout << "Rok: " << date.getYear() << std::endl;
    std::cout << "\n";

    std::cout << date.slashOutput() << std::endl;
    std::cout << date.hyphenOutput() << std::endl;
    std::cout << date.dotOutput() << std::endl;
    std::cout << date.verbalMonthOutput() << std::endl;
    std::cout << date.verbalDayOutput() << std::endl;
}
