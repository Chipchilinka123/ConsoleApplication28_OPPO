#pragma once
#include <iostream>

// —труктура даты
struct Date {

    // ƒень, мес€ц и год
    int day;
    int month;
    int year;

    Date(); // ќбъ€вление конструктора
    Date(int day, int month, int year);
    bool isValid() const;

    void print(std::ostream& out) const;
    static Date create_from_stream(std::istream& stream);
    static bool isDateValid(const Date& date);
};
