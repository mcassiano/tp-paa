#include "ga.hpp"
#import "solution.hpp"
#import "population.hpp"

static const float mutationRate = 0.015;
static const int tournamentSize = 5;
static const bool elitism = true;

int rand_util_int(int from, int to) {

    static random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(from, to - 1);

    return distr(eng);
}

int rand_util_double(double from, double to) {

	static random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<> distr(from, to);

    return distr(eng);
}

Population GA::evolvePopulation(Population p) {

	Population newPopulation(p.getSize(), false);

	int offset = 0;

	if (elitism) {
		newPopulation.addSolution(p.getFittest(), 0);
		offset = 1;
	}

	/* Crossover */

	for (int i = offset; i < newPopulation.getSize(); i++) {

		Solution parent1 = tournament(p);
		Solution parent2 = tournament(p);

		Solution child = crossover(parent1, parent2);
		newPopulation.addSolution(child, i);
	}

	/* Mutation */

	for (int i = offset; i < newPopulation.getSize(); i++)
		mutate(newPopulation.getSolution(i));

	return newPopulation;

}


Solution GA::crossover(Solution parent1, Solution parent2) {

	Solution child(parent1.getSize());

	int startPos = rand_util_int(0, parent1.getSize());
	int endPos = rand_util_int(0, parent2.getSize());

	for (int i = 0; i < child.getSize(); i++) {

		if (startPos < endPos && i > startPos && i < endPos)
			child.addNode(parent1.getNode(i), i);

		else if (startPos > endPos)
			if (!(i < startPos && i > endPos))
				child.addNode(parent1.getNode(i), i);
	}

	for (int i = 0; i < parent2.getSize(); i++) {

		if (!child.isPresent(parent2.getNode(i))) {
			for (int j = 0; j < child.getSize(); j++) {

				if (child.isEmpty(j)) {
					child.addNode(parent2.getNode(i), j);
					break;
				}
			}
		}
	}

	return child;
}

void GA::mutate(Solution solution) {

	for (int i = 0; i < solution.getSize(); i++) {

		if (rand_util_double(0,1) < mutationRate) {

			int j = rand_util_int(0, solution.getSize());

			int city1 = solution.getNode(i);
			int city2 = solution.getNode(j);

			solution.addNode(city1, j);
			solution.addNode(city2, i);
		}

	}
}

Solution GA::tournament(Population population) {

	Population tournmnt(tournamentSize, false);

	for (int i = 0; i < tournamentSize; i++) {

		int id = rand_util_int(0, population.getSize());
		tournmnt.addSolution(population.getSolution(id), i);
	}

	return tournmnt.getFittest();

}