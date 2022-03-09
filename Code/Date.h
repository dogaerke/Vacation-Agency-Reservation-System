#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
#include<string>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 0);
    ~Date();

    Date& operator = (const Date& obj);

    Date operator - (const Date& obj);

    friend std::ostream& operator << (std::ostream& os, const Date& obj);


    int getDay() { return day; }
    void setDay(int d) { day = d; }

    int getMonth() { return month; }
    void setMonth(int m) { month = m; }

    int getYear() { return year; }
    void setYear(int y) { year = y; }
};

#endif