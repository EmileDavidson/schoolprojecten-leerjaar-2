#pragma once
#include <string>;
#include <vector>;
#include "Student.h"

class Course
{

public:
	std::vector < Student* > students;

	Course(std::string name);
	~Course();

	void AddStudent(Student* student);
	void RemoveStudent(Student* student);

	// getters and setters
	std::string GetName();
	int GetAge();
	int GetStudentCounter();
	std::vector<Student*>* GetStudents();

	void SetName(std::string name);
	void SetAge(int age);

private:
	std::string name;
	int age;
	int studentCount;

};