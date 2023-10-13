#include <iostream>
#include <string>
#include <algorithm>

void speedConversion();
void bigDistanceConversion();
void smallDistanceConversion();

void converter() {
	int userChoice;

	std::cout << "What would you like to convert? Please select a numerical option based on the list below:\n";
	std::cout << "1. Miles per hour to/from kilometers per hour\n";
	std::cout << "2. Feet to/from meters\n";
	std::cout << "3. Inches to/from centimeters\n";
	std::cin >> userChoice;

	switch (userChoice) {
		case 1:
			speedConversion();
			break;
		case 2:
			bigDistanceConversion();
			break;
		case 3:
			smallDistanceConversion();
			break;
	}
}

void speedConversion() {
	//variable to store the unit we start in.
	std::string startingUnit;

	//variable to store the user's desired number for conversion
	int numberToConvert;
	//variable to store the new converted number
	double numberAfterConversion;

	std::cout << "Would you like to start with miles per hour or with kilometers per hour?\n";
	std::cout << "Please enter an M for MPH or K for KPH!\n";
	std::cin >> startingUnit;
	transform(startingUnit.begin(), startingUnit.end(), startingUnit.begin(), ::tolower);
	
	if ((startingUnit != "m") && (startingUnit != "k")) {
		std::cout << "That is not an acceptable answer. Please try again.\n";
		speedConversion();
	}
	else if (startingUnit == "m") {
		std::cout << "Please input the speed you want to convert: \n";
		std::cin >> numberToConvert;
		numberAfterConversion = numberToConvert / 0.62137;
		std::cout << numberToConvert << " mph is " << numberAfterConversion << " kph.\n";
	}
	else if (startingUnit == "k") {
		std::cout << "Please input the speed you want to convert: \n";
		std::cin >> numberToConvert;
		numberAfterConversion = numberToConvert * 0.62137;
		std::cout << numberToConvert << " kph is " << numberAfterConversion << " mph.\n";
	}
}

void bigDistanceConversion() {
	//variable to store the unit we start in.
	std::string startingUnit;

	//variable to store the user's desired number for conversion
	int numberToConvert;
	//variable to store the new converted number
	double numberAfterConversion;

	std::cout << "Would you like to start with feet or with meters?\n";
	std::cout << "Please enter an F for feet or M for meters!\n";
	std::cin >> startingUnit;
	transform(startingUnit.begin(), startingUnit.end(), startingUnit.begin(), ::tolower);

	if ((startingUnit != "f") && (startingUnit != "m")) {
		std::cout << "That is not an acceptable answer. Please try again.\n";
		bigDistanceConversion();
	}
	else if (startingUnit == "f") {
		std::cout << "Please input the distance you want to convert: \n";
		std::cin >> numberToConvert;
		numberAfterConversion = numberToConvert / 3.2808;
		std::cout << numberToConvert << " foot/feet is " << numberAfterConversion << " meter(s).\n";
	}
	else if (startingUnit == "m") {
		std::cout << "Please input the distance you want to convert: \n";
		std::cin >> numberToConvert;
		numberAfterConversion = numberToConvert * 3.2808;
		std::cout << numberToConvert << " meter(s) is " << numberAfterConversion << " foot/feet.\n";
	}
}

void smallDistanceConversion() {
	//variable to store the unit we start in.
	std::string startingUnit;

	//variable to store the user's desired number for conversion
	int numberToConvert;
	//variable to store the new converted number
	double numberAfterConversion;

	std::cout << "Would you like to start with inches or with centimeters?\n";
	std::cout << "Please enter an I for inches or C for centimeters!\n";
	std::cin >> startingUnit;
	transform(startingUnit.begin(), startingUnit.end(), startingUnit.begin(), ::tolower);

	if ((startingUnit != "i") && (startingUnit != "c")) {
		std::cout << "That is not an acceptable answer. Please try again.\n";
		smallDistanceConversion();
	}
	else if (startingUnit == "i") {
		std::cout << "Please input the distance you want to convert: \n";
		std::cin >> numberToConvert;
		numberAfterConversion = numberToConvert * 2.54;
		std::cout << numberToConvert << " inch(es) is " << numberAfterConversion << " centimeter(s).\n";
	}
	else if (startingUnit == "c") {
		std::cout << "Please input the distance you want to convert: \n";
		std::cin >> numberToConvert;
		numberAfterConversion = numberToConvert / 2.54;
		std::cout << numberToConvert << " centimeter(s) is " << numberAfterConversion << " inch(es).\n";
	}
}