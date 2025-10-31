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
        } else {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }
};

int main() {
    CNode* pnn;
    Clist mainList;
    int n;

    // Input main list
    cin >> n;
    for (int i = 0; i < n; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        mainList.Att(pnn);
    }


    CNode* prev = NULL;
    CNode* curr = mainList.phead;
    CNode* next = NULL;

    mainList.ptail = mainList.phead; 

    while (curr != NULL) {
        next = curr->pnext;
        curr->pnext = prev;
        prev = curr;
        curr = next;
    }
    mainList.phead = prev; 

    cout << "=== ReverseList Version 1 (In-place) ===" << endl;
    cout << "Reversed main list: ";
    CNode* p = mainList.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;


    mainList.phead = NULL;
    mainList.ptail = NULL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        mainList.Att(pnn);
    }


    CNode* revHead = NULL;
    CNode* revTail = NULL;
    p = mainList.phead;

    while (p != NULL) {
        CNode* copyNode = new CNode();
        copyNode->info = p->info;
        copyNode->pnext = NULL;

        if (revHead == NULL) {
            revHead = copyNode;
            revTail = copyNode;
        } else {
            copyNode->pnext = revHead;
            revHead = copyNode;
        }

        p = p->pnext;
    }

    cout << "=== ReverseList Version 2 (Copy Version) ===" << endl;
    cout << "Main list (unchanged): ";
    p = mainList.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    cout << "Reversed copy list: ";
    p = revHead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    return 0;
}
