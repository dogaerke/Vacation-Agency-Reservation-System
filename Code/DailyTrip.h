#ifndef _DAILYTRIP_H_
#define _DAILYTRIP_H_
#include <string>
#include "VacationTypes.h"

class DailyTrip : public VacationTypes
{
public:
    DailyTrip() {

    }

    DailyTrip(std::string season, std::string place, int price) {
	this->season = season;
	this->place = place;
    this->price = price;
    }

    ~DailyTrip() {}

    DailyTrip& operator = (const DailyTrip& obj) {
        season = obj.season;
        place = obj.place;
        price = obj.price;
        startingDate = obj.startingDate;
        customerAmount = obj.customerAmount;
        return *this;
    }
};

#endif