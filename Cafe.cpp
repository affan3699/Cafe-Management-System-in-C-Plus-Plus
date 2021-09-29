#include <iostream>
#include "Cafe.h"

Cafe::Cafe(){} //DEFAULT CONSTRUCTOR

Cafe::~Cafe(){} //DEFAULT DECONSTRUCTOR

void Cafe::addMember() // ADD MEMBER 
{
	std::cin>>m1; 
	m1.addMember();
}

void Cafe::deleteMember(const int& ID) // DELETE MEMBER 
{
	m1.deleteMember(ID);	
}

void Cafe::updateMember(const int& ID) //UPDATE MEMEBER
{
	m1.updateMember(ID, m1);
}

void Cafe::searchMember(const int& ID) //SEARCH MEMEBER
{
	m1.searchMember(ID);
}

void Cafe::readMembers() //VIEW ALL MEMBERS
{
	m1.readMembers(m1);
}

//GETTER
int Cafe::getMemberID() const
{
	int userID = 0;

	userID = m1.getMemberID();
	return userID;
}