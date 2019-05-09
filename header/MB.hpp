#ifndef MB_hpp
#define MB_hpp

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "../header/Solution.hpp"

using namespace std;

class Solutions;

#define RANDOM_FLIP 2

//Multidimentionnal bag

class MB{
private:
  int _objectNumber;
  int _bagNumber;
  vector<int> _objectList;
  vector<int> _bagCapacity;
  vector<vector<int>> _objectCharge;
  int _verbose;

public:
  MB(int,int,vector<int>,vector<int>,vector<vector<int>>,int);
  //Getter
  int getObjectNumber();
  int getBagNumber();
  vector<int> getObjectList();
  int getObjectListByIndex(int);
  vector<int> getBagCapacity();
  int getBagCapacityByIndex(int);
  vector<vector<int>> getObjectCharge();
  int getObjectChargeByBag(int,int);
  //function
  /*
  find return best and worst index's solutions
  in input we have All solutions

  crossover return child from 2 parents get from solutions
  in input we have 2 parent

  mutation return child mutated where some bit are flipped
  in input we have child

  getValueWeigt return for a input object array the weight associated

  bagcheck return if input array weight is greather than bag capacity

  bagcheckafteradd return if after a adding object if capacity is still good

  repair return mutatedchild which respect constraint
  */
  int getValueWeight(vector<int>,int);
  int* find(Solutions);
  vector<int> crossover(vector<vector<int>*>);
  vector<int> mutation(vector<int>);
  vector<int> repair(vector<int>);
  bool bagCheck(vector<int>);
  bool bagCheckAfterAdd(int,vector<int>);
  int getValue(vector<int>); // same as getValue from Solutions's class

};

#endif
