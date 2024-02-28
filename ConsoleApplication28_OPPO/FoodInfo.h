#pragma once
#include "Date.h"
#include <fstream>
#include <string>
using namespace std;

// ����������
// ��������� ������
struct FoodInfo {
    // ����, ��� � ���������
    Date date;
    string foodName;
    int foodValue = 0;

    // �������� ����������
    bool isValid() const;
    static bool isValidFoodName(const string& foodName);
    static bool isValidFoodValue(const int& foodValue);

    // ������ � ������
    static FoodInfo readFoodInfoFromFile(istream& inputFile);
    void printFoodInfo(ostream& out) const;
};