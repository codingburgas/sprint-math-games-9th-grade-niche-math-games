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

    cout << "Enter a lucky number to seed the generator: ";
    int userSeed;

    if (cin >> userSeed)
        setSeed(abs(userSeed));
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
        cout << "1. Easy\n2. Medium\n3. Hard\n4. Quit\n";
        cout << "Choose option: ";

        if (!(cin >> choice)) {
            cin.clear();
            char c; while (cin.get(c) && c != '\n');
            cout << RED << "Invalid input.\n" << RESET;
            cin.get();
            continue;
        }

        if (choice == 4) {
            cout << "Thanks for playing!\n";
            break;
        }

        if (choice >= 1 && choice <= 3) {
            playQuiz(choice);
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        else {
            cout << RED << "Invalid choice.\n" << RESET;
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
