#include "pch.h"
#include "reader.h"
#include <iostream>

// stringstream

// ��������� ������
void readFoodInfo(istream& inputFile, vector<FoodInfo>& foodList) {
    while (!inputFile.eof()) {
        FoodInfo food = FoodInfo::readFoodInfoFromFile(inputFile);
        foodList.push_back(food);
    }
}

// ������� ������
void displayFoodInfo(const vector<FoodInfo>& foodList, ostream& out) {
    for (const FoodInfo& food : foodList) {
        food.printFoodInfo(out);
    }
}