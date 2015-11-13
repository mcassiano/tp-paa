#ifndef tsp_hpp
#define tsp_hpp

#include <stdio.h>
#include <vector>

using namespace std;

#define INF 32767
#define MAX_CITY 100

class Solution;

class TSP {
    
private:
    int length;
    float matrix[MAX_CITY][MAX_CITY];
    bool solved;
    
    vector<int> elements;
    
public:
    
    TSP(float dists[MAX_CITY][MAX_CITY], int size);
    void run();
    void run_rec(Solution &current, Solution &best);
    int size();
    float getDistance(int i, int j);
    vector<int> getElements();
    
};

#endif /* tsp_hpp */
