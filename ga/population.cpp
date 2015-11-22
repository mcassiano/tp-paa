#import "population.hpp"

Population::Population(int size) {

	solutions = vector<Solution>(size);
}

Population::Population(int size, bool init) {

	solutions = vector<Solution>(size);

	if (init) {
		
		for (int i = 0; i < size; i++) {
			Solution sol;
			solutions[i] = sol.generate();
		}
	}
}

/**
    Retorna o tamanho da população.
    O(1).
*/
int Population::getSize() {

	return (int)solutions.size();
}

/**
    Retorna uma solução no índice i.
    O(1).

    @param i índice da solução
    @return referência para a solução
*/
Solution& Population::getSolution(int i) {

	return solutions[i];
}

/**
    Retorna a solução com menor cursto da população.
    O(n) comparações.

    @return solução de menor custo
*/
Solution& Population::getFittest() {

	Solution &fittest = solutions[0];

	for (int i = 1; i < solutions.size(); i++)
		if (fittest.getFitness() <= solutions[i].getFitness())
			fittest = solutions[i];

	return fittest;
}

/**
    Adiciona solução à população.
    O(1) atribuições (pode ser O(n) se houver resize).
*/
void Population::addSolution(Solution solution) {

	solutions.push_back(solution);
}

/**
    Adiciona solução à população na posição i.
    O(1) atribuições.
*/
void Population::addSolution(Solution solution, int i) {
    
    solutions[i] = solution;
}