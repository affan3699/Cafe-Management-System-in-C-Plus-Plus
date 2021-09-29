#ifndef COMPUTERCHARGES_H
#define COMPUTERCHARGES_H
#include "Charges.h" // INHERITING FROM CHARGES CLASS

class ComputerCharges: public Charges 
{
	public:

		ComputerCharges(); //DEFAULT CONSTRUCTOR
		~ComputerCharges(); //DEFAULT DECONSTRUCTOR 

		virtual void calculateCharges() override; //POLYMORPHISM

};
#endif