#ifndef _PAYMENT_H_
#define _PAYMENT_H_

class Payment {
private:
	long long int cardId;
	int password;

public:
	Payment() {
		cardId = 0;
		password = 0;
	}
	~Payment(){}

	Payment(const Payment& obj) {
		cardId = obj.cardId;
		password = obj.password;
	}

	Payment& operator = (const Payment& obj) {
		cardId = obj.cardId;
		password = obj.password;
		return *this;
	}

	long long int getCardId() { return cardId; }
	void setCardId(long long int id) { cardId = id; }

	int getPassword() { return password; }
	void setPassword(int p) { password = p; }
};
#endif // !_PAYMENT_H_
