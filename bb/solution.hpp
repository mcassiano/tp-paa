#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class TSP;

class Solution {
    
private:
    vector<int> tour;
    TSP *tsp;
    float cost;
    
public:
    Solution(TSP *tsp);
    Solution(Solution *s);
    bool isComplete();
    void addNode(int n);
    float getCost();
    vector<int> getTour();
    vector<int> getChildren();
    
};

#endif /* solution_hpp */
