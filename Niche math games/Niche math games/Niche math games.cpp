#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // for seeding random numbers
using namespace std;

// ANSI escape codes for colors
const string RESET = "\033[0m";
const string GREEN = "\033[32m"; // Green for correct answers
const string RED = "\033[31m";   // Red for wrong answers

enum Difficulty { EASY = 1, MEDIUM, HARD };

static int seed = time(0) % 1000; // Seed based on current time

int next_rand() {
    seed = (seed * 37 + 17) % 1000;
    return seed;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayHeader() {
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

void displayFooter() {
    cout << "=====================\n";
}

void displayInstructions() {
    cout << "Instructions:\n";
    cout << "1. Choose a difficulty level (Easy, Medium, Hard).\n";
    cout << "2. Answer the math questions by typing the answer and pressing Enter.\n";
    cout << "3. You will receive feedback on your answers at the end of the quiz.\n\n";
}

int askQuestion(int difficulty) {
    int max_val, min_val;
    switch (difficulty) {
    case EASY: max_val = 10; min_val = 1; break;
    case MEDIUM: max_val = 50; min_val = 10; break;
    case HARD: max_val = 100; min_val = 50; break;
    default: max_val = 10; min_val = 1;
    }

    int range = max_val - min_val + 1;
    int a = (next_rand() % range) + min_val;
    int b = (next_rand() % range) + min_val;
    int op = next_rand() % 3;
    char op_char;
    int answer;

    switch (op) {
    case 0: op_char = '+'; answer = a + b; break;
    case 1: op_char = '-'; answer = a - b; break;
    case 2: op_char = '*'; answer = a * b; break;
    }

    cout << "Question: " << a << " " << op_char << " " << b << " = ?\n";
    int userAnswer;
    if (!(cin >> userAnswer)) {
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
        cout << RED << "Wrong! Correct answer was " << answer << ".\n" << RESET;
        return 0;
    }
}

void playQuiz(int difficulty) {
    int score = 0;
    const int totalQuestions = 10;
    cout << "\n--- Starting Quiz (Difficulty " << difficulty << ") ---\n";
    for (int i = 0; i < totalQuestions; i++) {
        score += askQuestion(difficulty);
    }
    cout << "\n--- Quiz End ---\n";
    cout << "Final Score: " << score << " out of " << totalQuestions << ".\n";
    if (score == totalQuestions) {
        cout << GREEN << "Perfect score! Amazing job!\n" << RESET;
    }
    else if (score >= 7) {
        cout << GREEN << "Great work! You did really well!\n" << RESET;
    }
    else if (score >= 4) {
        cout << "Not bad, keep practicing!\n";
    }
    else {
        cout << RED << "Better luck next time, don't give up!\n" << RESET;
    }
}

int main() {
    int choice;
    while (true) {
        clearScreen();
        displayHeader();
        displayInstructions();
        cout << "Choose difficulty level:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Quit\n";
        cout << "Choose option: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << RED << "\nInvalid input. Please enter a number from 1 to 4.\n" << RESET;
            cout << "Press Enter to continue...";
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 4) {
            cout << "Thanks for playing!\n";
            break;
        }
        else if (choice >= 1 && choice <= 3) {
            playQuiz(choice);
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(10000, '\n');
            cin.get();
        }
        else {
            cout << RED << "\nInvalid choice. Try again.\n" << RESET;
            cout << "Press Enter to continue...";
            cin.ignore(10000, '\n');
            cin.get();
        }
    }
    return 0;
}