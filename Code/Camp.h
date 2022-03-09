#ifndef _CAMP_H
#define _CAMP_H
#include <string>
#include <iostream>
#include "VacationTypes.h"

class Camp : public VacationTypes
{
protected:
    std::string tentType;
    int tentCapacity;

public:
    Camp() {
        tentType = "";
        tentCapacity = 0;

    }

    Camp(std::string season, std::string place) {
        this->season = season;
        this->place = place;
    }
    ~Camp() {}

    Camp& operator = (const Camp& obj) {
        place = obj.place;
        season = obj.season;
        return *this;
    }

    std::string getTentType() { return tentType;}
    void setTentType(std::string type) { tentType = type;}

    int getTentCapacity() { return tentCapacity; }
    void setTentCapacity(int capacity) { tentCapacity = capacity; }

    void chooseTypeAndCapacity()
    {
        int choice{ 0 };
        int capacity{ 0 };


        do {
            std::cout << std::endl << std::endl << "Tent Types\n1. Simple(200 TL)\n2. Advanced(500 TL)\n3. Professional(800 TL)\nPlease enter the tent type: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                tentType = "Simple";
                totalPrice += 200;
                break;
            case 2:
                tentType = "Advanced";
                totalPrice += 500;
                break;
            case 3:
                tentType = "Professional";
                totalPrice += 800;
                break;

            default:
                std::cout << "Invalid type!";
                break;
            }
        } while (choice < 0 || choice>3);

        do {

            std::cout << std::endl << std::endl << "1 Man -> 20 TL" << std::endl
                << "2 Man -> 40 TL" << std::endl
                << "3 Man -> 60 TL" << std::endl
                << "4 Man -> 80 TL" << std::endl
                << "Please enter the capacity of your tent(1-4): ";
            std::cin >> capacity;

            switch (capacity) {
            case 1:
                tentCapacity = 1;
                totalPrice += 20;
                break;
            case 2:
                tentCapacity = 2;
                totalPrice += 40;
                break;
            case 3:
                tentCapacity = 3;
                totalPrice += 60;
                break;
            case 4:
                tentCapacity = 4;
                totalPrice += 80;
                break;
            default:
                std::cout << "Invalid number!";
                break;
            }
        } while (capacity < 0 || capacity>4);

    }
};
#endif