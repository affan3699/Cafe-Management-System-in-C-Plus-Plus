#ifndef USERCHARGES_H
#define USERCHARGES_H
#include "Charges.h" // INHERITING FROM CHARGES CLASS

class UserCharges: public Charges
{
		friend std::istream& operator >>(std::istream &in, UserCharges& c1); //OVERLOADING EXTRACTION OPERATOR TO take new charges

	public:

		UserCharges(); //DEFAULT CONSTRUCTOR
		~UserCharges(); //DEFAULT DECONSTRUCTOR

		virtual void calculateCharges() override; //POLYMORPHISM
};
#endif