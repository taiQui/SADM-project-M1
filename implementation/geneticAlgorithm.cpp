#include "../header/geneticAlgorithm.hpp"



void geneticAlgorithm (int objectnumber, int bagnumber, vector<int> objectlist,vector<int> bagcapacity, vector<vector<int>> objectcharge,int tm,int verbose){
  /* Variable definitions
  */
  srand(time(NULL));
  clock_t start = clock();
  MB* MultidimentionnalBackpack = new MB(objectnumber,bagnumber,objectlist,bagcapacity,objectcharge,1);
  int compt = 0;
  //Solution's generation
  Solutions solutions;
  solutions.generate(MultidimentionnalBackpack);
  // get Best solutions before executing to compare
  int* bestaux = NULL;
  bestaux = MultidimentionnalBackpack->find(solutions);
  // get best solutions from our list
  vector<int> best = solutions.getChoosen(bestaux[1]);
  cout <<"Before executing algorithm, our first solutions is : "<<MultidimentionnalBackpack->getValue(best)<<endl;
  delete[] bestaux;
  best.clear();
  int time_useless = 0;
  while(elapsedTime(start) < tm && compt < T_MAX ){
    // Get 2 parents from genetic algorithmique technique
    // cout<<time_useless<<endl;
    vector<int> child;
    if(time_useless > 8000){
      cout<<"No more better solutions in 8000 iterations - BREAK"<<endl;
      break;
    } else if(time_useless > 1500){
      vector<vector<int>*> parent = solutions.getParent(MultidimentionnalBackpack->getObjectList(),solutions.getNbsol()/2-1);
      child = MultidimentionnalBackpack->crossover(parent);
    } else if(time_useless > 1000){
      vector<vector<int>*> parent = solutions.getParent(MultidimentionnalBackpack->getObjectList(),solutions.getNbsol()/4);
      child = MultidimentionnalBackpack->crossover(parent);
    } else if(time_useless > 500){
      vector<vector<int>*> parent = solutions.getParent(MultidimentionnalBackpack->getObjectList(),solutions.getNbsol()/8);
      child = MultidimentionnalBackpack->crossover(parent);
    } else {
      vector<vector<int>*> parent = solutions.getParent(MultidimentionnalBackpack->getObjectList(),2);
      child = MultidimentionnalBackpack->crossover(parent);
    }
    // Make a child with parents
    // Mutate child
    child = MultidimentionnalBackpack->mutation(child);
    // Repair mutated child
    child =  MultidimentionnalBackpack->repair(child);
    // if child doesn't belong to solutions list
    if(!solutions.belongTo(child)){
      int* bestandworst = NULL;
      // find best and worst solutions ( index )
      bestandworst = MultidimentionnalBackpack->find(solutions);
      // swap worst in solutions's list wirh our child
      solutions.setChoosen(bestandworst[0],child);
      // check if son have better score than best solutions from our list
      // if it's true we swap better with our child
      if(solutions.getValueByIndex(bestandworst[1],MultidimentionnalBackpack->getObjectList()) < MultidimentionnalBackpack->getValue(child)){
        solutions.setChoosen(bestandworst[1],child);
        time_useless = 0;
      } else {
        time_useless++;
      }
      // free pointer
      delete[] bestandworst;
    } else {
      time_useless++;
    }
    compt++;
  }
  if (elapsedTime(start)>=tm) cout<<"Time out ! "<<endl;
  else cout<<"Execution time : "<<elapsedTime(start)<<"s"<<endl;
  bestaux = MultidimentionnalBackpack->find(solutions);
  // get best solutions from our list
  best = solutions.getChoosen(bestaux[1]);
  int nbobject = 0;
  vector<int> objectselected;
  // get Number of object selected in best solutions
  // get all selected objects
  for(int i = 0; i < best.size();i++){
    if(best[i] == 1){
      nbobject++;
      objectselected.push_back(i);
    }
  }
  cout << "The best solutions is : "<< MultidimentionnalBackpack->getValue(best) <<" (score)"<<endl;
  ofstream file ("solution.txt");
  if(!file.is_open()) exit(-1);
  file <<MultidimentionnalBackpack->getValue(best)<<","<<nbobject<<"\n";
  for(int i = 0; i < objectselected.size() ; i++){
    file<<objectselected[i]<<" ";
  }
  delete[] bestaux;


}


int elapsedTime(clock_t start){
  int dif = (std::clock() - start) / (double)CLOCKS_PER_SEC;
  return dif;
}
