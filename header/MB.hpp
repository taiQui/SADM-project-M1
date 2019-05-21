#ifndef MB_hpp
#define MB_hpp

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "../header/Solution.hpp"

using namespace std;

class Solutions;

#define RANDOM_FLIP 1

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
  find retournes l'index de la pire et de la meilleure solutions
  crossover retournes un enfants engendré par les 2 parents
  mutation retournes l'enfant passé en paramètre mais muté
  getValueWeigt retournes un tableau comportant la valeurs des sac a dos
  bagcheck retournes un booleen suivant si les capacité des sac est depassé ou pas
  bagcheckafteradd retournes un boolean suivant si la capacité des sac est depassé ou pas apres un ajouts
  repair retournes l'enfant muté respectant les contraintes
  getValue retournes la valeurs d'une solutions passé en parametre
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
