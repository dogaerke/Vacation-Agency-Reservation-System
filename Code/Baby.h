#ifndef _BABY_H_
#define _BABY_H_

#include "Customer.h"
#include "VacationTypes.h"

class Baby : public Customer{
public:
	Baby() {
		
	}

	virtual ~Baby() {

	}


	float discount() override {
		return 0;
	}

};


#endif
