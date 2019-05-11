#ifndef geneticAlgo_hpp
#define geneticAlgo_hpp

#include <iostream>
#include <vector>
#include "../header/Solution.hpp"
#include "../header/MB.hpp"
#include <time.h>
#include <fstream>
#include <ctime>


using namespace std;
//number of iteration
#define T_MAX 100000

int elapsedTime(clock_t);

void geneticAlgorithm (int,int,vector<int>,vector<int>,vector<vector<int>>,int,int);

#endif
