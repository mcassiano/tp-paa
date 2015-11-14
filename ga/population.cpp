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

int Population::getSize() {

	return (int)solutions.size();
}

Solution& Population::getSolution(int i) {

	return solutions[i];
}

Solution& Population::getFittest() {

	Solution &fittest = solutions[0];

	for (int i = 1; i < solutions.size(); i++)
		if (fittest.getFitness() <= solutions[i].getFitness())
			fittest = solutions[i];

	return fittest;
}

void Population::addSolution(Solution solution) {

	solutions.push_back(solution);
}

void Population::addSolution(Solution solution, int i) {
    
    solutions[i] = solution;
}