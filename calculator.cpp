#include <iostream>
#include <string>

char inputFunction;
int number1;
int number2;
double answer;


void calculator() {
	std::cout << "Please enter the operation you would like to execute.\n";
	std::cout << "Your options are: +, -, / , *, %, and l(choosing l will execute a log function).\n";
	std::cin >> inputFunction;
	if ((inputFunction != '+') && (inputFunction != '-') && (inputFunction != '/') && (inputFunction != '*') && (inputFunction != '%') && (inputFunction != 'l')){
	std::cout << "That is not an acceptable answer, please try again.\n";
	calculator();
	}
	std::cout << "Please enter the first number you would like to use.\n";
	std::cout << "Only enter digits. Do not enter letters, characters, or commas.\n";
	std::cin >> number1;

	if ((inputFunction == '+') || (inputFunction == '-') || (inputFunction == '/') || (inputFunction == '*') || (inputFunction == '%')) {
		std::cout << "Please enter the second number you would like to use.\n";
		std::cout << "Only enter digits. Do not enter letters, characters, or commas.\n";
		std::cin >> number2;
	}
	
	switch (inputFunction) {
		case '+':
			answer = number1 + number2;
			std::cout << number1 << " + " << number2 << " = " << answer << "\n";
			break;

		case '-':
			answer = number1 - number2;
			std::cout << number1 << " - " << number2 << " = " << answer << "\n";
			break;

		case '/':
			answer = number1 / number2;
			std::cout << number1 << " / " << number2 << " = " << answer << "\n";
			break;

		case '*':
			answer = number1 * number2;
			std::cout << number1 << " * " << number2 << " = " << answer << "\n";
			break;

		case '%':
			answer = number1 % number2;
			std::cout << number1 << " % " << number2 << " = " << answer << "\n";
			break;

		case 'l':
			answer = log2(number1);
			std::cout << "The logarithmic value of " << number1 << " with a base of 2 = " << answer << "\n";
			break;
	}
}