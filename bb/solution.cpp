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

/**
    Diz se a solução é completa.
    O(1)

    @return bool se tour contém todas as cidades
*/
bool Solution::isComplete() {
    return (tour.size() == tsp->size());
}

/**
    Retorna o custo da solução.
    O(1)

    @return float soma das distâncias
*/
void Solution::addNode(int n) {
    
    if (tour.empty())
        tour.push_back(n);
    
    else {
        int i = tour.back();
        cost += tsp->getDistance(i, n);
        tour.push_back(n);
    }
    
}

/**
    Retorna o custo da solução.
    O(1)

    @return float soma das distâncias
*/
float Solution::getCost() {
    
    if (tour.empty())
        return INF;
    
    /* have to add the cost to go from the last
     * one to the first one */
    
    int i = tour.back();
    int j = tour.front();
    
    return cost + tsp->getDistance(i, j);
}

/**
    Retorna o tour da solução.
    O(1)

    @return vector<int> tour relativo à solução
*/
vector<int> Solution::getTour() {
    return tour;
}

/**
    Econtra o complemento da solução atual.
    Roda em O(nlogn) no pior caso.

    @param current solução sendo testada.
    @param best melhor solução encontrada até o momento
*/
vector<int> Solution::getChildren() {
    
    vector<int> aux_el = tsp->getElements();
    vector<int> aux_tour = tour;
    vector<int> complement(tsp->size());
    vector<int>::iterator it;
    
    sort(aux_tour.begin(), aux_tour.end()); // O(nlogn)
    
    // T(n) = 2*(count1+count2)-1
    it = set_difference(aux_el.begin(), aux_el.end(),
                        aux_tour.begin(), aux_tour.end(), complement.begin());
    
    complement.resize(it - complement.begin());
    
    return complement;
}