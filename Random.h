#if !defined(RANDOM_H)
#define RANDOM_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Random
{
public:
    Random();
    int Next(int min, int max);
};

#endif // !defined(RANDOM_H)
