#include <iostream>
#include <iomanip> // CONTAINS SETWIDTH (STD::SETW(10)) FUNCTION
#include <fstream> //FILE STREAM
#include "Member.h"

Member::Member(){} // DEFAULT CONSTRUCTOR

Member::~Member(){} // DEFAULT DESTRUCTOR

std::istream& operator>>(std::istream &in, Member &m1) //OVER LOADING EXTRACTION OPERATOR TO Add New MEMBER // DEFINITION
{
	//MEMBER VARIBALE INHERITED FROM CLASS USER
	std::cout<<"\t\tEnter UserID: ";
	in>>m1.userID;
	std::cout<<"\t\tEnter Name: ";
	in>>m1.name;
	std::cout<<"\t\tEnter Password: ";
	in>>m1.passWord;
	std::cout<<"\t\tEnter Contact No: ";
	in>>m1.contact;

	return in;
}

std::ostream& operator<<(std::ostream &out, Member &m1) // OVER LOADING INSERTION OPERATOR TO Display MEMBER Records // DEFINITION
{
	out<<m1.userID<<std::setw(14)<<m1.name<<std::setw(10)<<m1.passWord<<std::setw(22)<<m1.contact; //WIDTH IS TO BE SET IN ORDER TO INSERT NEW VALUE (FUNCTION DECLARED IN IOMANIP)

	return out;
}

void Member::addMember() // ADD MEMEBER FUNCTION
{
	std::string fileName = "Member.dat";
	std::ofstream outFile;
	outFile.open(fileName.c_str(), std::ios::app | std::ios::binary);  // BINARY FILED OPENED TO STORE IN .DAT FILE
	outFile.write((char*) (this), sizeof(*this));
	outFile.close();
	std::cout<<std::endl<<"\t\tMember Added"<<std::endl;
	system("pause");
}

void Member::deleteMember(const int& ID) // DELETE MEMBER 
{
	std::string fileName = "Member.dat";
	std::ifstream inFile; // TO READ FROM ONE FILE
	std::ofstream outFile; // TO WRITE IN ONE FILE

	inFile.open(fileName.c_str(), std::ios::binary);  // BINARY FILING OPEN
	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
	}

	outFile.open("Temp.dat", std::ios::binary);

	//seekG the position of the next character to be extracted from the input stream.
	inFile.seekg(0, std::ios::beg);

	while(inFile.read((char*) (this), sizeof(*this)))
	{
		if(getMemberID() != ID) // COMPARING INPUT ID WITH ID MEMBER.DAT FILE
		{
			outFile.write((char*) (this), sizeof(*this)); //STORE INTO FILE WHEN ABOVE CONDITION IS TRUE
		}
	}

    inFile.close();
	outFile.close();

	remove("Member.dat"); // REMOVE OLD COMPUTER.DAT FILE 
	rename("Temp.dat","Member.dat"); // RENAME TEMP TO COMPUTER.DAT FILE

	std::cout<<std::endl<<std::endl<<"\tMEMBER RECORD DELETED ..";
	std::cout<<std::endl<<std::endl;
	system("pause");
}


void Member::updateMember(const int& ID, Member& m1) // UPDATE COMPUTER FILE
{
	std::string fileName = "Member.dat";
	int pos = 0, pos1 = 0;
	bool found = false;
	std::fstream File;

	File.open(fileName.c_str(), std::ios::in | std::ios::out | std::ios::binary); // OPENIN FILE FOR READ AND WRITE BINARY MODE
   

	if(!File)
	{
		std::cout<<"File could not be open !! Press any Key...";
		return;
	}
	
	while(!File.eof() && found == false) //READING WHILE END OF FILE
	{
		File.read((char*) (this), sizeof(*this));

		if(getMemberID() == ID)
		{
			searchMember(ID);
			std::cout<<std::endl<<std::endl<<"Enter The New Details Of Member"<<std::endl;
			std::cin>>m1;
			// tellp() Returns the position of the current character in the output stream
			pos = File.tellp();
			pos1 = sizeof(*this);
			// seekp() Sets the position where the next character is to be inserted into the output stream.
			File.seekp(pos - pos1);
		    File.write((char*) (this), sizeof(*this));
		    std::cout<<std::endl<<"\t Member Updated"<<std::endl<<std::endl;
		    found = true;
		  }

	}

	File.close();
	if(found == false)
	{
		std::cout<<"\n\n Record Not Found ";
	}

	system("pause");
}

void Member::searchMember(const int& ID) // SEARCHING IN FILE WITH INPUT ID 
{
	system("cls");
	std::string fileName = "Member.dat";
	bool flag = false;
	std::ifstream inFile;
	inFile.open(fileName.c_str(), std::ios::in | std::ios::binary);// FILE OPEN IN BINARY MODE
	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
	}

	else
	{
		inFile.seekg(0); // SET POSITION TO 0 
		std::cout<<std::endl<<"MEMBER DETAILS"<<std::endl;
    	while(inFile.read((char*) (this), sizeof(*this)))
		{
			if(getMemberID() == ID)
			{
				std::cout<<"\n\t\tMEMBER ID : "<<getMemberID(); // READING FROM FILE //FUNCTIONS DECLARED IN USER CLASS AND INHERITED HERE
				std::cout<<"\n\t\tNAME : "<<getName();
				std::cout<<"\n\t\tPASSWORD : "<<getPassword();
				std::cout<<"\n\t\tCONTACT : "<<getContact()<<std::endl;
				flag = true;
				break;
			}
		}
	}
	
    inFile.close();
    
	if(flag == false)
	{
		std::cout<<"\n\tMEMBER does not exist";
	}

	system("pause");
}

void Member::readMembers(Member& m1) // TO VIEW ALL RECORDS ON COMPUTER CLASS
{
	system("cls");
	std::ifstream inFile;

	inFile.open("Member.dat", std::ios::in | std::ios::binary);

	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
	}

	else
	{
		std::cout<<"\n\n\t\t\t\tMEMBER LIST\n\n";
		std::cout<<"================================================================="<<std::endl;
		std::cout<<"ID"<<std::setw(15)<<"NAME"<<std::setw(14)<<"  PASSWORD"<<std::setw(15)<<"COMTACT"<<std::endl;
		std::cout<<"================================================================="<<std::endl;

		while(inFile.read((char*) (this), sizeof(*this)))
		{
			std::cout<<m1<<std::endl;
		}

		inFile.close();
	}

	system("pause");
}

// GETTER
int Member::getMemberID() const
{
	return userID;
}