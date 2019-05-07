#include "../header/Solution.hpp"

// Basic Constructor
Solutions::Solutions(){
    this->_nbSolutions = 100;
}

// Special Constructor
Solutions::Solutions(int nbElement){
  this->_nbSolutions = nbElement;
}

vector<int> Solutions::getChoosen(int index){
  if(index < this->_nbSolutions && index >= 0)
    return this->_choosen[index];
}

int Solutions::getObjectByIndex(int indexsol,int object){
  if( indexsol < this->_choosen.size() && object < this->_choosen[0].size()) return this->_choosen[indexsol][object];
  cout <<"getChoosenByIndex - index out of range"<<endl;
  exit(-1);
}

void Solutions::setChoosenAtIndex(int indexsol,int object,int elt){
  this->_choosen[indexsol][object] = elt;
}

int* Solutions::getValue(vector<int> value){
  int* returned = new int[this->_nbSolutions];
  for(int i = 0; i < this->_nbSolutions; i++){
    int compt = 0;
    for(int j = 0; j < value.size(); j++){
      if(this->_choosen[i][j] == 1){
        compt += value[j];
      }
    }
    returned[i] = compt;
  }
  return returned;
}
int Solutions::getNbsol(){
  return this->_nbSolutions;
}

vector<vector<int>*> Solutions::getParent(){

}
