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

    void Att(CNode* newNode) {
        if (phead == NULL) {
            phead = newNode;
            ptail = newNode;
        }
        else {
            ptail->pnext = newNode;
            ptail = newNode;
        }
    }
};

int main() {
    CNode* newNode;
    Clist mainList;
    Clist l1;
    Clist l2;

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        newNode = new CNode();
        cin >> newNode->info;
        newNode->pnext = NULL;
        mainList.Att(newNode);
    }

    int splitVal;
    cin >> splitVal;



    CNode* p = mainList.phead;
    int found = -1;

    while (p != NULL) {
        CNode* copyNode = new CNode();
        copyNode->info = p->info;
        copyNode->pnext = NULL;

        if (p->info == splitVal) {
            found = 1;
        }

        if (found == -1)
            l1.Att(copyNode);
        else
            l2.Att(copyNode);

        p = p->pnext;
    }

    cout << "Main list: ";
    p = mainList.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    cout << "List 1: ";
    p = l1.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    cout << "List 2: ";
    p = l2.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;


    l1.phead = NULL; l1.ptail = NULL;
    l2.phead = NULL; l2.ptail = NULL;

    p = mainList.phead;
    CNode* prev = NULL;
    bool found2 = false;

    while (p != NULL) {
        if (!found2) {
            if (l1.phead == NULL)
                l1.phead = p;
            else
                l1.ptail->pnext = p;
            l1.ptail = p;

            if (p->info == splitVal) {
                found2 = true;
                prev = p;
            }
        }
        else {
            if (l2.phead == NULL)
                l2.phead = p;
            else
                l2.ptail->pnext = p;
            l2.ptail = p;
        }

        p = p->pnext;
    }


    if (found2 && prev != NULL)
        prev->pnext = NULL;

    mainList.phead = NULL;
    mainList.ptail = NULL;

    cout << "Main list: ";
    p = mainList.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    cout << "List 1: ";
    p = l1.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    cout << "List 2: ";
    p = l2.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    return 0;
}