#ifndef ga_hpp
#define ga_hpp

#include <stdio.h>
#include <stdlib.h>
#include <random>

using namespace std;

class Population;
class Solution;

class GA {

private:
	static Solution tournament(Population);
	static void mutate(Solution);


public:
	static Population evolvePopulation(Population);
	static Solution crossover(Solution, Solution);

};

#endif