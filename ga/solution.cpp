#import "solution.hpp"
#import "tspinfo.hpp"

Solution::Solution() {
	fitness = 0;
	cost = 0;
}

Solution::Solution(int size) {
	fitness = 0;
	cost = 0;
	tour = vector<int>(size, -1);
}


void Solution::addNode(int n) {
	tour.push_back(n);
	recalculateCost();
}

void Solution::addNode(int n, int i) {
	tour[i] = n;
	recalculateCost();
}

int Solution::getNode(int i) {
	return tour[i];
}

bool Solution::isPresent(int n) {
	return find(tour.begin(), tour.end(), n) != tour.end();
}

bool Solution::isEmpty(int i) {
	return tour[i] == EMPTY;
}

double Solution::getCost() {
	return cost;
}

double Solution::getFitness() {

	if (fitness == 0 && cost != 0)
		fitness = 1.0/cost;

	return fitness;
}

int Solution::getSize() {
	return (int)tour.size();
}

void Solution::recalculateCost() {
	cost = 0;

	for (int i = 1; i < tour.size(); i++) {

		if (!(isEmpty(i - 1) || isEmpty(i)))
			cost += TSPInfo::getDistance(tour[i - 1], tour[i]);

		/* not a valid solution */
		else {
			cost = INT_MAX;
            break;
		}
	}
    
    if (cost != INT_MAX)
        cost += TSPInfo::getDistance(tour.back(), tour.front());
}

Solution& Solution::generate() {

	tour.clear();

	for (int i = 0; i < TSPInfo::getSize(); i++)
        addNode(i);

	random_shuffle(tour.begin(), tour.end());
    recalculateCost();
    
	return *this;
}