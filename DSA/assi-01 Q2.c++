#include <iostream>
using namespace std;

class CNode{
  public:
      int info;
      CNode* pnext;
};

class Clist{
  public:
    CNode* phead;
    CNode* ptail;

    Clist(){
      phead = NULL;
      ptail = NULL;
    }

    void Att(CNode* pnn){
      if(phead == NULL){
        phead = pnn;
        ptail = pnn;
      }
      else{
        ptail->pnext = pnn;
        ptail = pnn;
      }
    }


};

int main(){

  CNode* pnn;
  Clist l1;
  Clist l2;

  int n1;
  cin >> n1;
  for(int i=0; i<n1; i++){
    pnn = new CNode();
    cin >> pnn->info;
    pnn->pnext = NULL;
    l1.Att(pnn);
  }

  int n2;
  cin >> n2;
  for(int i=0; i<n2; i++){
    pnn = new CNode();
    cin >> pnn->info;
    pnn->pnext = NULL;
    l2.Att(pnn);
  }

  int Nsteps;
  cin >> Nsteps;
  int save = Nsteps;
  int max = -999;
  if(n1 >= n2) max = n1;
  else max = n2;

  CNode* p1 = l1.phead;
  CNode* p2 = l2.phead;
  for(int i=0; i<max; i++){
    if(i == Nsteps-1){
      if(p1 != NULL) cout << p1->info << ",";
      if(p2 != NULL) cout << p2->info << " >> ";
      Nsteps += save;
    }

    if(p1 != NULL) p1 = p1->pnext;
    if(p2 != NULL) p2 = p2->pnext;
  }
}