#include "pch.h"
#include "Date.h"
#include <iostream>

// Конструктор по-умолчанию
Date::Date()
    : day(0)
    , month(0)
    , year(0)
{}

// Заполнение данных
Date::Date(int day, int month, int year)
    : day(day)
    , month(month)
    , year(year)
{}

// Проверка валидности даты
bool Date::isValid() const
{
    return isDateValid(*this);
}

// Печать даты
void Date::print(std::ostream& out) const {
    out << day << "." << month << "." << year;
}

// Создание даты
Date Date::create_from_stream(std::istream& stream) {
    Date result;
    char separator;

    if (!(stream >> result.day) || !(stream >> separator) || separator != '.' ||
        !(stream >> result.month) || !(stream >> separator) || separator != '.' ||
        !(stream >> result.year) || !isDateValid(result)) {
        throw std::runtime_error("Неверный формат даты или значение.");
    }

    return result;
}

// Проверка даты
bool Date::isDateValid(const Date& date) {

    // Проверяем месяц
    if (date.month < 1 || date.month > 12)
        return false;

    // Проверяем день
    if (date.day < 1)
        return false;

    // Проверка количества дней в Феврале в високосные года
    if (date.month == 2) {
        if (date.year % 4 == 0) {
            if (date.day > 29)
                return false;
        }
        // Проверка количества дней в Феврале в другие года
        else {
            if (date.day > 28)
                return false;
        }
    }
    // Проверка количества дней в Апреле, Июне, Сентябре и Ноябре
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        if (date.day > 30)
            return false;
    }
    // Проверка дней в остальные месяца
    else {
        if (date.day > 31)
            return false;
    }

    return true;
}