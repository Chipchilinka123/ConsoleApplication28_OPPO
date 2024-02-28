#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FoodInfo.h" 
#include "reader.h"
#include <cstdlib>
#include <tchar.h>
using namespace std;

#ifdef _DEBUG
#include <crtdbg.h>
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#define _CRTDBG_MAP_ALLOC
#endif

struct AtExit
{
    // Выводим признаки утечки памяти в конце программы
    ~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

int main() {

    // Делаем снимок памяти в заданной точке
    _CrtMemState _ms;
    _CrtMemCheckpoint(&_ms);

    // Переменная для проверки утечки памяти
    int* x = new int[1000];

    setlocale(0, "");
    // Данные храним в векторе
    vector<FoodInfo> foodList;

    ifstream inputFile("vkusnyashka.txt");
    if (!inputFile.is_open()) {
            cerr << "Ошибка открытия файла." << endl;
            exit(1);
    }

    try {
            // Считываем данные
            readFoodInfo(inputFile, foodList);
    }
    catch (const exception& e) {
            // Перехват исключения или обработка по необходимости
            cerr << "Ошибка при чтении FoodInfo из файла: " << e.what() << endl;
    }

    // Выводим данные
    displayFoodInfo(foodList, cout);

    return 0;

}