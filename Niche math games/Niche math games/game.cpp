#include <iostream>
#include <iomanip>
#include <cmath>
#include "game.h"
#include "rng.h"
#include "colors.h"

using namespace std;

int askQuestion(int difficulty) {
    int minVal, maxVal;

    switch (difficulty) {
    case Easy:   minVal = 1;   maxVal = 10;  break;
    case Medium: minVal = 10;  maxVal = 50;  break;
    case Hard:   minVal = 50;  maxVal = 100; break;
    default:     minVal = 1;   maxVal = 10;
    }

    int a = getRandomInRange(minVal, maxVal);
    int b = getRandomInRange(minVal, maxVal);

    int op = nextRand() % 3;

    char opChar;
    int answer;

    switch (op) {
    case 0: opChar = '+'; answer = a + b; break;
    case 1: opChar = '-'; answer = a - b; break;
    case 2: opChar = '*'; answer = a * b; break;
    }

    cout << "Question: "
        << setw(3) << right << a << " "
        << opChar << " " 
        << setw(3) << left << b << " = ? ";

    int userAnswer;

    if (!(cin >> userAnswer)) {
        cin.clear();
        char c;
        while (cin.get(c) && c != '\n');
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

    for (int i = 0; i < totalQuestions; i++)
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