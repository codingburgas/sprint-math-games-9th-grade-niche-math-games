#include <iostream>
#include <cmath>
#include "ui.h"
#include "rng.h" 
#include "game.h" 
#include "colors.h" 

using namespace std;

int main() {
    clearScreen();
    displayHeader();

    cout << "Enter a lucky number to seed the random generator: ";
    int userSeed;

    if (cin >> userSeed) {
        setSeed(static_cast<unsigned int>(std::abs(userSeed)));
    }
    else {
        cin.clear();
        char c; while (cin.get(c) && c != '\n');
        setSeed(12345);
    }

    int choice;
    while (true) {
        clearScreen();
        displayHeader();
        displayInstructions();

        cout << "---------------------\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Quit\n";
        cout << "Choose option: ";

        if (!(cin >> choice)) {
            cin.clear();
            char c; while (cin.get(c) && c != '\n');
            cout << red << "\nInvalid input. Please enter a number from 1 to 4.\n" << reset;
            cout << "Press Enter to continue...";
            cin.get();
            continue;
        }

        if (choice == 4) {
            cout << "Thanks for playing!\n";
            break;
        }
        else if (choice >= 1 && choice <= 3) {
            playQuiz(choice);
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
        else {
            cout << red << "\nInvalid choice. Try again.\n" << reset;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}