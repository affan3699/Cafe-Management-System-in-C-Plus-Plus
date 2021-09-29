#ifndef CAFEMANAGEMENT_H
#define CAFEMANAGEMENT_H
#include "Member.h" 
#include <memory>

class Cafe
{
		friend std::istream& operator >>(std::istream &in, Member &m1); // OVERLOADING EXTRACTION OPERATOR TO Add New Member
		friend std::ostream& operator <<(std::ostream &out, Member &m1); // OVERLOADING INSERTION OPERATOR TO  Display Member Records

	public:

		Cafe(); // DEFAULT CONSTRUCTOR 
		~Cafe(); // DEFAULT DECONSTRUCTOR
		void addMember(); // ADD MEMBER
		void deleteMember(const int& ID); // DELETE MEMBER
		void updateMember(const int& ID); // UPDATE MEMBER
		void searchMember(const int& ID); // SEARCH MEMBER 
		void readMembers(); // VIEW ALL MEMBER

		//GETTER
		int getMemberID() const;

	protected:

		Member m1; // COMPOSITION OF MEMBER
		
};
#endif