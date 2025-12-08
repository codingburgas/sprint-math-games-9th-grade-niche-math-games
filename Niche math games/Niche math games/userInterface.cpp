#include <iostream>
#include "userInterface.h"
#include "colors.h"

using namespace std;

void clearScreen() {
    // Print platform specific escape sequence to clear the console
    cout << clearScreenCode; 
}

void displayHeader() {
   
    // ASCII art title
    cout << R"(
N   N III  CCC  H   H EEEEE       M   M   A   TTTTT H   H        GGG    A   M   M EEEEE  SSSS 
NN  N  I  C   C H   H E           MM MM  A A    T   H   H       G      A A  MM MM E     S
N N N  I  C     HHHHH EEEE        M M M AAAAA   T   HHHHH       G GG  AAAAA M M M EEEE   SSS
N  NN  I  C   C H   H E           M   M A   A   T   H   H       G   G A   A M   M E         S 
N   N III  CCC  H   H EEEEE       M   M A   A   T   H   H        GGG  A   A M   M EEEEE SSSS
)" << endl;

    cout << "=== Math Game ===\n";
    cout << "=====================\n";
}

void displayInstructions() {
    cout << "Instructions:\n";
    cout << "1. Enter a lucky number to start the engine.\n";
    cout << "2. Choose a difficulty level.\n";
    cout << "3. Answer the math questions.\n\n";
}