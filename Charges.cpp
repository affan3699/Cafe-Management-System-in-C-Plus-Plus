#include <iostream>
//#define rate 1.3333
#include "Charges.h"


Charges::Charges(): charges(0), minutes(0){} //DEFAULT DECONSTRUCTOR

Charges::~Charges(){} //DEFAULT DECONSTRUCTOR

std::istream& operator>>(std::istream &in, Charges& c1)
{
	std::cout<<std::endl<<"\t\t Enter Duration In Minutes: ";
	in>>c1.minutes;

	return in;
}

void Charges::calculateCharges(){}

float Charges :: rate{1.333};