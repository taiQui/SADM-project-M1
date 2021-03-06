#include "../header/Solution.hpp"

// Basic Constructor
Solutions::Solutions(){
  cout<<"Solutions Number : 15"<<endl;
    this->_nbSolutions = 15;
}

// Special Constructor
Solutions::Solutions(int nbElement){
  this->_nbSolutions = nbElement;
}

Solutions::~Solutions(){

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
  int j = 0;
  for(int i = 0+nbParent; i < nbParent*2; i++){
    tab[i] = this->getValueByIndex(tab[j],value);
    j++;
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
  returned.push_back(&(this->_choosen[indexreturned]));
  max = tab[(nbParent/2)+nbParent];
  indexreturned = nbParent/2;
  for(int i = 0; i < nbParent/2 ; i++){
    if(max < tab[nbParent+(nbParent/2)+i]){
      max = tab[nbParent+(nbParent/2)+i];
      indexreturned = (nbParent/2)+i;
    }
  }
  returned.push_back(&(this->_choosen[indexreturned]));
  return returned;

}

bool Solutions::belongTo(vector<int> child){
  bool good = false;
  int i = 0;
  while(i < this->_choosen.size() && !good){
    if(child == this->_choosen[i]){
      good = true;
    }
    i++;
  }
  return good;
}

void Solutions::setChoosen(int index,vector<int> replacement){
  if(index > this->_nbSolutions) exit(-1);
  this->_choosen[index].swap(replacement);
}

void Solutions::generate(MB* multi){
  for(int i = 0; i < this->_nbSolutions; i++){
    vector<int> aux;
    for(int j = 0; j < multi->getObjectNumber(); j++){
      int random = rand()%2;
      // cout<<"rand : "<<random<<endl;
      aux.push_back(random);
    }
    this->_choosen.push_back(multi->repair(aux));
  }
}
