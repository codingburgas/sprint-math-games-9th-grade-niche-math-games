#ifndef RNG_H
#define RNG_H

// Simple functions for working with random numbers
void setSeed(unsigned int newSeed);
int nextRand();
int getRandomInRange(int min, int max);

#endif