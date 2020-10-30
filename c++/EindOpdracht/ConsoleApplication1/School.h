#pragma once
#include <string>;
#include <vector>;
#include "Course.h";
#include "Student.h";

class School
{
public:
	// Constructor
	School(std::string name, std::string postcode, long phoneNumber);
	~School();

	void AddStudent(Student* student, Course* course);
	void RemoveStudent(Student* student);
	void NextYear();
	void AddCourse(Course* course);
	void RemoveCourse(Course* course);
	void PrintSchoolData();

	int GetAge();
	std::string GetName();
	std::string GetPostcode();
	long GetPhoneNumber();
	int GetStudentCount();
	std::vector < Course* > GetCourses();

	void SetAge(int age);
	void SetName(std::string name);
	void SetPostcode(std::string postcode);
	void SetPhoneNumber(long number);

private:
	std::string name;
	int age;
	std::string postcode;
	long phoneNumber;
	int studentCount;
	std::vector< Course* > courses;

};