#include <iostream>
#include <iomanip>
#include <cmath>
#include "game.h"
#include "randomizer.h"
#include "colors.h"

using namespace std;

// Ask single question and return 1 if correct, 0 if wrong
int askQuestion(int difficulty) {
    int minVal, maxVal;

    switch (difficulty) {
    case Easy:   minVal = 1;   maxVal = 10;  break;
    case Medium: minVal = 10;  maxVal = 50;  break;
    case Hard:   minVal = 50;  maxVal = 100; break;
    default:     minVal = 1;   maxVal = 10;
    }

    // Pick two random operands within difficulty range
    int leftOperand = getRandomInRange(minVal, maxVal);
    int rightOperand = getRandomInRange(minVal, maxVal);

    int operationIndex = nextRand() % 3;

    char operationSymbol;
    int answer;

    switch (operationIndex) {
    case 0: operationSymbol = '+'; answer = leftOperand + rightOperand; break;
    case 1: operationSymbol = '-'; answer = leftOperand - rightOperand; break;
    case 2: operationSymbol = '*'; answer = leftOperand * rightOperand; break;
    }

    cout << "Question: "
        << setw(3) << right << leftOperand << " "
        << operationSymbol << " " 
        << setw(3) << left << rightOperand << " = ";

    int userAnswer;

    // Read user's answer and invalid input counts as wrong
    if (!(cin >> userAnswer)) {
        cin.clear();
        char leftoverInputChar;
        while (cin.get(leftoverInputChar) && leftoverInputChar != '\n');
        cout << red << "Invalid input! Counted as wrong.\n" << reset;
        return 0;
    }

    if (userAnswer == answer) {
        cout << green << "Correct!\n" << reset;
        return 1;
    }
    else {
        cout << red << "Wrong! Correct answer was " << answer << ".\n" << reset;
        return 0;
    }
}

void playQuiz(int difficulty) {
    const int totalQuestions = 10;
    int score = 0;

    cout << "\n--- Starting Quiz ---\n";

    for (int questionIndex = 0; questionIndex < totalQuestions; ++questionIndex)
        score += askQuestion(difficulty);

    cout << "\n--- Quiz End ---\n";
    cout << "Final Score: " << score << " out of " << totalQuestions << ".\n";

    if (score == totalQuestions) {
        cout << green << "Perfect score! Amazing job!\n" << reset;
    }
    else if (score >= 7) {
        cout << green << "Great work! You did really well!\n" << reset;
    }
    else if (score >= 4) {
        cout << "Not bad, keep practicing!\n";
    }
    else {
        cout << red << "Better luck next time, don't give up!\n" << reset;
    }
}