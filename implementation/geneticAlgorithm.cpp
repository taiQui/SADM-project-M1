#include "../header/geneticAlgorithm.hpp"


void geneticAlgorithm (int objectnumber, int bagnumber, vector<int> objectlist,vector<int> bagcapacity, vector<vector<int>> objectcharge,int time,int verbose){
  /* Variable definitions
  */
  timer chrono;
  chrono.start();
  MB MultidimentionnalBackpack = new MB(objectnumber,bagnumber,objectlist,bagcapacity,objectcharge,1);

  // compteurs
  int compt = 0;
  //initialise

  //fitness

  //find best solution

  while(compt < T_MAX && !chrono.isTimeout() ){


    compt++;
  }
}
