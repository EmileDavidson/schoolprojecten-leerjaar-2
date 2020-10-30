#pragma once
#include <string>
#include "Date.h"

class Student
{
private:
    std::string _name;
    std::string _familyName;
    Date _birthDate;
    std::string _adres;
    std::string _postCode;
    int _phoneNumber;
    std::string _firstContactName;
    std::string _firstContactFamilyName;
    int _phoneNumberfirstContact;
    int _courseYear;
    Date _admissionDate;

public:
    Student(std::string name, std::string familyName, Date birthDate, std::string adres, std::string postCode, int phoneNumber, std::string firstContactName, std::string firstContactFamilyName, int phoneNumberfirstContact, int courseYear, Date admissionDate);
    ~Student();

    void NextYear();
    bool DoneWithSchool();

    // getters and setters

    std::string GetName();
    std::string GetFamilyName();
    Date GetBirthDate();
    std::string GetAdres();
    std::string GetPostcode();
    int GetPhoneNumber();
    std::string GetFirstContactName();
    std::string GetFirstContactFamilyName();
    int GetFirstContactPhonenumber();
    int GetCourseYear();
    Date GetAdmissionDate();

    void SetName(std::string name);
    void SetFamiltyName(std::string famililyName);
    void SetBirthDate(Date date);
    void SetAdres(std::string adres);
    void SetPostcode(std::string postcode);
    void SetPhoneNumber(int Number);
    void SetFirstContactName(std::string name);
    void SetFirstContactFamilyName(std::string name);
    void SetFirstContactPhonenumber(int number);
    void SetCourseYear(int year);
    void SetAdmissionDate(Date date);
};