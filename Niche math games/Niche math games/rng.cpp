#include <cmath>
#include "rng.h"

static unsigned int currentSeed = 123u;

void setSeed(unsigned int newSeed) {
    currentSeed = newSeed;
}

int nextRand() {
    const unsigned int multiplier = 1103515245u;
    const unsigned int increment = 12345u;
    const unsigned int modulus = 2147483648u;

    currentSeed = (multiplier * currentSeed + increment) % modulus;
    return static_cast<int>(currentSeed);
}

int getRandomInRange(int min, int max) {
    int randValue = nextRand();
    int rangeSize = std::abs(max - min) + 1;
    return (randValue % rangeSize) + min;
}
