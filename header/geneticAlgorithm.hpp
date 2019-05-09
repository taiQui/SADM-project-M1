#ifndef geneticAlgo_hpp
#define geneticAlgo_hpp

#include <iostream>
#include <vector>
#include "../header/Solution.hpp"
#include "../header/MB.hpp"
#include <time.h>
#include <fstream>

using namespace std;

//number of iteration
#define T_MAX 100


class timer {
	private:
		unsigned long begTime;
	public:
		void start() {
			begTime = clock();
		}

		unsigned long elapsedTime() {
			cout<<"test elapsedTime"<<endl;
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		int isTimeout(unsigned long seconds) {
			cout<<"test isTimeout"<<endl;
			unsigned long yolo = elapsedTime();
			cout<<"test isTimeout 2"<<endl;
			cout<<"test is : "<<(seconds >= yolo)<<endl;
			return seconds >= yolo;
		}
};

void geneticAlgorithm (int,int,vector<int>,vector<int>,vector<vector<int>>,int,int);

#endif
