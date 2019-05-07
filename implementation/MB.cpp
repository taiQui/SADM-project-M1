#include "../header/MB.hpp"

MB::MB(int objectnumber,int bagnumber,vector<int> objectlist,vector<int> bagcapacity,vector<vector<int>>objectcharge,int verbose){
  this->_objectNumber = objectnumber;
  this->_bagNumber = bagnumber;
  this->_objectList = objectlist;
  this->_bagCapacity = bagcapacity;
  this->_objectCharge = objectcharge;
  this->_verbose = verbose;
}

int MB::getObjectNumber(){ return this->_objectNumber; }

int MB::getBagNumber(){ return this->_bagNumber; }

vector<int> MB::getObjectList(){ return this->_objectList; }

int MB::getObjectListByIndex(int index){
  if(index < 0 || index > this->_objectList.size()){
    if(this->_verbose) cout<<"GetObjectByIndex - Index out of range"<<endl;
    return -1;
  }
  return this->_objectList[index];
}

vector<int> MB::getBagCapacity(){
  return this->_bagCapacity;
}

int MB::getBagCapacityByIndex(int index){
  if(index < 0 || index > this->_bagCapacity.size()){
    if(this->_verbose) cout << "GetBagCapacityByIndex - Index out of range"<<endl;
    exit(-1);
  }
  return this->_bagCapacity[index];
}

vector<vector<int>> MB::getObjectCharge(){
  return this->_objectCharge;
}

int MB::getObjectChargeByBag(int bag,int object){
  if(bag < 0 || bag > this->_objectNumber){
    if(this->_verbose) cout << "getObjectChargeByBag - index out of range : bag"<<endl;
    exit(-1);
  }
  if(object < 0 || object > this->_objectNumber){
    if(this->_verbose) cout << "getObjectChargeByBag - index out of range : object"<<endl;
    exit(-1);
  }
  return this->_objectCharge[bag][object];
}

int* MB::find(Solutions sol){
  int returned[2];
  int* value = sol.getValue(this->getObjectList());
  int min = value[0];
  int max = value[0];
  for(int i = 1; i < sol.getNbsol(); i++){
    if(value[i] > max) returned[1] = i;
    if(value[i] < min) returned[0] = i;
  }
  return returned;
}
