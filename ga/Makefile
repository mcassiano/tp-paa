CC = g++
CXX = g++
CXXFLAGS =  -g -Wall $(INCLUDES)
LDFLAGS = -g

main: population.o solution.o ga.o tspinfo.o main.o
main.o: main.cpp
ga.o: ga.cpp ga.hpp
population.o: population.cpp population.hpp
solution.o: solution.cpp solution.hpp
tspinfo.o: tspinfo.cpp tspinfo.hpp

.PHONY: clean
clean:
	rm -f *.o *~a.out *.gch main
