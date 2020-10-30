#include "Date.h"
#include <iostream>
#include <chrono>
#include <ctime>  

Date::Date(int year, int month, int day)
{
    SetDate(year, month, day);
}

void Date::SetDate(int year, int month, int day)
{
    _month = month;
    _day = day;
    _year = year;
}

void Date::SetCurrentDate() {
    // set time to current date;

}