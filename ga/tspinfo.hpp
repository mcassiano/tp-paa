#ifndef tspinfo_hpp
#define tspinfo_hpp

#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#define MAX_CITY 100

class TSPInfo {

private:
	static int problemSize;
	static double **distances;

	TSPInfo();
	TSPInfo(TSPInfo const&);
    void operator=(TSPInfo const&);

public:

	static void init(double **, int);
	static double getDistance(int, int);
	static int getSize();

};

#endif 