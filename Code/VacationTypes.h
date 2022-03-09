#ifndef _VACATIONTYPES_H_
#define _VACATIONTYPES_H_
#include "Date.h"
#include <string>

class VacationTypes
{
protected:
	std::string season;
	int customerAmount;
	std::string place;
	float totalPrice;
	float price;	
	Date startingDate;
	Date finalDate;
	int dayAmount;
	
public:
	
	VacationTypes();
	~VacationTypes();


	std::string getSeason() { return season; }
	void setSeason(std::string season) { this->season = season; }

	int getCustomerAmount() { return customerAmount; }
	void setCustomerAmount(int customerAmount) { this->customerAmount = customerAmount; }

	std::string getPlace() { return place; }
	void setPlace(std::string place) { this->place = place; }

	float getTotalPrice() { return totalPrice; }
	void setTotalPrice(float totalPrice) { this->totalPrice = totalPrice; }

	float getPrice() { return price; }
	void setPrice(float price) { this->price = price; }

	void setStartingDate(Date d) { startingDate = d; }
	Date getStartingDate() { return startingDate; }

	void setFinalDate(Date f) { finalDate = f; }
	Date getFinalDate() { return finalDate; }

	int getDayAmount() { return dayAmount; }
	void setDayAmount(int d) { dayAmount = d; }

	VacationTypes(const VacationTypes& source);
	
	
};

#endif // !_VACATIONTYPES_H_