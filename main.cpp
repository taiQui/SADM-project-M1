#include <iostream>
#include "header/getInput.hpp"

using namespace std;

int main(int argc, char* argv[]){

  // variables -----------------
  string filename;
  int objectNumber;
  int bagNumber;
  string* objectList = NULL;
  int* bagCapacity = NULL;
  int** objectCharge = NULL;
  // ----------------------------
  if (argc < 3){
    cout << "2 arguments are expected"<<endl;
    exit(-1);
  }
  cout << "Filename given : "<<argv[1]<<endl;
  cout << "Time max given : "<<argv[2]<<endl;
  filename = argv[1];
  input(filename,&objectNumber,&bagNumber,objectList,bagCapacity,objectCharge);
  cout << "object number "<<objectNumber<<endl;
  cout << "bagnumber "<<bagNumber<<endl;
  return 0;
}
