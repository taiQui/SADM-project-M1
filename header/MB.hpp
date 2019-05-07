#ifndef MB_hpp
#define MB_hpp

#include <iostream>
#include <vector>
#include <time.h>
#include "../header/Solution.hpp"

using namespace std;

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
  int[] find() return best and worst index's solutions
  in input we have All solutions

  */
  int* find(Solutions);


};

#endif
