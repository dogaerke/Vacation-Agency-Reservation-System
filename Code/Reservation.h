#ifndef _RESERVATION_H_
#define _RESERVATION_H_

#include "Customer.h"
#include "Payment.h"
#include "Elder.h"
#include "Adult.h"
#include "Baby.h"
#include "Student.h"
#include "Hotel.h"
#include "Camp.h"
#include "DailyTrip.h"

class Reservation {
public:

	Payment account;

	Hotel* hotel = new Hotel;
	Camp* camp = new Camp;
	DailyTrip* daily = new DailyTrip;
	Customer* elder = new Elder[10];
	Customer* adult = new Adult[10];
	Customer* baby = new Baby[10];
	Customer* student = new Student[10];
	Payment* payment = new Payment;

	Reservation() {

	}

	~Reservation() {
		delete hotel;
		delete camp;
		delete daily;
		delete[] elder;
		delete[] adult;
		delete[] baby;
		delete[] student;
		delete payment;
	}

	Reservation& operator = (const Reservation& obj) {
		hotel = obj.hotel;
		camp = obj.camp;
		daily = obj.daily;
		elder = obj.elder;
		adult = obj.adult;
		baby = obj.baby;
		student = obj.student;
		payment = obj.payment;

		return *this;
	}


	friend std::ostream& operator << (std::ostream& os, const Reservation& obj) {
		int i = 0; 
		int customerAmount = 0;

		std::cout << "----------RESERVATION INFORMATION----------" << std::endl << std::endl;

		if (obj.hotel->getHotelName() != "") {
			os << "Vacation Type: Hotel" << std::endl
				<< "Season: " << obj.hotel->getSeason() << std::endl
				<< "Customer Amount: " << obj.hotel->getCustomerAmount() << std::endl
				<< "Starting Date: " << obj.hotel->getStartingDate() << std::endl
				<< "Final Date: " << obj.hotel->getFinalDate() << std::endl
				<< "Day: " << obj.hotel->getDayAmount() << std::endl << std::endl << std::endl

				<< "---Hotel Information---" << std::endl
				<< "Hotel Place: " << obj.hotel->getPlace() << std::endl
				<< "Hotel Name: " << obj.hotel->getHotelName() << std::endl
				<< "Hotel Type: " << obj.hotel->getHotelType() << std::endl
				<< "Hotel Price (Total): " << obj.hotel->getTotalPrice() << std::endl;

			customerAmount = obj.hotel->getCustomerAmount();

		}

		else if (obj.camp->getTentType() != "") {
			os << "Vacation Type: Camp"
				<< "Season: " << obj.camp->getSeason() << std::endl
				<< "Customer Amount: " << obj.camp->getCustomerAmount() << std::endl
				<< "Starting Date: " << obj.camp->getStartingDate() << std::endl
				<< "Final Date: " << obj.camp->getFinalDate() << std::endl
				<< "Day: " << obj.camp->getDayAmount() << std::endl << std::endl << std::endl

				<< "---Camp Information---" << std::endl
				<< "Camp Place: " << obj.camp->getPlace() << std::endl
				<< "Tent Type: " << obj.camp->getTentType() << std::endl
				<< "Tent Capacity: " << obj.camp->getTentCapacity() << std::endl
				<< "Camp Price (Total): " << obj.camp->getTotalPrice();

			customerAmount = obj.camp->getCustomerAmount();
		}

		else if (obj.daily->getPlace() != "") {
			os << "Vacation Type: Daily Trip\n"
				<< "Season: " << obj.daily->getSeason() << std::endl
				<< "Customer Amount: " << obj.daily->getCustomerAmount() << std::endl
				<< "Date: " << obj.daily->getStartingDate() << std::endl

				<< "---Daily Trip Information---" << std::endl
				<< "Daily Trip Place: " << obj.daily->getPlace() << std::endl
				<< "Daily Trip Price (Total): " << obj.daily->getTotalPrice();
			customerAmount = obj.daily->getCustomerAmount();
		}
		
		std::cout << std::endl << std::endl << "---Customers Information--- " << std::endl << std::endl;
		
		int j = 0;
			while (obj.elder[j].getName() != "" && j < customerAmount) {
				os << "Customer " << ++i << ":" << std::endl
					<< "Customer Name: " << obj.elder[j].getName() << std::endl
					<< "Birthdate: " << obj.elder[j].getDate() << std::endl
					<< "Customer ID: " << obj.elder[j].getID() << std::endl
					<< "Customer Gender: " << obj.elder[j].getSex() << std::endl
					<< "Customer Mail:  " << obj.elder[j].getMail() << std::endl << std::endl;
				j++;
			}

			j = 0;
			while (obj.adult[j].getName() != "" && j < customerAmount) {
				os << "Customer " << ++i << ":" << std::endl
					<< "Customer Name: " << obj.adult[j].getName() << std::endl
					<< "Birthdate: " << obj.adult[j].getDate() << std::endl
					<< "Customer ID: " << obj.adult[j].getID() << std::endl
					<< "Customer Gender: " << obj.adult[j].getSex() << std::endl
					<< "Customer Mail:  " << obj.adult[j].getMail() << std::endl << std::endl;
				j++;
			}

			j = 0;
			while (obj.student[j].getName() != "" && j < customerAmount) {
				os << "Customer " << ++i << ":" << std::endl
					<< "Customer Name: " << obj.student[j].getName() << std::endl
					<< "Birthdate: " << obj.student[j].getDate() << std::endl
					<< "Customer ID: " << obj.student[j].getID() << std::endl
					<< "Customer Gender: " << obj.student[j].getSex() << std::endl
					<< "Customer Mail:  " << obj.student[j].getMail() << std::endl << std::endl;
				j++;
			}

			j = 0;
			while (obj.baby[j].getName() != "" && j < customerAmount) {
				os << "Customer " << ++i << ":" << std::endl
					<< "Customer Name: " << obj.baby[j].getName() << std::endl
					<< "Birthdate: " << obj.baby[j].getDate() << std::endl
					<< "Customer ID: " << obj.baby[j].getID() << std::endl
					<< "Customer Gender: " << obj.baby[j].getSex() << std::endl << std::endl;
				j++;
			}
		
		
		return (os);
	}

};


#endif // !_RESERVATION_H_
