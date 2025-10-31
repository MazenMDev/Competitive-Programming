#include <iostream>
using namespace std;

class CNode {
  public: 
    int info;
    CNode* next;
};

class CList {
  public:
    CNode* phead;
    CNode* ptail;
    CList() {
      phead = NULL;
      ptail = NULL;
    }
    void att(CNode* pnn){
      if(phead == NULL){
        phead = pnn;
        ptail = pnn;
      }
      else{
        ptail->next = pnn;
        ptail = pnn;
      }
    }
};

void main(){
  CList l1, l2;
  CNode* pnn;
  int number;
  cin >> number;
  for(int i=0; i<number; i++){
    pnn = new CNode();
    cin >> pnn->info;
    pnn->next = NULL;
    l1.att(pnn);
  }
  for(int i=0; i<number; i++){
    pnn = new CNode();
    cin >> pnn->info;
    pnn->next = NULL;
    l2.att(pnn);
  }

  CNode* p1 = l1.phead;
  CNode* p2 = l2.phead;

  CNode* start1 = NULL;
  CNode* start2 = NULL;
  while(p1 != NULL && p2 != NULL){
    if(p1->info == p2->info){
      if(start1 == NULL){
        start1 = p1;
        start2 = p2;
      }
      else{
        CNode* temp = start1->next;
        start1->next = start2->next;
        start2->next = temp;

        start1 = NULL;
        start2 = NULL;
      }
    }
    p1 = p1->next;
    p2 = p2->next;
  }

  // cout l1 
  p1 = l1.phead;
  while(p1 != NULL){
    cout << p1->info << " ";
    p1 = p1->next;
  }
  cout << endl;
  // cout l2
  p2 = l2.phead;
  while(p2 != NULL){
    cout << p2->info << " ";
    p2 = p2->next;
  }
  cout << endl;
}