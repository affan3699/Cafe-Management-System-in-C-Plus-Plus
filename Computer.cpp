#include <iostream>  
#include <fstream> // FILING STREAM 
#include <iomanip> // CONTAINS SETWIDTH (STD::SETW(10)) FUNCTION
#include <cctype>
#include "Computer.h"

Computer::Computer(): memory(" "), processor(" "), GPU(" "), HDD(" "), computerID(0){} // DEFAULT VALUE THROUGH CONSTRUCTOR

Computer::~Computer(){} //DESTRUCTOR

std::istream& operator>>(std::istream &in, Computer &c1) //OVER LOADING EXTRACTION OPERATOR TO Add New Computer // DEFINITION
{
	std::cout<<"Enter computerID: ";
	in>>c1.computerID;
	std::cout<<"Enter memory: ";
	in>>c1.memory;
	std::cout<<"Enter processor: ";
	in>>c1.processor;
	std::cout<<"Enter GPU: ";
	in>>c1.GPU;
	std::cout<<"Enter HDD: ";
	in>>c1.HDD;

	return in;
}

std::ostream& operator<<(std::ostream &out, Computer &c1) // OVER LOADING INSERTION OPERATOR TO Display Computer Records // DEFINITION
{
	out<<c1.computerID<<std::setw(10)<<c1.memory<<std::setw(14)<<c1.processor<<std::setw(20)<<c1.GPU<<std::setw(12)<<c1.HDD<<std::endl; //WIDTH IS TO BE SET IN ORDER TO INSERT NEW VALUE

	return out;
}

void Computer::addComputer() //NEW COMPUTER 
{
	std::string fileName = "Computer.dat";
	std::ofstream outFile;
	outFile.open(fileName.c_str(), std::ios::app | std::ios::binary); // BINARY FILED OPENED TO STORE IN .DAT FILE
	outFile.write((char*) (this), sizeof(*this));
	outFile.close();
	std::cout<<std::endl<<"\t\tComputer Added"<<std::endl;
	system("pause");
}

void Computer::deleteComputer(const int& ID)
{
	std::string fileName = "Computer.dat";
	std::ifstream inFile;	// TO READ FROM ONE FILE
	std::ofstream outFile; // TO WRITE IN ONE FILE

	inFile.open(fileName.c_str(), std::ios::binary); // BINARY FILING OPEN
	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
	}

	outFile.open("Temp.dat", std::ios::binary);

	//seekG the position of the next character to be extracted from the input stream.
	inFile.seekg(0, std::ios::beg);
	while(inFile.read((char*) (this), sizeof(*this)))
	{
		if(getComputerID() != ID) // COMPARING INPUT ID WITH ID COMPUTER.DAT FILE
		{
			outFile.write((char*) (this), sizeof(*this)); //STORE INTO FILE WHEN ABOVE CONDITION IS TRUE
		}
	}

    inFile.close();
	outFile.close();

	remove("Computer.dat"); // REMOVE OLD COMPUTER.DAT FILE 
	rename("Temp.dat","Computer.dat"); // RENAME TEMP TO COMPUTER.DAT FILE

	std::cout<<std::endl<<std::endl<<"\tComputer Record Deleted ..";
	std::cout<<std::endl<<std::endl;
	system("pause");
}

void Computer::searchComputer(const int& ID) // SEARCHING IN FILE WITH INPUT ID 
{
	system("cls");
	std::string fileName = "Computer.dat";
	bool flag = false;
	std::ifstream inFile;

	inFile.open(fileName.c_str(), std::ios::in | std::ios::binary); // FILE OPEN IN BINARY MODE
	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
	}

	else
	{
		inFile.seekg(0); // SET POSITION TO 0 
		std::cout<<std::endl<<"COMPUTER DETAILS"<<std::endl;
    	while(inFile.read((char*) (this), sizeof(*this)))
		{
			if(getComputerID() == ID) 
			{
				std::cout<<"\n\t\tComputerID : "<<getComputerID(); // READING FROM FILE 
				std::cout<<"\n\t\tMemory : "<<getMemory();
				std::cout<<"\n\t\tProcessor : "<<getProcessor();
				std::cout<<"\n\t\tGPU: "<<getGpu();
				std::cout<<"\n\t\tHDD: "<<getHdd()<<std::endl;
				flag = true;
				break;
			}
		}
	}
	
    inFile.close();
    
	if(flag == false)
	{
		std::cout<<"\n\nComputer does not exist";
	}

	system("pause");
}

void Computer::updateComputer(const int& ID, Computer& c1) // UPDATE COMPUTER FILE
{
	std::string fileName = "Computer.dat";
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

		if(getComputerID() == computerID)
		{
			searchComputer(ID);
			std::cout<<std::endl<<std::endl<<"Enter The New Details Of Computer"<<std::endl;
			std::cin>>c1;
			// tellp() Returns the position of the current character in the output stream
			pos = File.tellp();
			pos1 = sizeof(*this);
			// seekp() Sets the position where the next character is to be inserted into the output stream.
			File.seekp(pos - pos1);
		    File.write((char*) (this), sizeof(*this));
		    std::cout<<std::endl<<"\t Record Updated"<<std::endl<<std::endl;
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

void Computer::readComputers(Computer& c1) // TO VIEW ALL RECORDS ON COMPUTER CLASS
{
	system("cls");
	
	std::ifstream inFile;

	inFile.open("Computer.dat", std::ios::in | std::ios::binary);

	if(!inFile)
	{
		std::cout<<"File could not be open !! Press any Key...";
	}

	else
	{
		std::cout<<"\n\n\t\tCOMPUTER LIST\n\n";
		std::cout<<"=================================================================\n";
		std::cout<<"ID"<<std::setw(15)<<"MEMORY"<<std::setw(14)<<"  PROCESSOR"<<std::setw(15)<<"GPU"<<std::setw(15)<<"HDD\n";
		std::cout<<"=================================================================\n";

		while(inFile.read((char*) (this), sizeof(*this)))
		{
			std::cout<<c1<<std::endl;
		}

	inFile.close();
	}

	system("pause");
}

// GETTERS USED AS CHAR ARRAY FOR BINARY FILING
int Computer::getComputerID() const
{
	return computerID;
}

char* Computer::getMemory()
{
	return memory;
}

char* Computer::getProcessor()
{
	return processor;
}

char* Computer::getGpu()
{
	return GPU;
}

char* Computer::getHdd() 
{
	return HDD;
}