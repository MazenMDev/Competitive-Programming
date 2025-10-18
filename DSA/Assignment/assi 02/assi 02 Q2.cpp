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

    //------------------------------------------------------
    // 🔹 Version 1: Reverse the list in-place
    //------------------------------------------------------
    CNode* prev = NULL;
    CNode* curr = mainList.phead;
    CNode* next = NULL;

    mainList.ptail = mainList.phead; // old head becomes new tail

    while (curr != NULL) {
        next = curr->pnext;
        curr->pnext = prev;
        prev = curr;
        curr = next;
    }
    mainList.phead = prev; // new head after reversal

    cout << "=== ReverseList Version 1 (In-place) ===" << endl;
    cout << "Reversed main list: ";
    CNode* p = mainList.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    //------------------------------------------------------
    // 🔹 Version 2: Reverse by creating a new copied list
    //------------------------------------------------------
    // Rebuild main list again for version 2 (since it’s reversed now)
    mainList.phead = NULL;
    mainList.ptail = NULL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        mainList.Att(pnn);
    }

    // Create reversed copy
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
