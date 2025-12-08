#include <cmath>
#include "randomizer.h"

static unsigned int seed = 123;

using namespace std;

void setSeed(unsigned int newSeed) {
    seed = newSeed;
}

int nextRand() {
    const unsigned int multiplier = 1103515245u;
    const unsigned int increment = 12345u;
    const unsigned int modulus = 2147483648u;

    seed = (multiplier * seed + increment) % modulus;
    return static_cast<int>(seed);
}

int getRandomInRange(int min, int max) { 
    int randomValue = nextRand(); 
    int rangeSize = abs(max - min) + 1;
    return (randomValue % rangeSize) + min;
}