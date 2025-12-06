#ifndef RNG_H
#define RNG_H

void setSeed(unsigned int newSeed);
int nextRand();
int getRandomInRange(int min, int max);

#endif