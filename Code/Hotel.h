#ifndef _HOTEL_H_
#define _HOTEL_H_
#include <string>
#include "VacationTypes.h"

class Hotel : public VacationTypes
{
private:
	std::string hotelType;
	std::string hotelName;
public:
	Hotel() {
		hotelName = "";
		hotelType = "";
	}

	Hotel(std::string season, std::string hotelType, std::string place, std::string hotelName, float price) {
		this->season = season;
		this->hotelType = hotelType;		
		this->place = place;
		this->hotelName = hotelName;
		this->price = price;
	}
	~Hotel(){}

	Hotel& operator = (const Hotel& obj) {
		hotelName = obj.hotelName;
		hotelType = obj.hotelType;
		price = obj.price;	
		place = obj.place;
		season = obj.season;
		return *this;
	}

	std::string getHotelType() { return hotelType; }
	void setHotelType(std::string type) { hotelType = type; }

	std::string getHotelName() { return hotelName; }
	void setHotelName(std::string name) { hotelName = name; }

};

#endif