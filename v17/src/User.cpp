#include "../include/User.h"


User::User()
    : username(""),
      password(""),
      email(""),
      firstName(""),
      lastName(""),
      bio(""),
      profilePicture("")
{
}

User::User(const std::string& username, const std::string& password, const std::string& email, const std::string& firstName, const std::string& lastName, const std::string& bio, const std::string& profilePicture)
    : username(username),
      password(password),
      email(email),
      firstName(firstName),
      lastName(lastName),
      bio(bio),
      profilePicture(profilePicture)
{
}

User::User(const User& other)
    : username(other.username),
      password(other.password),
      email(other.email),
      firstName(other.firstName),
      lastName(other.lastName),
      bio(other.bio),
      profilePicture(other.profilePicture)
{
}

User::~User()
{
}

std::string User::getUsername()
{
    return username;
}

std::string User::getPassword()
{
    return password;
}

std::string User::getEmail()
{
    return email;
}

std::string User::getFirstName()
{
    return firstName;
}

std::string User::getLastName()
{
    return lastName;
}

std::string User::getBio()
{
    return bio;
}

std::string User::getProfilePicture()
{
    return profilePicture;
}

void User::setUsername(const std::string& username)
{
    this->username = username;
}

void User::setPassword(const std::string& password)
{
    this->password = password;
}

void User::setEmail(const std::string& email)
{
    this->email = email;
}

void User::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void User::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void User::setBio(const std::string& bio) {
    this->bio = bio;
}

void User::setProfilePicture(const std::string& profilePicture) {
    this->profilePicture = profilePicture;
}

bool User::operator==(const User& other) const {
    return username == other.username;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Nume de utilizator: " << user.username << std::endl;
    os << "Parola: " << user.password << std::endl;
    os << "Email: " << user.email << std::endl;
    os << "Prenume: " << user.firstName << std::endl;
    os << "Nume: " << user.lastName << std::endl;
    os << "Biografie: " << user.bio << std::endl;
    os << "Link poza de profil: " << user.profilePicture << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, User& user) {
    std::string username;
    std::string password;
    std::string email;
    std::string firstName;
    std::string lastName;
    std::string bio;
    std::string profilePicture;

    std::cout << "Nume de utilizator: ";
    is >> username;

    std::cout << "Parola: ";
    is >> password;

    std::cout << "Email: ";
    is >> email;

    std::cout << "Prenume: ";
    is >> firstName;

    std::cout << "Nume: ";
    is >> lastName;

    std::cout << "Biografie: ";
    is >> bio;

    std::cout << "Link poza de profil: ";
    is >> profilePicture;

    user.username = username;
    user.password = password;
    user.email = email;
    user.firstName = firstName;
    user.lastName = lastName;
    user.bio = bio;
    user.profilePicture = profilePicture;

    return is;
}

std::ostream& loadIntoCSV(std::ostream& os, const User& user) {
    os << user.username << ",";
    os << user.password << ",";
    os << user.email << ",";
    os << user.firstName << ",";
    os << user.lastName << ",";
    os << user.bio << ",";
    os << user.profilePicture << std::endl;
    return os;
}

std::istream& loadFromCSV(std::istream& is, User& user) {
    std::string username;
    std::string password;
    std::string email;
    std::string firstName;
    std::string lastName;
    std::string bio;
    std::string profilePicture;

    std::getline(is, username, ',');
    std::getline(is, password, ',');
    std::getline(is, email, ',');
    std::getline(is, firstName, ',');
    std::getline(is, lastName, ',');
    std::getline(is, bio, ',');
    std::getline(is, profilePicture, '\n');

    user.username = username;
    user.password = password;
    user.email = email;
    user.firstName = firstName;
    user.lastName = lastName;
    user.bio = bio;
    user.profilePicture = profilePicture;

    return is;
}