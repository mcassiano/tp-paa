#include "tspinfo.hpp"

int TSPInfo::problemSize = 0;
double** TSPInfo::distances = NULL;

void TSPInfo::init(double **dists, int size) {
	distances = dists;
	problemSize = size;
}

/**
    Retorna distância entre cidade i e j.
    O(1).

    @param int i cidade1
    @param int j cidade2

    @return double distância
*/
double TSPInfo::getDistance(int i, int j) {
	return distances[i][j];
}

/**
    Retorna o tamanho do problema
    O(1).
*/
int TSPInfo::getSize() {
	return problemSize;
}