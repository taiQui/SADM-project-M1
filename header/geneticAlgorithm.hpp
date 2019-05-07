#ifndef geneticAlgo_hpp
#define geneticAlgo_hpp

#include <iostream>
#include <vector>
#include "../header/Soluton.hpp"
#include "../header/MB.hpp"
#include <time.h>

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
			return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
		}

		bool isTimeout(unsigned long seconds) {
			return seconds >= elapsedTime();
		}
};


#endif
