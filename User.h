#ifndef USER_H
#define USER_H

class User // HOLDS USER INFORMATION
{
	public:

		User(); //DEFAULT CONSTRUCTOR
		~User(); //DEFAULT DECONSTRUCTOR
		
		//GETTERS
		char* getName();
		char* getContact();
		char* getPassword();

	protected:

		char name[20], contact[12], passWord[13];
		int userID;
};
#endif