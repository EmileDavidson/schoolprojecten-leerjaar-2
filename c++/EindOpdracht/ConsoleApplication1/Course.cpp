#include <iostream>;
#include <vector>;
#include "Course.h";



Course::Course(std::string name)
{
	this->name = name;
	std::cout << "Succesfully made the course: " + name + " \n";
}
Course::~Course()
{
	std::cout << "course deleted course name: " + this->name;
}



void Course::AddStudent(Student* student)
{
	this->students.push_back(student);
}

void Course::RemoveStudent(Student* student)
{
	for (int i = 0; i < this->students.size(); i++) {
		if (this->students[i] == student) {
			this->students.erase(this->students.begin() + i);
			i -= 1;
		}
	}
}


#pragma region Getters And Setters
//getters
std::string Course::GetName(){return this->name;}
int Course::GetAge() {return this->age;}
int Course::GetStudentCounter() { return this->studentCount; }
std::vector<Student*>* Course::GetStudents(){return &this->students;}
//setters
void Course::SetName(std::string name){this->name = name;}
void Course::SetAge(int age){this->age = age;}

#pragma endregion