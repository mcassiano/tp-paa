#include "tsp.hpp"
#include "solution.hpp"


TSP::TSP(float dists[MAX_CITY][MAX_CITY], int size) {
    
    this->length = size;
    memcpy(matrix, dists, MAX_CITY*MAX_CITY*sizeof(float));
    this->solved = false;
    
    for(int i = 0; i < size; i++)
        elements.push_back(i);
}


void TSP::run_rec(Solution &current, Solution &best) {
    
    /* base case */
    if (current.isComplete()) {
        
        if (current.getCost() < best.getCost())
            best = current;
        
        return;
    }
    
    vector<int> children = current.getChildren();
    
    for (int i = 0; i < children.size(); i++) {
        Solution temp(current);
        temp.addNode(children[i]);
        
        if (temp.getCost() <= best.getCost())
            run_rec(temp, best);
        else
            return;
    }
    
}

void TSP::run() {
    
    Solution initial(this);
    initial.addNode(0);
    
    Solution best(this);
    
    run_rec(initial, best);
    
    printf("%0.2f \n", best.getCost());
    
    for (int i = 0; i < best.getTour().size(); i++) {
        printf("%d ", best.getTour()[i] + 1);
    }
    
    printf("\n");
}


int TSP::size() {
    return length;
}

vector<int> TSP::getElements() {
    return elements;
}

float TSP::getDistance(int i, int j) {
    return matrix[i][j];
}