CC = g++
CXX = g++
CXXFLAGS =  -g -Wall $(INCLUDES)
LDFLAGS = -g

main: main.o tsp.o solution.o
main.o: main.cpp
tsp.o: tsp.cpp tsp.hpp
solution.o: solution.cpp solution.hpp

.PHONY: clean
clean:
	rm -f *.o *~a.out *.gch main
