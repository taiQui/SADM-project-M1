#include <iostream>
#include "header/getInput.hpp"
#include <vector>
// #include <pthread.h>
#include <thread>
// #include <ctime>
#include <time.h>
#include "header/geneticAlgorithm.hpp"

using namespace std;


int main(int argc, char* argv[]){
  if (argc < 3){
    cout << "2 arguments are expected"<<endl;
    exit(-1);
  }
  cout << "Filename given : "<<argv[1]<<endl;
  cout << "Time max given : "<<argv[2]<<endl;
  // variables -----------------
  string filename;
  filename = argv[1];
  int decompte = stoi(argv[2]);
  int objectNumber;
  int bagNumber;
  vector<int> objectList;
  vector<int> bagCapacity;
  vector<vector<int>> objectCharge;

  // ----------------------------
  cout<<"Executing parsing"<<endl;
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
	cout<<endl<<endl;
	geneticAlgorithm(objectNumber,bagNumber,objectList,bagCapacity,objectCharge,decompte,1);
  //to get time
  // while (chrono.elapsedTime() < decompte){
  //
  // }
  return 0;
}
