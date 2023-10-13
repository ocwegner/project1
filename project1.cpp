// project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

void menu(std::string userName, int lastChoice);
void calculator();
void converter();
void gradesProcessor();
void stringTokenizer();
void help(int lastChoice);

int main()
{
    //variables to store the user's name
    std::string userName;

    //variable to store the last operation
    int lastChoice{};
    lastChoice = 0;

    //recieve user's first and last names
    std::cout << "Hello, user!\n";
    std::cout << "Please enter your name to get started!\n";

    getline(std::cin, userName);
    std::cout << "Welcome, " << userName << "!\n";
    menu(userName, lastChoice);
}

void menu(std::string userName, int lastChoice)
{
    //variable to store future user input
    std::string choice;

    //variable to convert choice into a number
    int choiceAsNum{};

    //display menu + potential options
    std::cout << "----------------------------------------\n";
    std::cout << "           MENU           \n";
    std::cout << "Please select one of the options below:\n";
    std::cout << "1. Math Calculator\n";
    std::cout << "2. Metric Conversion Calculator\n";
    std::cout << "3. Grades Calculator\n";
    std::cout << "4. String Tokenizer\n";
    std::cout << "5. Help\n";
    std::cout << "6. Quit\n";
    std::cin >> choice;
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
    if ((choice == "1") || (choice == "2") || (choice == "3") || (choice == "4") || (choice == "5") || (choice == "6"))
        choiceAsNum = stoi(choice);
    else if ((choice == "h") || (choice == "help"))
        choiceAsNum = 5;
    else if ((choice == "q") || (choice == "quit"))
        choiceAsNum = 6;
    else {
        std::cout << "I'm sorry, that is not an option. Please try again.\n";
        menu(userName, lastChoice);
    }

    //computer chooses which part of the program to do based on user's input
    switch (choiceAsNum)
    {
        case 1:
            calculator();
            lastChoice = 1;
            menu(userName, lastChoice);

        case 2:
            converter();
            lastChoice = 2;
            menu(userName, lastChoice);
          
        case 3:    
            gradesProcessor();
            lastChoice = 3;
            menu(userName, lastChoice);
            
        case 4:    
            stringTokenizer();
            lastChoice = 4;
            menu(userName, lastChoice);
            
        case 5:
            help(lastChoice);
            menu(userName, lastChoice);
        case 6:
            std::cout << "Thank you for using this program.";
            exit(0);
    }
}

void help(int lastChoice) {
    if (lastChoice == 1) {
        std::cout << "For the calculator, you will first be asked for the operator of the equation you would like to solve.\n";
        std::cout << "You will then be asked for two numbers you would like to put in to the equation, in order of first to second.\n";
        std::cout << "Be sure to press enter between the two numbers, and not space.\n";
        std::cout << "The calculator will then process the numbers it was given with the operator it was given.\n\n";
    }

    if (lastChoice == 2) {
        std::cout << "For the converter, you will first be asked for what you want to convert between.\n";
        std::cout << "You will have the options of converting units of speed, larger units of distance, and smaller units of distance.\n";
        std::cout << "You will then have the option to choose which unit you would like to start with.\n";
        std::cout << "Then, you will be able to put in the number of however many units you wish to start with.\n";
        std::cout << "The computer will then output the converted measurement.\n\n";
    }

    if (lastChoice == 3) {
        std::cout << "For the grades section of the junkulator, you will be asked whose overall grade you want to look at.\n";
        std::cout << "You may access the files of Omar, Hana, Tom, Nancy, and Raja.\n";
        std::cout << "You will then be shown their exact grade, along with what letter grade they have.\n\n";
    }

    if (lastChoice == 4) {
            std::cout << "For the string tokenizer, you will be asked for input.\n";
            std::cout << "The computer will then show you how many letters and words there are, it will print your input backwards, and will print all words that start with a capital letter.\n";
            std::cout << "You will then be asked for a word you want to search for in the string.\n";
            std::cout << "You will then recieve a message saying whether the word was found or not.\n\n";
    }

    if (lastChoice == 0) {
        std::cout << "You have not accessed any other parts of the junkulator. Go explore, then come back if you need help!\n";
    }

}