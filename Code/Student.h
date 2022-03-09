#ifndef _STUDENT_H_
#define _STUDENT_H_
#include "Customer.h"

class Student : public Customer {
public:
	Student() {

	}

	virtual ~Student() {

	}


	float discount() override {
		return 0.90;
	}
};


#endif
