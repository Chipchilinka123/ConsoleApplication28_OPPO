#include "pch.h"
#include "reader.h"
#include <iostream>

// stringstream

// Считываем данные
void readFoodInfo(istream& inputFile, vector<FoodInfo>& foodList) {
    while (!inputFile.eof()) {
        FoodInfo food = FoodInfo::readFoodInfoFromFile(inputFile);
        foodList.push_back(food);
    }
}

// Выводим данные
void displayFoodInfo(const vector<FoodInfo>& foodList, ostream& out) {
    for (const FoodInfo& food : foodList) {
        food.printFoodInfo(out);
    }
}