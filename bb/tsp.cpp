#include "tsp.hpp"
#include "solution.hpp"

/**
    Construtor da classe TSP. Complexidade analisada com
    atribuições. Roda em O(n)

    @param dists matriz com as distâncias.
    @param size tamanho do problema.
*/
TSP::TSP(float dists[MAX_CITY][MAX_CITY], int size) {
    
    this->length = size;
    memcpy(matrix, dists, MAX_CITY*MAX_CITY*sizeof(float)); // O(n)
    this->solved = false;
    
    for(int i = 0; i < size; i++)
        elements.push_back(i); // O(n)
}

/**
    Função recursiva do branch and bound.
    O(n!) pior caso

    @param current solução sendo testada.
    @param best melhor solução encontrada até o momento
*/
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

/**
    Função helper para executar o algoritmo.
    O(n)
*/
void TSP::run() {
    
    Solution initial(this);
    initial.addNode(0);
    
    Solution best(this);
    
    run_rec(initial, best);
    
    printf("%0.2f \n", best.getCost());
    
    // O(n)
    for (int i = 0; i < best.getTour().size(); i++) {
        printf("%d ", best.getTour()[i] + 1);
    }
    
    printf("\n");
}


/**
    Função que devolve o tamanho do problema.
    @return int número de cidades
    O(1)
*/
int TSP::size() {
    return length;
}

/**
    Função que devolve a cidades do problema.
    @return vector<int> ids das cidades
    O(1)
*/
vector<int> TSP::getElements() {
    return elements;
}

/**
    Função que devolve a distância entre duas cidades.
    @param i cidade de partida
    @param j cidade de destino
    @return vector<int> ids das cidades
    O(1)
*/
float TSP::getDistance(int i, int j) {
    return matrix[i][j];
}