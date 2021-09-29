//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <iostream>
#include <fstream> // standard library for istream and ostream (Filing)
#include <memory> // for smart ptr
#include <windows.h> //USED FOR SLEEP
#include <stdlib.h>
#include <conio.h> // Holds getch
#include <string>
#include <iomanip> // for setw() FUNCTION
#include "Login.h"
#include "Cafe.h"
#include "Computer.h"
#include "ComputerCharges.h"
#include "UserCharges.h"

//***************************************************************
//    				Function Declarations
//***************************************************************

void loading();
void login();
void mainMenu();
void ComputerMenu();
void memberMenu();
void subMenu();
void subMenu2();
void chargesMenu();
void infoMenu();

//***************************************************************
//    				MAIN FUNCTION
//***************************************************************

int main()
{
	system("color 0e"); // Changes color of CMD text to peach
	login(); //AFTER LOGIN IS CALLED MAIN MENU IS CALLED

	do
	{
		system("cls");
		mainMenu();

	}while(1); // Do While (true) loop TO RUN INFINITE TIMES

	return 0;
}

//***************************************************************
//    				Functions Defination
//***************************************************************

void loading() //LOADING SCREEN USER DEFINED FUNCTION
{
	system("cls");
    for(int i=1;i<=50;i++)
    {
    	system("cls");
  		std::cout<<"\n\n\n\n\t\t\t\t   Loading "<<'\n'<<'\t'<<'\t';

 		for(int j=1;j<=i;j++)
		{
 			std::cout<<(char)219; //PRINTS BOXES ON CMD USING ITS ASCII
 		}
  
  		std::cout<<std::endl<<std::endl<<"\t "<<2*i<<"%"; 

 		if(i>1 && i<20)
 		{
 			std::cout<<"\n\n\tCreating Temporary files";
 		}
  		
 		else if(i > 20 && i< 40)
 		{
 			std::cout<<"\n\n\tAccessing Main Memory";
 		}
  		
 		else if(i > 40 && i< 48)
 		{
 			std::cout<<std::endl<<std::endl<<"\tAccessing Cache";
 		}
  		
 		else
 		{
 			std::cout<<"\n\n\tComplete. Press Enter to Continue ";
 		}

 		Sleep(150 - i * 3); //SLEEP FUNCTION DEFINED IN WINDOWS.H
     }

 	getch();

}

void ComputerMenu()
{
	std::unique_ptr<Computer> c1(new Computer()); //DYNAMIC OBJECT CREATION THROUGH SMART (UNIQUE POINTER) // NO MEMORY LEAK WILL OCCUR IT WILL DELETE IT SELF
	int ID = 0;
	std::string option = " ";

	do
	{
		system("cls");
		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** COMPUTER MENU***           "<<std::endl;
		std::cout<<std::endl<<std::endl<<"\t\t\t***     01. ADD COMPUTER                ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     02. VIEWALLCOMPUTERS            ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     03. UPDATECOMPUTER              ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     04. DELETECOMPUTER              ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     05. SEARCHCOMPUTER              ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     06. GO BACK                     ***"<<std::endl;
		std::cout<<"    \t\t\t*******************************************"<<std::endl;
		std::cout<<"    \t\t\t*******************************************"<<std::endl;                      
		std::cout<<std::endl<<std::endl<<"\tSelect Your Option (1-6): ";
		std::cin>>option;

		if (option == "01" || option == "1")
		{
			std::cin>>*c1; //INPUT OBJECT VALUES BY STREAM OVERLOADING 
			c1->addComputer(); // FUNCTION DECLARED IN COMPUTER CLASS
		}
		else if (option == "02" || option == "2")
		{
			c1->readComputers(*c1); // FUNCTION DECLARED IN COMPUTER CLASS
		}
		else if (option == "03" || option == "3")
		{
			std::cout<<"\t\t\tEnter ID To Update: ";
			std::cin>>ID;
			c1->updateComputer(ID, *c1); // FUNCTION DECLARED IN COMPUTER CLASS
		}
		else if (option == "04" || option == "4")
		{
			std::cout<<"\t\t\tEnter ID To Update: ";
			std::cin>>ID;
			c1->deleteComputer(ID); // FUNCTION DECLARED IN COMPUTER CLASS
		}
		else if (option == "05" || option == "5")
		{
			std::cout<<"\t\t\tEnter ID To Serach: ";
			std::cin>>ID;
			c1->searchComputer(ID); // FUNCTION DECLARED IN COMPUTER CLASS
		}
		else if (option == "06" || option == "6")
		{
			subMenu(); // FUNCTION TO NAVIGATE BACK AND FOURTH
		}
		else // VALIDATION 
		{
	        std::cout<<std::endl<<"Invalid Input !"<<std::endl;
	        system("PAUSE");
	        system("cls");
	        std::cout<<std::endl;
		}

	}while(1);
	
}

