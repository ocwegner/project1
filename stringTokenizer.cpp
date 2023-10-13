#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

void countWordsAndLetters(std::string userInput1);
void reverseString(std::string userInput1);
void capitalFinder(std::string userInput1);
void wordFinder(std::string userInput1);


void stringTokenizer() {
	std::string userInput1 = "";

	std::cout << "What string would you like to process?\n";
	std::getline(std::cin, userInput1);
	std::getline(std::cin, userInput1);
	std::cout << "Your input is: " << userInput1 << std::endl;
	
	countWordsAndLetters(userInput1);
	reverseString(userInput1);
	capitalFinder(userInput1);
	wordFinder(userInput1);
}

void countWordsAndLetters(std::string userInput1) {
	//one variable to count words, one to count letters
	//both start as 1
	int wordCount;
	wordCount = 1;
	int letterCount;
	letterCount = 0;

	for (int i = 0; i <= userInput1.length(); i++) {
		if (userInput1[i] == ' ') {
			wordCount++;
		}

		else if (isalpha(userInput1[i])) {
			letterCount++;
		}
	}

	std::cout << "The input has " << wordCount << " words and " << letterCount << " letters.\n";
}

void reverseString(std::string userInput1) {
	for (int i = 0; i < (userInput1.length()); i++) {
		std::cout << userInput1[userInput1.length() - (i) - 1];
	}
	std::cout << "\n";
}

void capitalFinder(std::string userInput1) {
	//variable to see if there are any words with a capital letter
	int counter;
	counter = 0;

	//variable to store output
	std::string output;
	output = "";

	for (int l = 0; l < userInput1.size(); l++) {
		if ((userInput1[l] >= 'A' && userInput1[l] <= 'Z') ) {
			for (int j = l; j < userInput1.size(); j++) {
				if (userInput1[j] == ' ') {
					output = output + ", ";
					break;
				}
				else {
					output = output + userInput1[j];
				}
				l = j;
				counter++;
			}
		}
	}

	if (counter > 0) {
		std::cout << "The words that start with capital letters are: " << output << "\n";
	}
	else {
		std::cout << "There are no words that start with capital letters in the given input.\n";
	}
}

void wordFinder(std::string userInput1) {
	//variable to take the word the user wants to find
	std::string userInput2;
	userInput2 = "";

	//variable to manipulate the original input
	std::string manipulatedInput;
	manipulatedInput = userInput1;
	transform(manipulatedInput.begin(), manipulatedInput.end(), manipulatedInput.begin(), ::tolower);

	std::cout << "What word would you like to find? \n";
	std::cin >> userInput2;
	transform(userInput2.begin(), userInput2.end(), userInput2.begin(), ::tolower);

	size_t substring_length = manipulatedInput.find(userInput2);
	if (substring_length == std::string::npos) {
		std::cout << "The word was not found in the string.\n";
	}

	else {
		std::cout << "The word was found in the string.\n";
	}
}