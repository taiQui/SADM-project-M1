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

int Solutions::getValueByIndex(int index,vector<int> value){
  if(index >= this->_nbSolutions || index < 0) exit(-1);
  int compt = 0;
  for(int i = 0; i < value.size() ; i ++){
    if(this->_choosen[index][i] == 1){
      compt+=value[i];
    }
  }
  return compt;
}

vector<vector<int>*> Solutions::getParent(vector<int> value,int nbParent){
  nbParent *=2;
  int tab[nbParent*2];
  int index = 0;
  while(index < nbParent){
    int random = (rand()%this->_nbSolutions);
    int i = 0;
    bool good = true;
    while( i < nbParent && good){
      if (tab[i] == random ){
          good = false;
      }
      i++;
    }
    if(good){
      tab[index] = random;
      index++;
    }
  }
  for(int i = 0+nbParent; i < nbParent*2; i++){
    tab[i] = this->getValueByIndex(tab[i],value);
  }
  vector<vector<int>*> returned;
  int max = tab[nbParent];
  int indexreturned = 0;
  for(int i = 1; i < nbParent/2 ; i+=1){
    if (max < tab[nbParent+i]){
      max = tab[nbParent+i];
      indexreturned = i;
    }
  }
  returned[0]=&(this->_choosen[indexreturned]);
  max = tab[(nbParent/2)+nbParent];
  indexreturned = nbParent/2;
  for(int i = 0; i < nbParent/2 ; i++){
    if(max < tab[nbParent+(nbParent/2)+i]){
      max = tab[nbParent+(nbParent/2)+i];
      indexreturned = (nbParent/2)+i;
    }
  }
  returned[1] = &(this->_choosen[indexreturned]);
  return returned;

}
