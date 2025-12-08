#ifndef GAME_H
#define GAME_H

// Functions for asking questions and running the quiz

enum Difficulty { Easy = 1, Medium, Hard };

int askQuestion(int difficulty);
void playQuiz(int difficulty);

#endif