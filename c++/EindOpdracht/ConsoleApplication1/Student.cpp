#include <iostream>
#include "Student.h"

#include <windows.h>
Student::Student(std::string name, std::string familyName, Date birthDate, std::string adres, std::string postCode, int phoneNumber, std::string firstContactName, std::string firstContactFamilyName, int phoneNumberfirstContact, int courseYear, Date admissionDate)
{
    this->_name = name;
    this->_familyName = familyName;
    this->_birthDate = birthDate;
    this->_adres = adres;
    this->_postCode = postCode;
    this->_phoneNumber = phoneNumber;
    this->_firstContactName = firstContactName;
    this->_firstContactFamilyName = firstContactFamilyName;
    this->_phoneNumberfirstContact = phoneNumberfirstContact;
    this->_courseYear = courseYear;
    this->_admissionDate = admissionDate;

    std::cout << "nieuwe student is aangemaakt\n";
}

Student::~Student()
{
    std::cout << "Student deleted student Name: " << this->_name << "\n";
}

void Student::NextYear() {
    _courseYear += 1;
}

bool Student::DoneWithSchool() {
    return (this->_courseYear > 4);
}


#pragma region Getters and setters

//getters
std::string Student::GetName(){ return this->_name;}
std::string Student::GetFamilyName(){return this->_familyName;}
Date Student::GetBirthDate(){return this->_birthDate;}
std::string Student::GetAdres(){return this->_adres;}
std::string Student::GetPostcode(){return this->_postCode;}
int Student::GetPhoneNumber(){return this->_phoneNumber;}
std::string Student::GetFirstContactName(){return this->_firstContactName;}
std::string Student::GetFirstContactFamilyName(){return this->_firstContactFamilyName;}
int Student::GetFirstContactPhonenumber(){return this->_phoneNumberfirstContact;}
int Student::GetCourseYear(){return this->_courseYear;}
Date Student::GetAdmissionDate(){return this->_admissionDate;}

//setters
void Student::SetName(std::string name){this->_name = name;}
void Student::SetFamiltyName(std::string famililyName){this->_familyName = famililyName;}
void Student::SetBirthDate(Date date){this->_birthDate = date;}
void Student::SetAdres(std::string adres){this->_adres = adres;}
void Student::SetPostcode(std::string postcode){this->_postCode = postcode;}
void Student::SetPhoneNumber(int number){this->_phoneNumber = number;}
void Student::SetFirstContactName(std::string name){this->_firstContactName = name;}
void Student::SetFirstContactFamilyName(std::string name){ this->_firstContactFamilyName = name; }
void Student::SetFirstContactPhonenumber(int number){ this->_phoneNumberfirstContact = number; }
void Student::SetCourseYear(int year){ this->_courseYear = year; }
void Student::SetAdmissionDate(Date date) { this->_admissionDate = date; }

#pragma endregion