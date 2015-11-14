#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>
#include <vector>

#define EMPTY -1

using namespace std;

class Solution {
    
private:
    vector<int> tour;
    double fitness;
    double cost;
    void recalculateCost();
    
public:
	Solution();
	Solution(int);
    void addNode(int);
    void addNode(int, int);
    int getNode(int);
    bool isPresent(int);
    bool isEmpty(int);
    double getCost();
    double getFitness();
    int getSize();
    Solution& generate();
    
};

#endif