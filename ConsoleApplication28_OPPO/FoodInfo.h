#pragma once
#include "Date.h"
#include <fstream>
#include <string>
using namespace std;

// Исправлено
// Структура товара
struct FoodInfo {
    // Дата, имя и количесво
    Date date;
    string foodName;
    int foodValue = 0;

    // Проверка валидности
    bool isValid() const;
    static bool isValidFoodName(const string& foodName);
    static bool isValidFoodValue(const int& foodValue);

    // Чтение и печать
    static FoodInfo readFoodInfoFromFile(istream& inputFile);
    void printFoodInfo(ostream& out) const;
};