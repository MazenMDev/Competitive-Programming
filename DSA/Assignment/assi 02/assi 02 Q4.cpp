#include <iostream>
using namespace std;

class CNode {
public:
    int info;
    CNode* pnext;
};

class Clist {
public:
    CNode* phead;
    CNode* ptail;

    Clist() {
        phead = NULL;
        ptail = NULL;
    }

    void Att(CNode* pnn) {
        if (phead == NULL) {
            phead = pnn;
            ptail = pnn;
        }
        else {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }
};

int main() {
    CNode* pnn;
    Clist l1;
    Clist l2;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        l1.Att(pnn);
    }

    //find max and min
    CNode* ptemp = l1.phead;
    int max = ptemp->info;
    int min = ptemp->info;
    int posmax = 0;
    int posmin = 0;
    for (int i = 0; i < n; i++) {
        if (ptemp->info > max) {
            max = ptemp->info;
            posmax = i;
        }
        if (ptemp->info < min) {
            min = ptemp->info;
            posmin = i;
        }
        ptemp = ptemp->pnext;
    }

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

    int st, end;
    if (posmin < posmax) {
        st = posmin;
        end = posmax;
    }
    else {
        st = posmax;
        end = posmin;
    }

    CNode* nodeMin = new CNode();
    nodeMin->info = min;
    nodeMin->pnext = NULL;
    l2.Att(nodeMin);

    CNode* nodeMax = new CNode();
    nodeMax->info = max;
    nodeMax->pnext = NULL;
    l2.Att(nodeMax);

    ptemp = l1.phead;


    for (int i = 0; i < n; i++) {
      if(i > st and i < end) {
        CNode* copyNode = new CNode();
        copyNode->info = ptemp->info;
        copyNode->pnext = NULL;
        l2.Att(copyNode);
      }
      ptemp = ptemp->pnext;
    }

    cout << "New list: ";
    ptemp = l2.phead;
    while (ptemp != NULL) {
        cout << ptemp->info << " ";
        ptemp = ptemp->pnext;
    }
    cout << endl;

    return 0;
}