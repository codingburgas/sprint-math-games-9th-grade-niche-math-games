#include <cmath>
#include "rng.h"

static unsigned int seed = 123;

void setSeed(unsigned int newSeed) {
    seed = newSeed;
}

int nextRand() {
    const unsigned int a = 1103515245;
    const unsigned int c = 12345;
    const unsigned int m = 2147483648u;

    seed = (a * seed + c) % m;
    return static_cast<int>(seed);
}

int getRandomInRange(int min, int max) { 
    int r = nextRand(); 
    int range = std::abs(max - min) + 1;
    return (r % range) + min;
}