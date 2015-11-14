#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tspinfo.hpp"
#include "population.hpp"
#include "solution.hpp"
#include "ga.hpp"

class City {

public:
    int x, y;
    
    double distanceTo(City &city) {
        return sqrt(pow(city.x - this->x, 2) +  pow(city.y - this->y, 2));
    }
};

void alloc_matrix(double** &matrix, int n) {

    matrix = new double*[n];
    double *M_data = new double[n*n];

    for(int i = 0; i < n; ++i)
        matrix[i] = M_data + i * n;
}

void free_matrix(double** &matrix, int n) {


    delete[] matrix[0];
    delete[] matrix;
}

void readInput(double** &dists, City *cities, int *n) {
    
    scanf("%d", n);

    alloc_matrix(dists, *n);
    
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
    double **dists = NULL;
    City cities[MAX_CITY];

    readInput(dists, cities, &n);
    

    TSPInfo::init(dists, n);
    
    Population pop(50, true);
    pop = GA::evolvePopulation(pop);

    for (int i = 0; i < 1000; i++)
        pop = GA::evolvePopulation(pop);


    Solution sol = pop.getFittest();

    printf("%0.2f\n", sol.getCost());

    for (int i = 0; i < sol.getSize(); i++)
        printf("%d ", sol.getNode(i));

    printf("\n");

    free_matrix(dists, n);
    
    return 0;
}