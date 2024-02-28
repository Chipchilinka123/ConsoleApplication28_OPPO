#include "pch.h"
#include "FoodInfo.h"
#include "Date.h"
#include <iostream>


// Исправлено
// Печать информации
void FoodInfo::printFoodInfo(ostream& out) const {
    out << "Date: ";
    date.print(out);
    out << ", Food name: " << foodName << ", Food value: " << foodValue << endl;
}

// Исправлено
// Считывание информации
FoodInfo FoodInfo::readFoodInfoFromFile(istream& inputFile) {
    FoodInfo food;

    food.date = Date::create_from_stream(inputFile);
    inputFile >> food.foodName;
    inputFile >> food.foodValue;

    if (!food.isValid()) {
        throw runtime_error("Неверные данные FoodInfo в файле.");
    }

    return food;
}
// Исправлено
// Проверка валидности имени
bool FoodInfo::isValidFoodName(const string& name)
{
    // Размер больше 13
    if (name.length() > 13) {
        return false;
    }

    // В слове встречается цифра
    for (int i = 0; i < name.length(); i++) {
        if (std::isdigit(name[i])) {
            return false;
        }
    }

    return true;
}


// Исправлено
// Проверка валидности количества
bool FoodInfo::isValidFoodValue(const int& value) {

    // Количество меньше нуля
    if (value <= 0) {
        return false;
    }

    // Число является строкой
    string str = to_string(value);
    for (int i = 0; i <= str.length() - 1; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

// Исправлено
// Проверка валидности даты, имени и количества
bool FoodInfo::isValid() const
{
    return date.isValid() && isValidFoodName(foodName) && isValidFoodValue(foodValue);
}