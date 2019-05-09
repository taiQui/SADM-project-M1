#include "../header/geneticAlgorithm.hpp"


void geneticAlgorithm (int objectnumber, int bagnumber, vector<int> objectlist,vector<int> bagcapacity, vector<vector<int>> objectcharge,int tm,int verbose){
  /* Variable definitions
  */
  srand(time(NULL));
  cout<<"test0"<<endl;
  timer chrono;
  cout<<"test1"<<endl;
  chrono.start();
  cout<<"test2"<<endl;
  MB* MultidimentionnalBackpack = new MB(objectnumber,bagnumber,objectlist,bagcapacity,objectcharge,1);
  cout<<"test3"<<endl;
  // compteurs
  int compt = 0;
  //initialise

  //fitness
  Solutions solutions;
  cout<<"test4"<<endl;
  solutions.generate(MultidimentionnalBackpack);
  //find best solution
  cout<<"test5"<<endl;
  while(compt < T_MAX ){
    cout<<"test55"<<endl;
    vector<vector<int>*> parent = solutions.getParent(MultidimentionnalBackpack->getObjectList(),2);
    cout <<"test6"<<endl;
    vector<int> child;
    cout<<"first child"<<endl;
    child = MultidimentionnalBackpack->crossover(parent);
    for(int i = 0; i < child.size();i++){
      cout<<child[i]<<" ";
    }
    cout<<endl;
    cout<<"mutation child"<<endl;
    child = MultidimentionnalBackpack->mutation(child);
    for(int i = 0; i < child.size();i++){
      cout<<child[i]<<" ";
    }
    cout<<endl;
    cout<<"repair child"<<endl;
    child =  MultidimentionnalBackpack->repair(child);
    for(int i = 0; i < child.size();i++){
      cout<<child[i]<<" ";
    }
    cout<<endl;
    // child = MultidimentionnalBackpack->repair();
    cout<<"test7"<<endl;
    if(!solutions.belongTo(child)){
      cout<<"test8"<<endl;
      int* bestandworst = NULL;
      cout<<"test9"<<endl;
      bestandworst = MultidimentionnalBackpack->find(solutions);
      cout<<"1 : "<<bestandworst[0]<<"|||  2 : "<<bestandworst[1]<<endl;
      cout<<"test10"<<endl;
      solutions.setChoosen(bestandworst[0],child);
      cout<<"test11"<<endl;
      int test1 =solutions.getValueByIndex(bestandworst[1],MultidimentionnalBackpack->getObjectList());
      int test2 = MultidimentionnalBackpack->getValue(child);
      cout<<"t1 : "<<test1<<endl<<"t2 : "<<test2<<endl;
      if(test1 < test2){
        cout<<"test12"<<endl;
        solutions.setChoosen(bestandworst[1],child);
        cout<<"test13"<<endl;
      }
    }
    compt++;
  }

  int* bestaux = NULL;
  bestaux = MultidimentionnalBackpack->find(solutions);
  vector<int> best = solutions.getChoosen(bestaux[1]);
  int nbobject = 0;
  vector<int> objectselected;
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

}
