#pragma once
#include <iostream>

// ��������� ����
struct Date {

    // ����, ����� � ���
    int day;
    int month;
    int year;

    Date(); // ���������� ������������
    Date(int day, int month, int year);
    bool isValid() const;

    void print(std::ostream& out) const;
    static Date create_from_stream(std::istream& stream);
    static bool isDateValid(const Date& date);
};
