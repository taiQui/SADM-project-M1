#include <iostream>
#include "header/getInput.hpp"
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
  // variables -----------------
  string filename;
  int objectNumber;
  int bagNumber;
  vector<int> objectList;
  vector<int> bagCapacity;
  vector<vector<int>> objectCharge;
  // ----------------------------
  if (argc < 3){
    cout << "2 arguments are expected"<<endl;
    exit(-1);
  }
  cout << "Filename given : "<<argv[1]<<endl;
  cout << "Time max given : "<<argv[2]<<endl;
  filename = argv[1];
  input(filename,&objectNumber,&bagNumber,&objectList,&bagCapacity,&objectCharge);
  cout << "object number "<<objectNumber<<endl;
  cout << "bagnumber "<<bagNumber<<endl;
  cout << "objectList : "<<endl;
  for(int i = 0; i < objectList.size();i++){
    cout <<objectList[i]<<"-";
  }
  cout<<endl;
  cout <<"Bag capacity : ";
  for (int i = 0; i < bagCapacity.size(); i++){
    cout << bagCapacity[i]<<"-";
  }
  cout <<endl;
  for(int i = 0; i < objectCharge.size() ; i++){
    cout <<"object constraint for bag "<<i<<" : ";
    for(int j = 0 ; j < objectCharge[i].size(); j++){
      cout <<objectCharge[i][j]<<"-";
    }
    cout <<endl;
  }
  return 0;
}
