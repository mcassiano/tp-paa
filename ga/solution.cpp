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

/**
    Adiciona cidade à solução.
    O(n) comparações (recalculateCost()).

    @param int n cidade
*/
void Solution::addNode(int n) {
	tour.push_back(n);
	recalculateCost();
}

/**
    Adiciona cidade à solução.
    O(n) comparações (recalculateCost()).

    @param int n cidade
    @param int i índice
*/
void Solution::addNode(int n, int i) {
	tour[i] = n;
	recalculateCost();
}

/**
    Retorna a cidade no índice i.
    O(1).

    @param i índice da solução
    @return int cidade
*/
int Solution::getNode(int i) {
	return tour[i];
}

/**
    Verifica se a cidade n está presente na solução.
    O(n).

    @param int n cidade
    @return bool true se encontrada, false caso contrário
*/
bool Solution::isPresent(int n) {
	return find(tour.begin(), tour.end(), n) != tour.end();
}

/**
    Verifica se o índice i está ocupado.
    O(1).

    @param int i índice
    @return bool true se sim, false caso contrário
*/
bool Solution::isEmpty(int i) {
	return tour[i] == EMPTY;
}

/**
    Retorna o custo da solução.
    O(1).

    @return double custo total do caminho
*/
double Solution::getCost() {
	return cost;
}

/**
    Retorna o fitness da solução.
    O(1).

    @return double fitness da solucão
*/
double Solution::getFitness() {

	if (fitness == 0 && cost != 0)
		fitness = 1.0/cost;

	return fitness;
}

/**
    Retorna o tamanho da solução.
    O(1).

    @return int tamanho do vetor tour
*/
int Solution::getSize() {
	return (int)tour.size();
}

/**
    Calcula o custo da solução.
    O(n).
*/
void Solution::recalculateCost() {
	cost = 0;

	for (int i = 1; i < tour.size(); i++) { // O(n)

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


/**
    Gera uma solução.
    O(n).

    @return solution retorna solução gerada
*/
Solution& Solution::generate() {

	tour.clear();

	for (int i = 0; i < TSPInfo::getSize(); i++)
        addNode(i);

	random_shuffle(tour.begin(), tour.end());
    recalculateCost();
    
	return *this;
}