void login() // User Defined function to Verify Credentials to login
{
	system("color 0e"); // Change color OF cmd color to peach
	system("cls");
	Login l1("affan", "affan"); // Passing id and password as Object Parameters
	std::string userName = " ", passWord = " ";
	std::string yesORno = " " ;

	std::cout<<std::endl<<"\t\t\t========================  LOGIN   ========================  ";
    std::cout<<std::endl<<"\t\t\t            USERNAME:-";
    std::cin>>userName;
    std::cout<<std::endl<<"\t\t\t            PASSWORD:-";
    std::cin>>passWord;

	if(l1.getUser() == userName && l1.getPass() == passWord) // GET ID AND PASSWORD IF BOTH ARE RIGHT 
	{
		loading(); // USER DEFINED FUNCTION.
	}

	else
	{
		std::cout<<std::endl<<"Username or Password Incorrect."<<std::endl; // VALIDATION
     	REENTER:
        std::cout<<"Do you want to re-enter? (y/n): ";
        std::cin>>yesORno;
        if(yesORno == "y" || yesORno == "Y")
        {
            system("cls");
            login();
        }

        else if(yesORno == "n" || yesORno == "N")
        {
            std::cout<<std::endl<<"Thank you so much for visiting us !";
            std::cout<<std::endl<<"Program Will Terminate.."<<std::endl<<std::endl;
            getch();
            exit(0);
        }
        else
        {
        	std::cout<<std::endl<<"Invalid Input !"<<std::endl;
        	system("PAUSE");
        	system("cls");
        	std::cout<<std::endl;
        	goto REENTER;

        }
	}
}

void mainMenu() // USER DEFINED FUNCTION SHOWS MAIN MENU OF PROGRAM
{
	// CASE CONDITIONS NOT-USED (limitation with switch case is that they work on char and cannot more than 1 character )
	Mainmenu:
	// char option = '0'; 
	std::string option; // USED STRING AS INPUT SO THAT VALIDATION CAN BE DONE. 
	system("cls");
	std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** CAFE MANAGEMENT SYSTEM***           "<<std::endl;
	std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** MAIN MENU***           "<<std::endl;
	std::cout<<std::endl<<std::endl<<"\t\t\t***     01. CAFE MANAGEMENT             ***";
	std::cout<<std::endl<<std::endl<<"\t\t\t***     02. CAFE BILLING          	***";
	std::cout<<std::endl<<std::endl<<"\t\t\t***     03. CAFE INFO                   ***";
	std::cout<<std::endl<<std::endl<<"\t\t\t***     04. EXIT                        ***";
	std::cout<<std::endl<<std::endl<<"\tSelect Your Option (1-4): ";
	std::cin>>option;

	if (option == "01" || option == "1")
	{
		subMenu(); // FUNCTION DEFINED IN MAIN 
	}
	else if (option == "02" || option == "2")
	{
		subMenu2(); // FUNCTION DEFINED IN MAIN 
	}
	else if (option == "03" || option == "3")
	{
		infoMenu(); // TERMINATES THE PROGRAM
	}
	else if (option == "04" || option == "4")
	{
		exit(0); // TERMINATES THE PROGRAM
	}
	else // VALIDATION 
	{
        	std::cout<<std::endl<<"Invalid Input !"<<std::endl;
        	system("PAUSE");
        	system("cls");
        	std::cout<<std::endl;
        	goto Mainmenu;
	}
	
}

void memberMenu() // MEMBER MENU
{
	std::unique_ptr<Cafe> c1(new Cafe()); //DYNAMIC OBJECT CREATION THROUGH SMART (UNIQUE POINTER) // NO MEMORY LEAK WILL OCCUR IT WILL DELETE IT SELF
	int ID = 0;
	std::string option = " ";
	do
	{
		system("cls");
		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** MEMBER MENU***           "<<std::endl;
		std::cout<<std::endl<<std::endl<<"\t\t\t***     01. ADD MEMBER                ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     02. VIEWALLMEMBERS            ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     03. UPDATEMEMBER              ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     04. DELETEMEMBER              ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     05. SearchMember              ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     06. GO BACK                   ***"<<std::endl;
		std::cout<<"    \t\t\t*******************************************"<<std::endl;
		std::cout<<"    \t\t\t*******************************************"<<std::endl;                      
		std::cout<<std::endl<<std::endl<<"\tSelect Your Option (1-6): ";
		std::cin>>option;

		if (option == "01" || option == "1")
		{
			c1->addMember(); // OBJECT CREATED IN CAFE ( COMPOSITION )
				
		}
		else if (option == "02" || option == "2")
		{
			c1->readMembers();
				
		}
		else if (option == "03" || option == "3")
		{
			std::cout<<"\t\t\tEnter ID To Update: ";
			std::cin>>ID;
			c1->updateMember(ID);
				
		}
		else if (option == "04" || option == "4")
		{
			std::cout<<"\t\t\tEnter ID To Delete: ";
			std::cin>>ID;
			c1->deleteMember(ID);
				
		}
		else if (option == "05" || option == "5")
		{
			std::cout<<"\t\t\tEnter ID To Update: ";
			std::cin>>ID;
			c1->searchMember(ID);
				
		}
		else if (option == "06" || option == "6")
		{
			subMenu();
				
		}
		else // VALIDATION 
		{
	        	std::cout<<std::endl<<"Invalid Input !"<<std::endl;
	        	system("PAUSE");
	        	system("cls");
	        	std::cout<<std::endl;

		}

	}while(1);
	

}

