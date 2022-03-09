#include "Date.h"

Date::Date(int dayVal, int monthVal, int yearVal)
    : day{ dayVal }, month{ monthVal }, year{ yearVal }{}

Date::~Date() {}

Date& Date:: operator = (const Date& obj) {
    day = obj.day;
    month = obj.month;
    year = obj.year;
    return *this;
}

Date Date:: operator - (const Date& obj) {
    int objDay = obj.day;
    int objMonth = obj.month;
    int objYear = obj.year;

    if (objDay - day < 0) {
        objDay += 30;
        objMonth--;
    }
    
    if (objMonth - month < 0) {
        objMonth += 12;
        objYear--;
    }

    objDay = objDay - day;
    objMonth = objMonth - month;
    objYear = objYear - year;
    
    Date buff(objDay, objMonth, objYear);
    return buff;
}

std::ostream & operator << (std::ostream& os, const Date& obj) {
    os << obj.day << "." << obj.month << "." << obj.year;
    return(os);
}