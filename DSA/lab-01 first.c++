#include <iostream>
using namespace std;  

class CNode{
  public:
    int info;
    CNode* pnext;
};

int main(){
  CNode* phead = NULL;
  CNode* ptail = NULL;
  
  int number;
  cin >> number;
  for(int i=0; i<number; i++){
    CNode* pnn = new CNode();
    cin >> pnn->info;
    pnn->pnext = NULL;
    if(phead == NULL){
      phead = pnn;
      ptail = pnn;
    }else{
      ptail->pnext = pnn;
      ptail = pnn;
    }
  }
  int v;
  cin >> v;
  CNode* ptr = phead;
  int pos = 0;
  int found = -1;
  while(ptr != NULL){
    if(ptr->info == v){
      found = pos;
      break;
    }
    ptr = ptr->pnext;
    pos++;
  }

  if(found == -1){
    cout << "Try again" << endl;
    return 0;
  }

  int tot = 0;
  CNode* ptemp = phead;
  for(int i=0; i < found; i++){
    if(i >= found-3){
      tot += ptemp->info;
    }
    ptemp = ptemp->pnext;
  }

  CNode* po = ptr->pnext;
  for(int i=0; i<3; i++){
    tot += po->info;
    po = po->pnext;
  }
  cout << tot << endl;
  return 0;
}