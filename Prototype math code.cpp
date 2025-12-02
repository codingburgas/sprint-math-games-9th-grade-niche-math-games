#include <iomanip>
#include <cmath>
using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[36m"; // light blue

int askQuestion(int difficulty) {
    int a, b, answer, userAnswer;

    // Simple pseudo-random generator (no <cstdlib>/<ctime>)
    static int seed = 1;
    seed = (seed * 37 + 17) % 1000;

    switch (difficulty) {
    case 1: // Easy
        a = (seed % 10) + 1;
        b = ((seed / 10) % 10) + 1;
        break;
    case 2: // Medium
        a = (seed % 50) + 10;
        b = ((seed / 10) % 50) + 10;
        break;
    case 3: // Hard
        a = (seed % 100) + 50;
        b = ((seed / 10) % 100) + 50;
        break;
    default:
        a = b = 1;
    }

    int op = seed % 3; // 0=+, 1=-, 2=*
    cout << BLUE << "Question: ";
    switch (op) {
    case 0:
        cout << a << " + " << b << " = ";
        answer = a + b;
        break;
    case 1:
        cout << a << " - " << b << " = ";
        answer = a - b;
        break;
    case 2:
        cout << a << " * " << b << " = ";
        answer = a * b;
        break;
    }
    cout << RESET;

    cin >> userAnswer;
    if (!cin) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << RED << "Invalid input! Counted as wrong.\n" << RESET;
        return 0;
    }

    if (userAnswer == answer) {
        cout << GREEN << "Correct!\n" << RESET;
        return 1;
    }
    else {
        cout << RED << "Wrong! Correct answer was " << answer << "\n" << RESET;
        return 0;
    }
}

void playQuiz(int difficulty) {
    int score = 0;
    cout << "\n--- Starting Quiz ---\n";
    for (int i = 0; i < 10; i++) {
        score += askQuestion(difficulty);
    }

    cout << "\nYou scored " << score << " out of 10!\n";

    if (score == 10) {
        cout << GREEN << "Perfect score! Amazing job!\n" << RESET;
    }
    else if (score >= 7) {
        cout << GREEN << "Great work! You did really well!\n" << RESET;
    }
    else if (score >= 4) {
        cout << BLUE << "Not bad, keep practicing!\n" << RESET;
    }
    else {
        cout << RED << "Better luck next time, don't give up!\n" << RESET;
    }

    cout << "\nReturning to menu...\n\n";
}

int main() {
    int choice;

    while (true) {
        cout << "=== Math Quiz Game ===\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Quit\n";
        cout << "Choose difficulty: ";
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << RED << "Invalid input. Try again.\n\n" << RESET;
            continue;
        }

        if (choice == 4) {
            cout << "Thanks for playing!\n";
            break; // no return, just exit loop
        }
        else if (choice >= 1 && choice <= 3) {
            playQuiz(choice);
        }
        else {
            cout << RED << "Invalid choice. Try again.\n\n" << RESET;
        }
    }
}