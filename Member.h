#ifndef MEMBER_H
#define MEMBER_H
#include "User.h" //INHERTING FROM USER CLASS TO USE IT MEMBER FUNCTION/VARIABLES

class Member: public User // INHERITANCE
{
		friend std::istream& operator>>(std::istream &in, Member &m1); //OVER LOADING EXTRACTION OPERATOR TO Add New MEMBER
		friend std::ostream& operator<<(std::ostream &out, Member &m1); // OVER LOADING INSERTION OPERATOR TO Display MEMBER Records

	public:

		Member();// CONSTRUCTOR
		~Member(); // DESTRUCTOR
		void addMember(); // NEW MEMBER
		void deleteMember(const int& ID); // DELETE CURRENT MEMBER
		void updateMember(const int& ID, Member& c1); // UPDATE CURRENT MEMEBER
		void searchMember(const int& ID); //SEARCH IN FILE 
		void readMembers(Member& c1); // VIEW ALL MEMBERS
		//GETTER
		int getMemberID() const; 
};
#endif