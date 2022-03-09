#ifndef _ADULT_H_
#define _ADULT_H_
#include "Customer.h"

class Adult : public Customer {
public:
	Adult() {

	}

	virtual ~Adult() {

	}

	
	float discount() override {
		return 1;
	}

};
#endif