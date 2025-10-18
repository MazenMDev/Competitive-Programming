#include <iostream>
using namespace std;

class CNode {
public:
    int info;
    CNode* pnext;
};

int main(){
  CNode* pnn;
  CNode* phead = NULL;
  CNode* ptail = NULL;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    pnn = new CNode();
    cin >> pnn->info;
    pnn->pnext = NULL;
    if(phead == NULL){
      phead = pnn;
      ptail = pnn;
    } else {
      ptail->pnext = pnn;
      ptail = pnn;
    }
  }

  int target;
  cin >> target;
  CNode*pbreak = phead;
  for(int i=0; i<target-1; i++){
    pbreak = pbreak->pnext;
  }
  ptail->pnext = phead;
  ptail = pbreak;  
  pbreak = pbreak->pnext;
  phead = pbreak;
  ptail->pnext = NULL;


  cout << "Modified list after breaking the cycle at position " << target << ": ";
  CNode* p = phead;
  while(p != NULL){
    cout << p->info << " ";
    p = p->pnext;
  }
  cout << endl;

  return 0;
}