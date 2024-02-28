#pragma once
#include <vector>
#include <fstream>
#include "FoodInfo.h"

// ���������� �������
void readFoodInfo(istream& inputFile, vector<FoodInfo>& foodList);
void displayFoodInfo(const vector<FoodInfo>& foodList, ostream& out);

