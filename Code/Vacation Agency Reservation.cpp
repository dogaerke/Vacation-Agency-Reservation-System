#include <iostream>
#include <vector>
#include <fstream>
#include "VacationTypes.h"
#include "Hotel.h"
#include "Camp.h"
#include "Reservation.h"
#include "Customer.h"

using namespace std;

vector <Hotel> hotelVec;
vector <Camp> campVec;
vector <DailyTrip> dailyVec;

void addHotels();
void addCamp();
void addDailyTrip();
void controlDate(int* day, int* month, int* year);


int main(void) {

	int seasonChoice{ 0 };
	int vacationTypeChoice{ 0 };
	int choiceNumber{ 0 };
	int index{ -1 };
	int customerAmount = 0;

	string hotelName{ "" };
	string season{ "" };
	string campPlace{ "" };
	string dailyPlace{ "" };
	string typeChosen{ "" };

	Hotel hotelChoiced;
	Camp campChoiced;
	DailyTrip dailyChoiced;

	bool control = 0;

	addHotels();
	addCamp();
	addDailyTrip();

	cout << "\t\t\t\t\t\tWELCOME TO UDO VACATION AGENCY" << endl << endl;

	do
	{
		cout << endl << "Choose a vacation type you want to book:\n1.Hotel\n2.Camp\n3.Daily Trip\nChoice: ";
		cin >> vacationTypeChoice;
	} while (vacationTypeChoice < 1 || vacationTypeChoice > 3);

	do {
		cout << endl << "Choose season\n1.Winter\n2.Summer\n3.Spring\nChoice: ";
		cin >> seasonChoice;
	} while (seasonChoice < 1 || seasonChoice > 3);

	cout << endl << "We will book vacation for how many person? ";
	cin >> customerAmount;

	Reservation reservation;

	switch (vacationTypeChoice)
	{
	case 1://Hotels
	{
		typeChosen = "Hotel";
		int d{ 0 }, m{ 0 }, y{ 0 };

		cout << endl << "Please enter starting date(e.g. 01 01 2022): ";
		controlDate(&d, &m, &y);
		Date dateS(d, m, y);
		hotelChoiced.setStartingDate(dateS);

		cout << endl << "Please enter final date(e.g. 01 01 2022): ";
		controlDate(&d, &m, &y);
		Date dateF(d, m, y);
		hotelChoiced.setFinalDate(dateF);

		Date result = dateS - dateF;
		if (result.getMonth() != 0)
			result.setDay(result.getDay() + 30 * result.getMonth());
		hotelChoiced.setDayAmount(result.getDay());

		switch (seasonChoice)
		{
		case 1:	//Hotel Winter
			for (int i = 0; i < hotelVec.size(); i++)
				if (hotelVec.at(i).getSeason() == "Winter") {
					cout << endl << choiceNumber + 1 << "." << "Hotel Place: " << hotelVec.at(i).getPlace() << "\nHotel name: " << hotelVec.at(i).getHotelName()
						<< "\nHotel type: " << hotelVec.at(i).getHotelType() << "\nHotel Price(Daily): " << hotelVec.at(i).getPrice() << endl << endl;
					choiceNumber++;
				}
			do
			{
				cout << endl << "Enter name of the hotel that you want to book: ";
				cin >> hotelName;
				control = 0;
				index = -1;

				for (int i = 0; i < hotelVec.size(); i++)
					if (hotelName == hotelVec.at(i).getHotelName())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			hotelChoiced.operator= (hotelVec.at(index));
			hotelChoiced.setCustomerAmount(customerAmount);
			hotelChoiced.setPrice(hotelChoiced.getPrice() * hotelChoiced.getDayAmount());
			*reservation.hotel = hotelChoiced;

			reservation.hotel->setCustomerAmount(hotelChoiced.getCustomerAmount());
			reservation.hotel->setDayAmount(hotelChoiced.getDayAmount());
			reservation.hotel->setStartingDate(hotelChoiced.getStartingDate());
			reservation.hotel->setFinalDate(hotelChoiced.getFinalDate());


			break;

		case 2://Hotel Summer
			for (int i = 0; i < hotelVec.size(); i++)
				if (hotelVec.at(i).getSeason() == "Summer") {
					cout << endl << choiceNumber + 1 << "." << "Hotel Place: " << hotelVec.at(i).getPlace() << "\nHotel name: " << hotelVec.at(i).getHotelName()
						<< "\nHotel type: " << hotelVec.at(i).getHotelType() << "\nHotel Price(Daily): " << hotelVec.at(i).getPrice() << endl << endl;
					choiceNumber++;
				}
			do
			{
				cout << endl << "Enter name of the hotel that you want to book: ";
				cin >> hotelName;
				control = 0;
				index = -1;

				for (int i = 0; i < hotelVec.size(); i++)
					if (hotelName == hotelVec.at(i).getHotelName())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			hotelChoiced = hotelVec.at(index);
			hotelChoiced.setCustomerAmount(customerAmount);
			hotelChoiced.setPrice(hotelChoiced.getPrice() * hotelChoiced.getDayAmount());
			*reservation.hotel = hotelChoiced;

			reservation.hotel->setCustomerAmount(hotelChoiced.getCustomerAmount());
			reservation.hotel->setDayAmount(hotelChoiced.getDayAmount());
			reservation.hotel->setStartingDate(hotelChoiced.getStartingDate());
			reservation.hotel->setFinalDate(hotelChoiced.getFinalDate());

			break;
		case 3://Hotel Spring
			for (int i = 0; i < hotelVec.size(); i++)
				if (hotelVec.at(i).getSeason() == "Spring") {
					cout << endl << choiceNumber + 1 << "." << "Hotel Place: " << hotelVec.at(i).getPlace() << "\nHotel name: " << hotelVec.at(i).getHotelName()
						<< "\nHotel type: " << hotelVec.at(i).getHotelType() << "\nHotel Price(Daily): " << hotelVec.at(i).getPrice() << endl << endl;
					choiceNumber++;
				}
			do
			{
				cout << endl << "Enter name of the hotel that you want to book: ";
				cin >> hotelName;
				control = 0;
				index = -1;

				for (int i = 0; i < hotelVec.size(); i++)
					if (hotelName == hotelVec.at(i).getHotelName())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			hotelChoiced = hotelVec.at(index);
			hotelChoiced.setCustomerAmount(customerAmount);
			hotelChoiced.setPrice(hotelChoiced.getPrice() * hotelChoiced.getDayAmount());
			*reservation.hotel = hotelChoiced;

			reservation.hotel->setCustomerAmount(hotelChoiced.getCustomerAmount());
			reservation.hotel->setDayAmount(hotelChoiced.getDayAmount());
			reservation.hotel->setStartingDate(hotelChoiced.getStartingDate());
			reservation.hotel->setFinalDate(hotelChoiced.getFinalDate());
			break;
		default:
			break;
		}
		break;

	}

	case 2:	//Camps
	{
		typeChosen = "Camp";
		int d{ 0 }, m{ 0 }, y{ 0 };

		cout << endl << "Please enter starting date(e.g. 01 01 2022): ";
		controlDate(&d, &m, &y);
		Date dateS(d, m, y);
		campChoiced.setStartingDate(dateS);

		cout << endl << "Please enter final date(e.g. 01 01 2022): ";
		controlDate(&d, &m, &y);
		Date dateF(d, m, y);
		campChoiced.setFinalDate(dateF);

		Date result = dateS - dateF;

		if (result.getMonth() != 0)
			result.setDay(result.getDay() + 30 * result.getMonth());
		campChoiced.setDayAmount(result.getDay());

		switch (seasonChoice)
		{

		case 1://Camp Winter
			for (int i = 0; i < campVec.size(); i++)
				if (campVec.at(i).getSeason() == "Winter") {
					cout << endl << endl << choiceNumber + 1 << "." << "Camp Place: " << campVec.at(i).getPlace() << endl << endl;
					choiceNumber++;
				}
			do
			{
				cout << endl << "Enter the place name of the camp that you want to book: ";
				cin >> campPlace;
				control = 0;
				index = -1;
				for (int i = 0; i < campVec.size(); i++)
					if (campPlace == campVec.at(i).getPlace())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			campChoiced = campVec.at(index);
			campChoiced.setCustomerAmount(customerAmount);
			campChoiced.chooseTypeAndCapacity();
			*reservation.camp = campChoiced;

			reservation.camp->setCustomerAmount(campChoiced.getCustomerAmount());
			reservation.camp->setDayAmount(campChoiced.getDayAmount());
			reservation.camp->setStartingDate(campChoiced.getStartingDate());
			reservation.camp->setFinalDate(campChoiced.getFinalDate());
			reservation.camp->setTentCapacity(campChoiced.getTentCapacity());
			reservation.camp->setTentType(campChoiced.getTentType());
			reservation.camp->setTotalPrice(campChoiced.getTotalPrice());

			break;
		case 2://Camp Summer
			for (int i = 0; i < campVec.size(); i++)
				if (campVec.at(i).getSeason() == "Summer") {
					cout << endl << endl << choiceNumber + 1 << "." << "Camp Place: " << campVec.at(i).getPlace();
					choiceNumber++;
				}
			do
			{
				cout << endl << "Enter the place name of the camp that you want to book: ";
				cin >> campPlace;
				control = 0;
				index = -1;
				for (int i = 0; i < campVec.size(); i++)
					if (campPlace == campVec.at(i).getPlace())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			campChoiced = campVec.at(index);
			campChoiced.setCustomerAmount(customerAmount);
			campChoiced.chooseTypeAndCapacity();
			*reservation.camp = campChoiced;

			reservation.camp->setCustomerAmount(campChoiced.getCustomerAmount());
			reservation.camp->setDayAmount(campChoiced.getDayAmount());
			reservation.camp->setStartingDate(campChoiced.getStartingDate());
			reservation.camp->setFinalDate(campChoiced.getFinalDate());
			reservation.camp->setTentCapacity(campChoiced.getTentCapacity());
			reservation.camp->setTentType(campChoiced.getTentType());
			reservation.camp->setTotalPrice(campChoiced.getTotalPrice());

			break;
		case 3://Camp Spring
			for (int i = 0; i < campVec.size(); i++)
				if (campVec.at(i).getSeason() == "Spring") {
					cout << endl << endl << choiceNumber + 1 << "." << "Camp Place: " << campVec.at(i).getPlace();
					choiceNumber++;
				}
			do
			{
				cout << endl << "Enter the place name of the camp that you want to book: ";
				cin >> campPlace;
				control = 0;
				index = -1;
				for (int i = 0; i < campVec.size(); i++)
					if (campPlace == campVec.at(i).getPlace())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			campChoiced = campVec.at(index);
			campChoiced.setCustomerAmount(customerAmount);
			campChoiced.chooseTypeAndCapacity();
			*reservation.camp = campChoiced;

			reservation.camp->setCustomerAmount(campChoiced.getCustomerAmount());
			reservation.camp->setDayAmount(campChoiced.getDayAmount());
			reservation.camp->setStartingDate(campChoiced.getStartingDate());
			reservation.camp->setFinalDate(campChoiced.getFinalDate());
			reservation.camp->setTentCapacity(campChoiced.getTentCapacity());
			reservation.camp->setTentType(campChoiced.getTentType());
			reservation.camp->setTotalPrice(campChoiced.getTotalPrice());

			break;
		default:
			break;
		}
		break;
	}

	case 3://Daily Trip
		typeChosen = "Daily";

		int d{ 0 }, m{ 0 }, y{ 0 };

		cout << endl << "Please enter date(e.g. 01 01 2022): ";
		controlDate(&d, &m, &y);
		Date dateS(d, m, y);
		

		switch (seasonChoice)
		{
		case 1: //Daily Winter 
			for (int i = 0; i < dailyVec.size(); i++)
				if (dailyVec.at(i).getSeason() == "Winter") {
					cout << endl << endl << choiceNumber + 1 << "." << "Daily Trip Place: " << dailyVec.at(i).getPlace() << " " << dailyVec.at(i).getPrice() << endl;
					choiceNumber++;
				}

			do
			{
				cout << endl << "Enter the place name of the daily trip that you want to book: ";
				cin >> dailyPlace;
				control = 0;
				index = -1;
				for (int i = 0; i < dailyVec.size(); i++)
					if (dailyPlace == dailyVec.at(i).getPlace())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			dailyChoiced = dailyVec.at(index);
			dailyChoiced.setStartingDate(dateS);
			dailyChoiced.setCustomerAmount(customerAmount);
			*reservation.daily = dailyChoiced;
			break;

		case 2: //Daily Summer
			for (int i = 0; i < dailyVec.size(); i++)
				if (dailyVec.at(i).getSeason() == "Summer") {
					cout << endl << endl << choiceNumber + 1 << "." << "Daily Trip Place: " << dailyVec.at(i).getPlace() << " " << dailyVec.at(i).getPrice() << endl;
					choiceNumber++;
				}

			do
			{
				cout << endl << "Enter the place name of the daily trip that you want to book: ";
				cin >> dailyPlace;
				control = 0;
				index = -1;
				for (int i = 0; i < dailyVec.size(); i++)
					if (dailyPlace == dailyVec.at(i).getPlace())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			dailyChoiced = dailyVec.at(index);
			dailyChoiced.setStartingDate(dateS);
			dailyChoiced.setCustomerAmount(customerAmount);
			*reservation.daily = dailyChoiced;
			break;

		case 3: //Daily Spring
			for (int i = 0; i < dailyVec.size(); i++)
				if (dailyVec.at(i).getSeason() == "Spring") {
					cout << endl << endl << choiceNumber + 1 << "." << "Daily Trip Place: " << dailyVec.at(i).getPlace() << " " << dailyVec.at(i).getPrice() << endl;
					choiceNumber++;
				}

			do
			{
				cout << endl << "Enter the place name of the daily trip that you want to book: ";
				cin >> dailyPlace;
				control = 0;
				index = -1;
				for (int i = 0; i < dailyVec.size(); i++)
					if (dailyPlace == dailyVec.at(i).getPlace())
						index = i;

				if (index == -1)
				{
					cout << "Invalid Name!!!" << endl;
					control = 1;
				}

			} while (control);

			dailyChoiced = dailyVec.at(index);
			dailyChoiced.setStartingDate(dateS);
			dailyChoiced.setCustomerAmount(customerAmount);
			*reservation.daily = dailyChoiced;


			break;

		default:
			break;
		}
	}

		long long int id = 0;
		string name = "";
		string gender = "";
		string mail = "";
		int day = 0;
		int month = 0;
		int year = 0;
		Date birthDate;
		Date defaultDate(1, 1, 2022);
		int baby_index = 0;
		int student_index = 0;
		int adult_index = 0;
		int elder_index = 0;
		float calculateTotalPrice = 0.0;

		cout << endl << "Your vacation plan is adjusted. " << endl << endl;

		for (int i = 0; i < customerAmount; i++) {
			cout << endl << "Please enter personal information of " << i + 1 << ". member: " << endl;

			cout << endl << "1. Birthdate: ";
			
			do {
				try {
					cin >> day >> month >> year;
					if (day < 1 || day > 30)
						throw - 1;

					else if (month < 1 || month > 12)
						throw - 1;
					else if(year < 1900 || year >2022)
						throw - 1;
				}
				catch (int& d) {
					cerr << "Invalid date value!" << endl << "Please enter again: ";
				}

				catch (...) {
					cerr << "Default Error!";
				}

			} while ((year < 1900 || year >2022) || (month < 1 || month > 12) || (day < 1 || day > 30));

			birthDate.setDay(day);
			birthDate.setMonth(month);
			birthDate.setYear(year);

			Date* age = new Date;
			*age = birthDate - defaultDate;
			if (age->getYear() > 0 && age->getYear() < 7) {
				Customer* person = new Baby;

				if (typeChosen == "Hotel")
					calculateTotalPrice += reservation.hotel->getPrice() * person->discount(); //Abstract method is called.
				else if (typeChosen == "Daily")
					calculateTotalPrice += reservation.daily->getPrice() * person->discount();


				person->setDate(birthDate);

				cout << "2. Full Name: ";

				cin.ignore();
				getline(cin, name);
				person->setName(name);

				cout << "3. ID: ";
				do {
					cin >> id;

					if (id < 10000000000 || id > 99999999999)
						cout << "Invalid Value! Please enter again: ";

				} while (id < 10000000000 || id > 99999999999);
				person->setID(id);

				do {
					cout << "4. Gender (Male/ Female): ";
					cin >> gender;

					if (gender != "Male" && gender != "Female")
						cout << "Invalid Value! Please enter again: ";

				} while (gender != "Male" && gender != "Female");

				person->setSex(gender);

				reservation.baby[baby_index++] = *person;

				delete person;
			}

			else if (age->getYear() >= 7 && age->getYear() < 18) {
				Customer* person = new Student;

				if (typeChosen == "Hotel")
					calculateTotalPrice += reservation.hotel->getPrice() * person->discount(); //Abstract method is called.
				else if (typeChosen == "Daily")
					calculateTotalPrice += reservation.daily->getPrice() * person->discount();

				person->setDate(birthDate);

				cout << "2. Full Name: ";

				cin.ignore();
				getline(cin, name);
				person->setName(name);

				cout << "3. ID: ";
				do {
					cin >> id;

					if (id < 10000000000 || id > 99999999999)
						cout << "Invalid Value! Please enter again: ";

				} while (id < 10000000000 || id > 99999999999);
				person->setID(id);

				do {
					cout << "4. Gender (Male/ Female): ";
					cin >> gender;

					if (gender != "Male" && gender != "Female")
						cout << "Invalid Value! Please enter again: ";

				} while (gender != "Male" && gender != "Female");

				person->setSex(gender);

				cout << "5. Mail: ";
				cin >> mail;

				person->setMail(mail);

				reservation.student[student_index++] = *person;
				delete person;
			}


			else if (age->getYear() >= 18 && age->getYear() < 65) {
				Customer* person = new Adult;

				if (typeChosen == "Hotel")
					calculateTotalPrice += reservation.hotel->getPrice() * person->discount(); //Abstract method is called.
				else if (typeChosen == "Daily")
					calculateTotalPrice += reservation.daily->getPrice() * person->discount();

				person->setDate(birthDate);

				cout << "2. Full Name: ";

				cin.ignore();
				getline(cin, name);
				person->setName(name);

				cout << "3. ID: ";
				do {
					cin >> id;

					if (id < 10000000000 || id > 99999999999)
						cout << "Invalid Value! Please enter again: ";

				} while (id < 10000000000 || id > 99999999999);
				person->setID(id);

				do {
					cout << "4. Gender (Male/ Female): ";
					cin >> gender;

					if (gender != "Male" && gender != "Female")
						cout << "Invalid Value! Please enter again: ";

				} while (gender != "Male" && gender != "Female");

				person->setSex(gender);

				cout << "5. Mail: ";
				cin >> mail;

				person->setMail(mail);

				reservation.adult[adult_index++] = *person;
				delete person;
			}

			else {
				Customer* person = new Elder;

				if (typeChosen == "Hotel")
					calculateTotalPrice += reservation.hotel->getPrice() * person->discount(); //Abstract method is called.
				else if (typeChosen == "Daily")
					calculateTotalPrice += reservation.daily->getPrice() * person->discount();

				person->setDate(birthDate);

				cout << "2. Full Name: ";

				cin.ignore();
				getline(cin, name);
				person->setName(name);

				cout << "3. ID: ";
				do {
					cin >> id;

					if (id < 10000000000 || id > 99999999999)
						cout << "Invalid Value! Please enter again: ";

				} while (id < 10000000000 || id > 99999999999);
				person->setID(id);

				do {
					cout << "4. Gender (Male/ Female): ";
					cin >> gender;

					if (gender != "Male" && gender != "Female")
						cout << "Invalid Value! Please enter again: ";

				} while (gender != "Male" && gender != "Female");

				person->setSex(gender);

				cout << "5. Mail: ";
				cin >> mail;

				person->setMail(mail);

				reservation.elder[elder_index++] = *person;
				delete person;

			}
			delete age;
		}
		if (typeChosen == "Hotel")
			reservation.hotel->setTotalPrice(calculateTotalPrice);

		else if (typeChosen == "Daily") {
			reservation.daily->setTotalPrice(calculateTotalPrice);

		}

		cout << reservation;

		long long int card_id{ 0 };
		int password{ 0 };
		char c{ ' ' };

		cout << endl << "Your reservation was booked. \nAfter payment is done, your reservation will be made.";
		cout << "Amount to be paid: ";

		if (typeChosen == "Hotel")
			cout << reservation.hotel->getTotalPrice() << "TL";

		else if (typeChosen == "Daily")
			cout << reservation.daily->getTotalPrice()<< "TL";
		else
			cout << reservation.camp->getTotalPrice() << "TL";


		do {
			cout << endl << "Please enter Card ID: ";

			cin >> card_id;

			reservation.account.setCardId(card_id);

			cout << endl << "Please enter password: ";
			cin >> password;

			reservation.account.setPassword(password);

			cout << "If you want to continue, enter 'y'. \nIf you want to enter Card Information again please enter 'n'";
			do {
				cin >> c;
				if (c != 'n' && c != 'y')
					cout << "Invalid value! Please try again." << endl;
			} while (c != 'n' && c != 'y');
			

		} while (c == 'n');

		cout << "Your payment was done, and reservation was made."
			<< endl << "Detailed information about your reservation will be sent to your mail address."
			<< endl << "We wish you a wonderful holiday...";

		return 0;
}

void addHotels() {
	string season;
	string hotelType;
	string place;
	string hotelName;
	int price = 0;
	ifstream file("hotels.txt");
	while (file >> season >> hotelType >> place >> hotelName >> price) {
		Hotel hotel(season, hotelType, place, hotelName, price);
		hotelVec.push_back(hotel);
	}
}

void addCamp() {
	string season;
	string place;

	ifstream file("camps.txt");
	while (file >> season >> place) {
		Camp camp(season, place);
		campVec.push_back(camp);
	}
}

void addDailyTrip() {
	string season;
	string place;	
	int price;

	ifstream file("dailytrips.txt");
	while (file >> season >> place >> price) {
		DailyTrip daily(season, place, price);
		dailyVec.push_back(daily);
	}
}

void controlDate(int *day, int *month, int *year) {
	do {
		try {
			cin >> *day >> *month >> *year;
			if (*day < 1 || *day > 30)
				throw - 1;

			else if (*month < 1 || *month > 12)
				throw - 1;

			else if (*year != 2022)
				throw - 1;
		}
		catch (int& d) {
			cerr << "Invalid date value!" << endl << "Please enter again: ";
		}

		catch (...) {
			cerr << "Default Error!";
		}

	} while (*year != 2022 || (*month < 1 || *month > 12) || (*day < 1 || *day > 30));
}