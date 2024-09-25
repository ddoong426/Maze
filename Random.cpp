#include "Random.h"


Random::Random()
{
    srand((time(0)));
}


int Random::Next(int min, int max) 
{
    return min + rand() % (max - min);
}