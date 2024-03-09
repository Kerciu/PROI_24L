#include <iostream>
#include "Date.h"

int main()
{   
    try {
        Date date1(7, 3, 2004);
        Date date2(15, 10, 2024);
        Date date3(29, 2, 2016);
        Date date4(1, 1, 1970);
        Date date5(18, 3, 1982);
        Date date6(30, 10, 2017);

        std::cout << "Getter test for date 1: " << std::endl;
        std::cout << date1.getDay() << std::endl;
        std::cout << date1.getMonthDigits() << " == " << date1.getMonthName() << std::endl;
        std::cout << date1.getYear() << std::endl;
        std::cout << '\n';

        std::cout << "Setter test for date 4: " << std::endl;
        date4.setDay(14); date4.setMonth(2); date4.setYear(2030);
        std::cout << "Should be 14.02.2030 : " << date4.dotOutput() << std::endl;
        std::cout << '\n';

        std::cout << date1.slashOutput() << std::endl;
        std::cout << date2.hyphenOutput() << std::endl;
        std::cout << date3.dotOutput() << std::endl;
        std::cout << date4.shortenedYearOutput() << std::endl;
        std::cout << date5.verbalMonthOutput() << std::endl;
        std::cout << date6.verbalDayOutput() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error in constructor: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
