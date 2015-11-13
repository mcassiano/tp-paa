#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tsp.hpp"

using namespace std;

class City {

public:
    int x, y;
    
    float distanceTo(City &city) {
        return sqrt(pow(city.x - this->x, 2) +  pow(city.y - this->y, 2));
    }
};



void readInput(float dists[MAX_CITY][MAX_CITY], City *cities, int *n) {
    
    scanf("%d", n);
    
    for (int i = 0; i < *n; i++)
        scanf("%d %d", &(cities[i].x), &(cities[i].y));
    
    for (int i = 0; i < *n; i++) {
        dists[i][i] = 0;
        for (int j = 0; j < *n; j++) {
            if (i != j)
                dists[i][j] = cities[i].distanceTo(cities[j]);
        }
    }
}


int main(int argc, char **argv) {
    
    int n;
    float dists[MAX_CITY][MAX_CITY];
    City cities[MAX_CITY];
    
    readInput(dists, cities, &n);
    
    TSP tsp (dists, n);
    tsp.run();
    
    
    return 0;
}