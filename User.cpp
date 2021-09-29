#include <iostream>
#include "User.h"

User::User(): name(" "), contact(" "), userID(0), passWord(" "){} //DEFAUT CONSTRUCTOR

User::~User(){} //DEFAULT DECONSTRUCTOR

//GETTERS
char* User::getName()
{
	return name;
}

char* User::getContact()
{
	return contact;
}

char* User::getPassword()
{
	return passWord;
}