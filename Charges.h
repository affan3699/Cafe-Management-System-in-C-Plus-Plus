#ifndef CHARGES_H
#define CHARGES_H

class Charges
{
		friend std::istream& operator >>(std::istream &in, Charges& c1); // taking new charges

	public:

		Charges(); //DEFAULT CONSTRUCTOR
		virtual ~Charges(); //virtual DECONSTRUCTOR to avoid memory leak
		virtual void calculateCharges();

	protected:

		unsigned int charges, minutes;
		static float rate; // static function to calculate rate of browsing
};
#endif