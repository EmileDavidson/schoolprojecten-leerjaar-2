#pragma once
#include <string>

class Date
{
private:
    int _year;
    int _month;
    int _day;
    std::string _output;

public:
    Date(int year = 0, int month = 0, int day = 0);

    void SetDate(int year, int month, int day);

    int getYear() { return _year; }
    int getMonth() { return _month; }
    int getDay() { return _day; }
    std::string getDate() { return _output; }
    void SetCurrentDate();
};
