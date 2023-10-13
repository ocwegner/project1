#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

float goingThroughFile(std::string studentName);
void letterGrade(float grade, std::string studentName);

void gradesProcessor() {
	//establish a variable to hold the student's name
	std::string input = "";

	//establish a variable to hold a valid name
	std::string studentName = "";

	//establish a variable to hold the returned grade
	float grade;
	grade = 0;

	//ask user for input
	std::cout << "What is the name of the student whose grade you would like to access?\n";
	std::cin >> studentName;

	transform(studentName.begin(), studentName.end(), studentName.begin(), ::tolower);
	studentName[0] = std::toupper(studentName[0]);

	if ((studentName != "Omar") && (studentName != "Hana") && (studentName != "Tom") && (studentName != "Nancy") && (studentName != "Raja")) {
		std::cout << "Sorry, that answer is not acceptable. Please try again.\n";
		gradesProcessor();
	}

	else {
		grade = goingThroughFile(studentName);
		letterGrade(grade, studentName);
	}
}

float goingThroughFile(std::string studentName){
	//open file
	std::fstream gradeFile("grades.txt", std::ifstream::in);

	//variables for the different grades
	float labs;
	labs = 0;
	float quizes;
	quizes = 0;
	float project;
	project = 0;
	float midterm;
	midterm = 0;
	float final;
	final = 0;

	//variable to store final grade
	float grade;

	//temporary variable to go through the file
	std::string temp;

	//going through file 
	while (getline(gradeFile, temp)) {
		if (temp.find(studentName) != std::string::npos) {
			std::string temp2;
			std::istringstream parse{ temp }, translate;
			std::getline(parse, temp2, ',');

			std::getline(parse, temp2, ',');
			translate.str(temp2);
			translate >> labs;

			std::getline(parse, temp2, ',');
			translate.clear();
			translate.str(temp2);
			translate >> quizes;

			std::getline(parse, temp2, ',');
			translate.clear();
			translate.str(temp2);
			translate >> project;

			std::getline(parse, temp2, ',');
			translate.clear();
			translate.str(temp2);
			translate >> midterm;

			std::getline(parse, temp2, ',');
			translate.clear();
			translate.str(temp2);
			translate >> final;
		}
	}

	//calculate average
	grade = (labs + quizes + project + midterm + final) / 5;
	std::cout << "This student's grade is: " << grade << "%. ";
	return grade;
}

void letterGrade(float grade, std::string studentName) {
	if (grade >= 90) {
		std::cout << studentName << "'s letter grade is A.\n";
	}

	else if (grade >= 80 && grade < 90) {
		std::cout << studentName << "'s letter grade is B.\n";
	}

	else if (grade >= 70 && grade < 80) {
		std::cout << studentName << "'s letter grade is C.\n";
	}

	else if (grade >= 60 && grade < 70) {
		std::cout << studentName << "'s letter grade is D.\n";
	}

	else if (grade < 59) {
		std::cout << studentName << "'s letter grade is F.\n";
	}
}