void subMenu() // CAFE MANAGEMENT SUB MENU
{
	// int option = 0;
	std::string option = " " ;
	do
	{
		system("cls");
		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** CAFE MANAGEMENT SYSTEM***           "<<std::endl;
		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** SUB MENU***           "<<std::endl;
		std::cout<<std::endl<<std::endl<<"\t\t\t***     01. MEMBER MENU                 ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     02. COMPUTER MENU               ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     03. GO BACK                      ***";
		std::cout<<std::endl<<std::endl<<"\tSelect Your Option (1-3): ";
		std::cin>>option;

		if (option == "01" || option == "1")
		{
			memberMenu(); // FUNCTION DEFINED IN MAIN
		}
		else if (option == "02" || option == "2")
		{
			ComputerMenu(); // FUNCTION DEFINED IN MAIN
		}
		else if (option == "03" || option == "3")
		{
			mainMenu(); // FUNCTION DEFINED IN MAIN TO NAVIGATE 
		}
		else // VALIDATION 
		{
        	std::cout<<std::endl<<"Invalid Input !"<<std::endl;
        	system("PAUSE");
        	system("cls");
        	std::cout<<std::endl;
		}
		

	}while(1);
	
}

void subMenu2() // FUNCTION TO CALCULATE CHARGES
{
	std::string option = " ";

	do

	{
		system("cls");
		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** CAFE MANAGEMENT SYSTEM***           "<<std::endl;
		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** SUB MENU***           "<<std::endl;
		// std::cout<<std::endl<<std::endl<<"\t\t\t***     01. BOOKING                 ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     01. CHARGES                 ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     02. GO BACK                 ***";
		std::cout<<std::endl<<std::endl<<"\tSelect Your Option (1-3): ";
		std::cin>>option;

		if (option == "01" || option == "1")
		{
			chargesMenu(); // FUNCTION DEFINED IN MAIN
		}
		else if (option == "02" || option == "2")
		{
			mainMenu(); // FUNCTION DEFINED IN MAIN TO NAVIGATE
		}
		else // VALIDATION 
		{
        	std::cout<<std::endl<<"Invalid Input !"<<std::endl;
        	system("PAUSE");
        	system("cls");
        	std::cout<<std::endl;
		}
	}while(1);
	
}

void chargesMenu()
{
	int  option2 = 0;
	std::unique_ptr<Charges> c1;
	std::string option = " ";
	do
	{
		system("cls");
		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** CHARGES MENU ***           "<<std::endl;
		std::cout<<std::endl<<std::endl<<"\t\t\t***     01. TAKE CHARGES                ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     02. GO BACK                     ***"<<std::endl<<std::endl;
		std::cout<<"    \t\t\t*******************************************"<<std::endl;
		std::cout<<"    \t\t\t*******************************************"<<std::endl;                      
		std::cout<<std::endl<<std::endl<<"\tSelect Your Option (1-2): ";
		std::cin>>option;


		if (option == "01" || option == "1")
		{
			std::cout<<std::endl<<"\t\t Enter 1 for User, 2 For Computer: ";
			std::cin>>option2;

			if(option2 == 1)
			{
				c1 = std::make_unique<UserCharges>(); // LATE BINDING
				std::cin>>*c1;
				c1->calculateCharges();
			}

			else if(option2 == 2)
			{
				c1 = std::make_unique<ComputerCharges>(); // LATE BINDING
				c1->calculateCharges();
			}

			//std::cin>>*c1;
			//c1->calculateCharges();
			break;
		}
		else if (option == "02" || option == "2")
		{
			subMenu2();
			break;
		}
		else // VALIDATION 
		{
        	std::cout<<std::endl<<"Invalid Input !"<<std::endl;
        	system("PAUSE");
        	system("cls");
        	std::cout<<std::endl;
		}

	}while(1);
}

void infoMenu() // DISPLAY INFO ABOUT PROGRAM
{
 		system("cls");
 		std::cout<<std::endl<<std::endl<<std::endl<<"\t\t\t            *** INFORMATION MENU***           "<<std::endl;
		std::cout<<std::endl<<std::endl<<"\t\t\t***     THIS PROGRAM IS CODED BY FOLLOWING            ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     M. AFFAN MURTAZA (CS181099)            	      ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     M. SHAYAN FAROOQUI (CS181106)          	      ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     PURPOSE:			              ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     LEARN AND IMPLEMENT CONCEPTS OF OOP AND C++   ***";
		std::cout<<std::endl<<std::endl<<"\t\t\t***     REFER TO REPORT FOR MORE INFORMATION          ***"<<std::endl;
		std::cout<<"    \t\t\t***********************************************************"<<std::endl;
		std::cout<<"    \t\t\t***********************************************************"<<std::endl;                      
		system("PAUSE");
		mainMenu();
}