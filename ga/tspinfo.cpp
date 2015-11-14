#include "tspinfo.hpp"

int TSPInfo::problemSize = 0;
double** TSPInfo::distances = NULL;

void TSPInfo::init(double **dists, int size) {
	distances = dists;
	problemSize = size;
}

double TSPInfo::getDistance(int i, int j) {
	return distances[i][j];
}

int TSPInfo::getSize() {
	return problemSize;
}