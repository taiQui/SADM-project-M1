#include "../header/getInput.hpp"

void split(string arg,string value[]){
  string aux;
  int nb = 0;
  for(int i = 0; i < arg.size(); i++){
    cout <<"arg["<<i<<"] = "<<arg[i]<<endl;
    if (arg[i] == ' ' || arg[i] == '\n'){
      if (!aux.empty() && aux.find(' ') != string::npos){
        value[nb] = aux;
        cout << "aux : "<<aux <<endl;
        aux = "";
        nb+=1;
      }
    } else {
      aux += arg[i];
      cout <<"aux : "<<aux<<endl;
    }
  }
}

void input(string fileName,int* objectNumber,int* bagNumber,string* objectList, int* bagCapacity, int** objectCharge){
  ifstream file;
  file.open(fileName);
  if (file.is_open()){
    string aux;
    getline(file,aux);
    string firstSplit[2];
    split(aux,firstSplit);
    cout <<firstSplit[0]<<" "<<firstSplit[1]<<endl;
    objectNumber =  new int(stoi(firstSplit[0]));
    bagNumber = new int(stoi(firstSplit[1]));
  } else {
    cout<< "Error opening file"<<endl<<"Exit ..."<<endl;
    exit(-1);
  }
}
