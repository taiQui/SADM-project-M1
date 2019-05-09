#include "../header/MB.hpp"

MB::MB(int objectnumber,int bagnumber,vector<int> objectlist,vector<int> bagcapacity,vector<vector<int>>objectcharge,int verbose){
  this->_objectNumber = objectnumber;
  this->_bagNumber = bagnumber;
  this->_objectList.swap(objectlist);
  this->_bagCapacity.swap(bagcapacity);
  this->_objectCharge.swap(objectcharge);
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
  int* returned = new int[2];
  int* value = sol.getValue(this->getObjectList());
  int min = value[0];
  int max = value[0];
  cout<<"Value : "<<endl;
  for(int i =0; i < sol.getNbsol();i++){
    cout<<value[i]<<" ";
  }
  cout<<"------------------------------"<<endl;
  cout<<endl;
  cout<<"RETURN --------------"<<endl;
  int index1 = 0;
  int index2 = 0;
  for(int i = 1; i < sol.getNbsol(); i++){
    // cout<<"v : "<<value[i]<<" ";
    if(max < value[i]){
      index1 = i;
      max = value[i];
    }
    if(min > value[i]){
      index2 = i;
      min = value[i];
    }
  }
  cout<<endl;
  returned[0] = index1;
  returned[1] = index2;
  return returned;
}

vector<int> MB::crossover(vector<vector<int>*> parent){
  vector<int> random;
  vector<int> returned;
  for(int i = 0; i < this->_objectNumber ; i++){
    random.push_back(rand()%1);
  }
  for(int i = 0 ; i < this->_objectNumber; i++){
    if(random[i] == 1)
      returned.push_back(parent[1]->at(i));
    else if (random[i] == 0)
      returned.push_back(parent[0]->at(i));
  }
  return returned;
}

vector<int> MB::mutation(vector<int> child){
  for(int i = 0; i < RANDOM_FLIP ; i++){
    int random = rand()%this->_objectNumber;
    child[random] = !child[random];
  }
  return child;
}

int MB::getValueWeight(vector<int> solution,int bag){
  if(bag < 0 || bag > this->_bagNumber){
    if(this->_verbose) cout << "getValue - out of range"<<endl;
    exit(-1);
  }
  int returned = 0;
  for(int i = 0; i < this->_objectNumber ; i++ ){
      if(solution[i] == 1)
        returned+= this->_objectCharge[bag][i];
  }
  return returned;
}

bool MB::bagCheck(vector<int> weight){
  bool good = true;
  int i = 0;
  while(i < weight.size() && good){
    // cout<<"check : "<<weight[i]<<" : "<<this->_bagCapacity[i]<<endl;
    if(weight[i] > this->_bagCapacity[i]){
      return false;
    }
    i++;
  }
  return good;
}

bool MB::bagCheckAfterAdd(int object,vector<int> weightarray){
  for(int i = 0; i < weightarray.size();i++){
    weightarray[i]+=this->_objectCharge[i][object];
  }
  return(this->bagCheck(weightarray));
}

vector<int> MB::repair(vector<int> childmutated){
  int i = childmutated.size()-1;
  vector<int> weightByBag;
  for(int j = 0; j < this->_bagNumber; j++){
    weightByBag.push_back(this->getValueWeight(childmutated,j));
  }
  cout<<endl;
  cout<<"-----------------------"<<endl;
  for(int i = 0; i < weightByBag.size();i++){
    cout<<weightByBag[i]<<" ";
  }
  cout<<endl;
  cout<<"----"<<endl;
  while(i >= 0 && !this->bagCheck(weightByBag)){
    if(childmutated[i] == 1 && !this->bagCheck(weightByBag)){
      childmutated[i] = !childmutated[i];
      for(int j = 0; j < weightByBag.size();j++){
        // cout<<"sub : "<<this->_objectCharge[j][i]<<endl;
        cout<<"test : "<<weightByBag[j]<<endl;
        weightByBag[j] -= this->_objectCharge[j][i];
        cout<<"test2 : "<<weightByBag[j]<<endl;
        // cout<<"weight : "<<weightByBag.size()<<"   &&&&&&&&&&& "<<endl;
        // for(int j = 0; j < weightByBag.size();j++){
        //   cout<<weightByBag[i]<<" ";
        // }
        // cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
      }
    }
    i--;
    // cout<<"test weight : "<<this->bagCheck(weightByBag)<<endl;

  }
  cout<<"---------------------"<<endl;
  cout<<"repair "<<endl;
  for(int i = 0; i < childmutated.size();i++){
    cout<<childmutated[i]<<" ";
  }
  cout<<endl;
  for(int i = 0; i < childmutated.size();i++){
    if(childmutated[i] == 0 && this->bagCheckAfterAdd(i,weightByBag) ){
      childmutated[i] = 1;
      for(int j = 0; j < weightByBag.size() ; j++){
        weightByBag[j] += this->_objectCharge[j][i];
      }
    }
  }
  cout<<"----------------------"<<endl;
  return childmutated;
}

int MB::getValue(vector<int> child){
  int compt = 0;
  // cout<<"child : "<<endl;
  // for(int i =0; i < child.size();i++){
  //   cout<<child[i]<<" ";
  // }
  cout<<endl;
  for(int i = 0; i < child.size(); i++){
    if(child[i] == 1){
      compt+= this->_objectList[i];
    }
  }
  return compt;
}
