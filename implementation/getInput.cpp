#include "../header/getInput.hpp"

void split(string arg,string value[]){
  string aux;
  int nb = 0;
  for(int i = 0; i < arg.size(); i++){
    // cout <<"arg : "<<arg[i];
    // cout <<"arg["<<i<<"] = "<<(int)arg[i]<<endl;
    if ((int)arg[i] == 32 || arg[i] == '\n'){
      if (!aux.empty()){
        value[nb] = aux;
        // cout << "aux : "<<aux <<endl;
        aux.clear();
        nb+=1;
      }
    } else {
      aux += arg[i];
      // cout <<"aux : "<<aux<<endl;
    }

    // cout <<"test : "<<aux<<endl;
  }
  cout<<"last : "<<(int)aux[aux.size()-1]<<endl;
  if((int)aux[aux.size()-1] != 32 && (int)aux[aux.size()-1] != 0 ){
    value[nb] = aux;
  }
}

void input(string fileName,int* objectNumber,int* bagNumber,vector<int>* objectList, vector<int>* bagCapacity, vector<vector<int>>* objectCharge){
  ifstream file;
  file.open(fileName);
  if (file.is_open()){
    cout<<"test"<<endl;
    string aux;
    cout<<"test2"<<endl;
    getline(file,aux);
    cout<<"test3"<<endl;
    string firstSplit[2];
    // Parsing first row
    cout <<"STEP 1 -----"<<endl;
    split(aux,firstSplit);
    cout <<firstSplit[0]<<" "<<firstSplit[1]<<endl;
    *objectNumber = stoi(firstSplit[0]);
    *bagNumber = stoi(firstSplit[1]);
    // parsing object weight
    cout <<"STEP 2 ------"<<endl;
    for(int i = 0; i < *(objectNumber)/10 ; i++){
      aux.clear();
      getline(file,aux);
      string secondSplit[10];
      split(aux,secondSplit);
      for(int j = 0 ; j < 10 ; j++){
        objectList->push_back(stoi(secondSplit[j]));
      }
    }
    // empty getline
    getline(file,aux);
    aux.clear();
    // bag capacity
    cout << "STEP 3 ------"<<endl;
    int del = *bagNumber==5?10:*bagNumber;
    for(int i = 0; i < del/10 ; i++){
      int delimiter = *bagNumber==5?5:10;
      getline(file,aux);
      string thirdSplit[delimiter];
      split(aux,thirdSplit);
      for(int j = 0; j < delimiter; j++){
        bagCapacity->push_back(stoi(thirdSplit[j]));
      }
    }
    // empty line
    getline(file,aux);
    aux.clear();
    // object constraint through bag
    cout<<"STEP 4 ------"<<endl;
    for(int i = 0 ; i < *bagNumber ; i++){
      vector<int> raw;
      for(int j = 0 ; j < (*objectNumber)/10; j++ ){
        aux.clear();
        getline(file,aux);
        string secondSplit[10];
        split(aux,secondSplit);
        for(int k = 0 ; k < 10 ; k++){
          raw.push_back(stoi(secondSplit[k]));
        }
      }
      objectCharge->push_back(raw);
      // empty line
      getline(file,aux);
    }

  } else {
    cout<< "Error opening file"<<endl<<"Exit ..."<<endl;
    exit(-1);
  }
}
