#ifndef COMPUTER_H
#define COMPUTER_H

class Computer
{
		friend std::istream& operator >>(std::istream &in, Computer &c1); //OVER LOADING EXTRACTION OPERATOR TO Add New Computer
		friend std::ostream& operator <<(std::ostream &out, Computer &c1); // OVER LOADING INSERTION OPERATOR TO Display Computer Records

	public:

		Computer(); // constructor
		~Computer(); //destructor 
		void addComputer(); // New Computer
		void deleteComputer(const int& ID); // Delete Computer
		void updateComputer(const int& ID, Computer& c1); // Update Computer
		void searchComputer(const int& ID); // Search a Computer
		void readComputers(Computer& c1); // Display All Computers
		int getComputerID() const; // return Computer ID(Getter)
		char* getMemory(); // return Memory
		char* getProcessor(); // return Processor
		char* getGpu(); // return GPU
		char* getHdd(); // return HDD

	private:

		char memory[6], processor[8], GPU[10], HDD[6];
		unsigned int computerID;
};
#endif