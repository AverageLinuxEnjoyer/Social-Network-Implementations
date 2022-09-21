#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
private:
	std::string username;
	std::string password;
	std::string email;
	std::string firstName;
	std::string lastName;
	std::string bio;
	std::string profilePicture;

public:
	User();
	User(const std::string& username, const std::string& password, const std::string& email, const std::string& firstName, const std::string& lastName, const std::string& bio, const std::string& profilePicture);
	User(const User& other);
	~User();

	std::string getUsername();
	std::string getPassword();
	std::string getEmail();
	std::string getFirstName();
	std::string getLastName();
	std::string getBio();
	std::string getProfilePicture();

	void setUsername(const std::string& username);
	void setPassword(const std::string& password);
	void setEmail(const std::string& email);
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setBio(const std::string& bio);
	void setProfilePicture(const std::string& profilePicture);

	std::string toString();

	friend std::ostream& operator<<(std::ostream& os, const User& user);
	friend std::istream& operator>>(std::istream& is, User& user);

	friend std::ostream& loadIntoCSV(std::ostream& os, const User& user);
	friend std::istream& loadFromCSV(std::istream& is, User& user);

	bool operator==(const User& other) const;
};

std::ostream& loadIntoCSV(std::ostream& os, const User& user);
std::istream& loadFromCSV(std::istream& is, User& user);

#endif // USER_H
