#ifndef _ELDER_H_
#define _ELDER_H_
#include "VacationTypes.h"
#include "Customer.h"

class Elder : public Customer{
public:
	Elder() {

	}

	virtual ~Elder() {

	}


	float discount() override {
		return 0.85;
	}

};


#endif