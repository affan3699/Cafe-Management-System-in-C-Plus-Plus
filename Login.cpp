//LOGIN.CPP
#include <iostream>
#include "Login.h"

// Parameterized Constructor
Login :: Login(const std::string& userName, const std::string& passWord): userName(userName), passWord(passWord){}

Login :: ~Login(){}

//GETTERS
std::string Login :: getUser() const
{
	return userName;
}

std::string Login :: getPass() const
{
	return passWord;
}

//SETTERS
void Login :: setUser(const std::string& userName)
{
	this->userName = userName;
}

void Login :: setPass(const std::string& passWord)
{
	this->passWord = passWord;
}