#ifndef Solution_hpp
#define Solution_hpp

#include <iostream>
#include <vector>
#include <cstdlib>
#include "../header/MB.hpp"

class MB;

using namespace std;

class Solutions {
private:
  int _nbSolutions;
  vector<vector<int>> _choosen;
public:
  Solutions();
  Solutions(int);
  ~Solutions();

//Getter
/*
    getNbsol retournes la valeurs de l'attributs _nbSolutions
    getChoosen retournes la solutions se trouvant a l'index passé en paramètre
    getObjectByIndex retournes si l'objet a l'index passé en parametre de la solutions a l'index passé en parametre, est utilisé ou passé
    setCHoosenAtIndex place a l'index de la solutions passé en parametre l'elements passé en parametre a l'objets passé en parametre
    setChoosen place a l'index donné en parametre la solutions donné en parametre
    getValue retournes un tableau comprenant le score de toute les Solutions
    getValueByIndex retournes le score de la solutions a l'index passé en parametre
    getParent retournes les 2 parents choisis
    belongTo retournes un booleen suivant si le vecteur passé en parametre appartient a l'ensemble des Solutions
    generate genere un ensemble de solutions de manière aléatoire
*/
int getNbsol();
vector<int> getChoosen(int);
int getObjectByIndex(int,int);
//Setter
void setChoosenAtIndex(int,int,int);
void setChoosen(int,vector<int>);
//function
int* getValue(vector<int>);
int getValueByIndex(int,vector<int>);
vector<vector<int>*> getParent(vector<int>,int);
bool belongTo(vector<int>);
void generate(MB*);
};

#endif
