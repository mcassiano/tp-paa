#ifndef population_hpp
#define population_hpp

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "solution.hpp"

using namespace std;

class Population {

private:
	vector<Solution> solutions;

public:
	Population(int);
	Population(int, bool);
	int getSize();
	Solution& getSolution(int);
	Solution& getFittest();
	void addSolution(Solution);
    void addSolution(Solution, int);

};

#endif