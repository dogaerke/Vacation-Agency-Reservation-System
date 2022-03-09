#include <iostream>
#include "VacationTypes.h"
#include <string>

VacationTypes::VacationTypes() {
	season = "";
	customerAmount = 0;
	totalPrice = 0.0;
	place = "";
	price = 0.0;
	dayAmount = 0;
	finalDate = NULL;
	startingDate = NULL;
}


VacationTypes::~VacationTypes(){}

VacationTypes::VacationTypes(const VacationTypes& source) {
	season = source.season;
	customerAmount = source.customerAmount;
	totalPrice = source.totalPrice;
	place = source.place;
	price = source.price;
	finalDate = source.finalDate;
	startingDate = source.startingDate;
}
