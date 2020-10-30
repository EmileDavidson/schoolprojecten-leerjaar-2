#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include <ctime>;
#include "School.h";
#include "Course.h";
#include "Student.h";

void sleepFor(int seconds) {
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void clearConsole() {
	system("cls");
}

int main()
{	
	//maak de school aan (school name, postcode, phone number)
	School* school = new School("Media collage amsterdam", "3278 GT", 31655123432);

	//maak de courses aan (course name) 
	Course* course_gameDeveloper = new Course("Game developer");
	Course* course_gameArtist = new Course("Media development");
	Course* course_webDeveloper = new Course("Audiovisueel");
	Course* course_webDesigner = new Course("Game artist");

	//add de course aan de school
	school->AddCourse(course_gameDeveloper);
	school->AddCourse(course_gameArtist);
	school->AddCourse(course_webDeveloper);
	school->AddCourse(course_webDesigner);

	//make dates aan (year, month, day)
	Date birthDate(2003, 05, 28);
	Date currentData(2020, 10, 20);
	//make students aan met juiste gegeven (firstname, lastname, birthdate (date), straatnaam, postcode, telefoon nummer, first name (eerste ouder), last name (eerste ouder), phonenumber (eerste ouder), schooljaar, currentdate (date)
	Student* student1 = new Student("Emile1", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 4, currentData);
	Student* student2 = new Student("Emile2", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 3, currentData);
	Student* student3 = new Student("Emile3", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 2, currentData);
	Student* student4 = new Student("Emile4", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 1, currentData);
	Student* student5 = new Student("Emile5", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 0, currentData);
	Student* student6 = new Student("Emile6", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 0, currentData);
	Student* student7 = new Student("Emile7", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 0, currentData);
	Student* student8 = new Student("Emile8", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 0, currentData);
	Student* student9 = new Student("Emile9", "Davidson", birthDate, "Laan van brussel", "1825 GS", 999999999, "Linda", "Davidson", 11122233344, 0, currentData);
	//add students to a school
	school->AddStudent(student1, course_gameDeveloper);
	school->AddStudent(student2, course_gameDeveloper);
	school->AddStudent(student3, course_gameDeveloper);
	school->AddStudent(student4, course_gameArtist);
	school->AddStudent(student5, course_gameArtist);
	school->AddStudent(student6, course_webDeveloper);
	school->AddStudent(student7, course_webDeveloper);
	school->AddStudent(student8, course_webDesigner);
	school->AddStudent(student9, course_webDesigner);

	//clear console
	clearConsole();
	//show school data
	school->PrintSchoolData();
	//wait 10 seconds
	sleepFor(5);
	//clear console
	clearConsole();

	//loop else if stops after first time so now we can do 10 years.
	for (int i = 0; i < 10; i++) {
		school->NextYear();
		school->PrintSchoolData();
		sleepFor(1);

		std::cout << "\n\nType iets om naar het volgende jaar te gaan\n";

		//this waits for input?
		//std::cin.get(); doesnt work for some reason skips for times.. 
		std::string test;
		std::cin >> test;
		clearConsole();
	}
	

	school->PrintSchoolData();
	return 0;
}