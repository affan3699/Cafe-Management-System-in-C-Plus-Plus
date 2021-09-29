#include <iostream>
#include "ComputerCharges.h"

ComputerCharges :: ComputerCharges(){} //DEFAULT CONSTRUCTOR

ComputerCharges :: ~ComputerCharges(){} //DEFAULT DECONSTRUCTOR

void ComputerCharges :: calculateCharges() // FUNCTION TO CALCULATE CHARGES AND DISPLAY IN CHANGES RETURNED
{
	std::cout<<"ComputerCharges Called"<<std::endl;
	unsigned int netCharges = 0, change = 0, rs1000 = 0, rs500 = 0, rs100 = 0, rs50 = 0, rs10 = 0, rs05 = 0, rs02 = 0, rs01 = 0, totalNumberOfRupeeNotes = 0;

	//std::cout<<"Total = "<<netCharges<<std::endl;

	std::cout<<std::endl<<"\t\t Enter Amount: ";
	std::cin>>charges;

	while(charges < netCharges)
	{
		std::cout<<std::endl<<"\t\tAmount less than total bill"<<std::endl;
		std::cout<<std::endl<<"\t\tEnter Amount Again: ";
		std::cin>>charges;
	}

	change = charges - netCharges;

    rs1000 = change / 1000;
    change = change % 1000;

    rs500 = change / 500;
    change = change % 500;

    rs100 = change / 100;
    change = change % 100;

    rs50 = change / 50;
    change = change % 50;

    rs10 = change / 10;
    change = change % 10;

    rs05 = change / 5;
    change = change % 5;

    rs02 = change / 2;
    change = change % 2;

    rs01 = change / 1;
    change = change % 1;

    totalNumberOfRupeeNotes = rs01 + rs02 + rs05 + rs10 + rs50 + rs100 + rs500 + rs1000;

    std::cout<<std::endl<<"Rs 1 Notes :  "<<rs01;
    std::cout<<std::endl<<"Rs 2 Notes :  "<<rs02;
    std::cout<<std::endl<<"Rs 5 Notes :  "<<rs05;
    std::cout<<std::endl<<"Rs 10 Notes :  "<<rs10;
    std::cout<<std::endl<<"Rs 50 Notes :  "<<rs50;
    std::cout<<std::endl<<"Rs 100 Notes :  "<<rs100;
    std::cout<<std::endl<<"Rs 500 Notes :  "<<rs500;
    std::cout<<std::endl<<"Rs 1000 Notes :  "<<rs1000;
    std::cout<<std::endl<<"Total Notes : "<<totalNumberOfRupeeNotes<<std::endl<<std::endl;

    system("pause");
}