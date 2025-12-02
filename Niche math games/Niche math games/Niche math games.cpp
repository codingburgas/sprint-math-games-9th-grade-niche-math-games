#include <iostream>
#include <string>
#include <cstdlib> // Added for the system() function to clear the console

using namespace std;

// Static seed for a simple, repeatable pseudo-random number generator.
static int seed = 1;

/**
 * @brief Generates the next pseudo-random integer in the range [1, 1000].
 * @return int The next pseudo-random number.
 */
int next_rand() {
    seed = (seed * 37 + 17) % 1000;
    return seed;
}

/**
 * @brief Utility function to clear the console screen for cleaner output.
 */
void clearScreen() {
    // Uses system-specific commands to clear the console, preventing
    // the previous quiz output/menu from "repeating" on screen.
#ifdef _WIN32
    system("cls");
#else
    // Works for Linux, macOS, and many other UNIX-like systems
    system("clear");
#endif
}

/**
 * @brief Asks a single arithmetic question based on the difficulty level.
 * @param difficulty 1 (Easy: 1-10), 2 (Medium: 10-50), 3 (Hard: 50-100).
 * @return int 1 if the user answers correctly, 0 otherwise.
 */
int askQuestion(int difficulty) {
    int max_val, min_val;

    // Determine the range for random numbers based on difficulty
    switch (difficulty) {
    case 1: max_val = 10; min_val = 1; break;
    case 2: max_val = 50; min_val = 10; break;
    case 3: max_val = 100; min_val = 50; break;
    default: max_val = 10; min_val = 1;
    }

    int range = max_val - min_val + 1;
    // Generate two random numbers within the determined range
    int a = (next_rand() % range) + min_val;
    int b = (next_rand() % range) + min_val;

    // Select an operation: 0=Add, 1=Subtract, 2=Multiply
    int op = next_rand() % 3;
    char op_char;
    int answer;

    switch (op) {
    case 0: op_char = '+'; answer = a + b; break;
    case 1: op_char = '-'; answer = a - b; break;
    case 2: op_char = '*'; answer = a * b; break;
    }

    // Display the question to the user
    cout << "Question: " << a << " " << op_char << " " << b << " = ";

    int userAnswer;
    // Check for valid integer input
    if (!(cin >> userAnswer)) {
        cin.clear(); // Clear error flags
        cin.ignore(10000, '\n'); // Discard invalid input
        cout << "Invalid input! Counted as wrong.\n";
        return 0;
    }

    // Check the answer
    if (userAnswer == answer) {
        cout << "Correct!\n";
        return 1;
    }
    else {
        cout << "Wrong! Correct answer was " << answer << "\n";
        return 0;
    }
}

/**
 * @brief Runs a 10-question arithmetic quiz at the specified difficulty.
 * @param difficulty The difficulty level (1, 2, or 3).
 */
void playQuiz(int difficulty) {
    int score = 0;
    const int totalQuestions = 10;

    cout << "\n--- Starting Quiz (Difficulty " << difficulty << ") ---\n";

    for (int i = 0; i < totalQuestions; i++) {
        score += askQuestion(difficulty);
    }

    cout << "\n--- Quiz End ---\n";
    cout << "Final Score: " << score << " out of " << totalQuestions << ".\n";

    // Provide feedback based on the score
    if (score == totalQuestions) {
        cout << "Perfect score! Amazing job!\n";
    }
    else if (score >= 7) {
        cout << "Great work! You did really well!\n";
    }
    else if (score >= 4) {
        cout << "Not bad, keep practicing!\n";
    }
    else {
        cout << "Better luck next time, don't give up!\n";
    }

    // Removed "Returning to menu..." as the prompt below is clearer.
}

int main() {
    int choice;

    while (true) {
        clearScreen(); // NEW: Clear the screen at the start of every loop iteration

        // ASCII art for "MATH GAME" is now inside the loop so it's always displayed
        cout << R"(
M   M   A   TTTTT H   H        GGG    A   M   M EEEEE  SSSS 
MM MM  A A    T   H   H       G      A A  MM MM E     S     
M M M AAAAA   T   HHHHH       G GG  AAAAA M M M EEEE   SSS  
M   M A   A   T   H   H       G   G A   A M   M E         S 
M   M A   A   T   H   H        GGG  A   A M   M EEEEE SSSS  
)" << '\n';

        cout << "\n=== Math Game ===\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "4. Quit\n";
        cout << "Choose option: ";

        // Attempt to read user choice
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\nInvalid input. Please enter a number from 1 to 4.\n";
            // Pause before clearing the screen and showing the menu again
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

            // NEW: Pause to allow the user to read their quiz results
            cout << "\nPress Enter to return to the menu...";
            // Consume the newline character left by the quiz input
            cin.ignore(10000, '\n');
            // Wait for user confirmation
            cin.get();
        }
        else {
            cout << "\nInvalid choice. Try again.\n";
            // Pause before clearing the screen and showing the menu again
            cout << "Press Enter to continue...";
            cin.ignore(10000, '\n');
            cin.get();
        }
    }
    return 0;
}