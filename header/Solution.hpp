#ifndef Solution_hpp
#define Solution_hpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include "../header/MB.hpp"

class MB;

using namespace std;

class Solutions {
private:
  int _nbSolutions;
  vector<vector<int>> _choosen;
public:
  Solutions();
  Solutions(int);
  ~Solutions();

//Getter
int getNbsol();
vector<int> getChoosen(int);
int getObjectByIndex(int,int);
//Setter
void setChoosenAtIndex(int,int,int);
void setChoosen(int,vector<int>);
//function
int* getValue(vector<int>);
int getValueByIndex(int,vector<int>);
vector<vector<int>*> getParent(vector<int>,int);
bool belongTo(vector<int>);
void generate(MB*);
};

#endif
