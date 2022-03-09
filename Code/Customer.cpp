#include "Customer.h"


Customer::Customer(std::string nameVal, int IDVal, std::string sexVal, std::string mailVal)
	: name{nameVal}, ID{IDVal}, sex{sexVal}, mail{mailVal}{}

Customer::Customer(const Customer& obj) {
	name = obj.name;
	ID = obj.ID;
	sex = obj.sex;
	mail = obj.mail;
	birthDate = obj.birthDate;
}

Customer::~Customer(){}


