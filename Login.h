// LOGIN CLASS
#ifndef LOGIN_H  
#define LOGIN_H

class Login
{
	public:

		Login(const std::string& userName, const std::string& passWord); // Parameterized Constructor
		~Login(); // Destructor
		
		//GETTERS
		std::string getUser() const;
		std::string getPass() const;
		//SETTERS
		void setUser(const std::string& userName);
		void setPass(const std::string& passWord);

	private:
		
		std::string userName, passWord;
};
#endif