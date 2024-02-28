#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "../ConsoleApplication28_OPPO/Date.h"
#include "../ConsoleApplication28_OPPO/FoodInfo.h"
#include "../ConsoleApplication28_OPPO/reader.h"
#include "../ConsoleApplication28_OPPO/Date.cpp"
#include "../ConsoleApplication28_OPPO/FoodInfo.cpp"
#include "../ConsoleApplication28_OPPO/reader.cpp"
#include "../ConsoleApplication28_OPPO/pch.h"
#include "../ConsoleApplication28_OPPO/pch.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Load)
		{

			std::istringstream input("10.02.2024 mango 100");

			try {
				auto food = FoodInfo::readFoodInfoFromFile(input);

				Assert::AreEqual(food.date.day, 10);
				Assert::AreEqual(food.date.month, 2);
				Assert::AreEqual(food.date.year, 2024);

				string name = "mango";
				int value = 100;

				Assert::AreEqual(food.foodName, name);
				Assert::AreEqual(food.foodValue, value);

				cout << "Load is OK" << endl;

			}
			catch(const std::exception& e){
				Assert::Fail();
			}
		}
		TEST_METHOD(IsValidDate)
		{
			FoodInfo food;

			std::istringstream input("10.02.2024 mango 100");
			food.date = Date::create_from_stream(input);
			Date date = food.date;

			if (!date.isValid()) {
				Assert::Fail();
			}
		}
		TEST_METHOD(IsValidFoodName)
		{
			std::vector<std::string> vector1 = {
				"pineapple",
				"apple",
				"qivi"
			};

			for (int i = 0; i < vector1.size(); i++) {
				if (!FoodInfo::isValidFoodName(vector1[i])) {
					Assert::Fail();
				}

			}
		}
		TEST_METHOD(IsValidFoodValue)
		{
			std::vector<int> vector1 = {
				-100,
				-10,
				-5,
			};

			for (int i = 0; i < vector1.size(); i++) {
				if (FoodInfo::isValidFoodValue(vector1[i])) {
					Assert::Fail();
				}

			}
		}

	};
}
