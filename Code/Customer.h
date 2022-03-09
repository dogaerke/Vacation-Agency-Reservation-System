#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include <string>
#include "Date.h"
#include "VacationTypes.h"
#include "Payment.h"

class Customer
{
protected:
	std::string name;
	long long int ID;
	std::string sex;	
	std::string mail;
	Date birthDate;

public:
	
	std::string getName() { return name; }
	void setName(std::string name) { this->name = name; }
	
	long long int getID() { return ID; }
	void setID(long long int ID) { this->ID = ID; }

	std::string getSex() { return sex; }
	void setSex(std::string sex) { this->sex = sex; }

	std::string getMail() { return mail; }
	void setMail(std::string mail) { this->mail = mail; }

	Date getDate() { return birthDate; }
	void setDate(Date d) { birthDate = d; }

	Customer(std::string name = "", int ID = 0, std::string sex = "", std::string mail = "");

	Customer(const Customer& obj);

	Customer& operator = (const Customer& obj) {
		name = obj.name;
		ID = obj.ID;
		sex = obj.sex;
		mail = obj.mail;
		birthDate = obj.birthDate;
		return *this;
	}

	virtual ~Customer();

	virtual float discount() = 0;
};


#endif