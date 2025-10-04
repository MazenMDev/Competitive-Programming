#include <iostream>
using namespace std;

class CNode {
public:
    int info;
    CNode* pnext;
};

int32_t main() {

    CNode* phead = NULL;
    CNode* ptail = NULL;

    CNode* phead2 = NULL;
    CNode* ptail2 = NULL;

    int number;
    cin >> number;
    // build first list
    for (int i = 0; i < number; i++) {
        CNode* pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        if (phead == NULL) {
            phead = pnn;
            ptail = pnn;
        }
        else {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }

    // build second list
    for (int i = 0; i < number; i++) {
        CNode* pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        if (phead2 == NULL) {
            phead2 = pnn;
            ptail2 = pnn;
        }
        else {
            ptail2->pnext = pnn;
            ptail2 = pnn;
        }
    }



    CNode* p1 = phead;
    CNode* p2 = phead2;

    for (int i = 0; i < number; i++) {
        if (p1->info == p2->info) {
            cout << i << " " << p1->info << endl;
        }
        p1 = p1->pnext;
        p2 = p2->pnext;
    }



    return 0;
}
