#include "pch.h"
#include "FoodInfo.h"
#include "Date.h"
#include <iostream>


// ����������
// ������ ����������
void FoodInfo::printFoodInfo(ostream& out) const {
    out << "Date: ";
    date.print(out);
    out << ", Food name: " << foodName << ", Food value: " << foodValue << endl;
}

// ����������
// ���������� ����������
FoodInfo FoodInfo::readFoodInfoFromFile(istream& inputFile) {
    FoodInfo food;

    food.date = Date::create_from_stream(inputFile);
    inputFile >> food.foodName;
    inputFile >> food.foodValue;

    if (!food.isValid()) {
        throw runtime_error("�������� ������ FoodInfo � �����.");
    }

    return food;
}
// ����������
// �������� ���������� �����
bool FoodInfo::isValidFoodName(const string& name)
{
    // ������ ������ 13
    if (name.length() > 13) {
        return false;
    }

    // � ����� ����������� �����
    for (int i = 0; i < name.length(); i++) {
        if (std::isdigit(name[i])) {
            return false;
        }
    }

    return true;
}


// ����������
// �������� ���������� ����������
bool FoodInfo::isValidFoodValue(const int& value) {

    // ���������� ������ ����
    if (value <= 0) {
        return false;
    }

    // ����� �������� �������
    string str = to_string(value);
    for (int i = 0; i <= str.length() - 1; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

// ����������
// �������� ���������� ����, ����� � ����������
bool FoodInfo::isValid() const
{
    return date.isValid() && isValidFoodName(foodName) && isValidFoodValue(foodValue);
}