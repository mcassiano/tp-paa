#include "solution.hpp"
#include "tsp.hpp"


Solution::Solution(TSP *tsp) {
    this->tsp = tsp;
    cost = 0;
}

Solution::Solution(Solution *s) {
    this->tsp = s->tsp;
    this->tour = s->tour;
    this->cost = s->cost;
}

bool Solution::isComplete() {
    return (tour.size() == tsp->size());
}

void Solution::addNode(int n) {
    
    if (tour.empty())
        tour.push_back(n);
    
    else {
        int i = tour.back();
        cost += tsp->getDistance(i, n);
        tour.push_back(n);
    }
    
}

float Solution::getCost() {
    
    if (tour.empty())
        return INF;
    
    /* have to add the cost to go from the last
     * one to the first one */
    
    int i = tour.back();
    int j = tour.front();
    
    return cost + tsp->getDistance(i, j);
}

vector<int> Solution::getTour() {
    return tour;
}

vector<int> Solution::getChildren() {
    
    vector<int> aux_el = tsp->getElements();
    vector<int> aux_tour = tour;
    vector<int> complement(tsp->size());
    vector<int>::iterator it;
    
    sort(aux_tour.begin(), aux_tour.end());
    
    it = set_difference(aux_el.begin(), aux_el.end(),
                        aux_tour.begin(), aux_tour.end(), complement.begin());
    
    complement.resize(it - complement.begin());
    
    return complement;
}