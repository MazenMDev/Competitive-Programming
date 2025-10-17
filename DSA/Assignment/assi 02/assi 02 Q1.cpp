#include <iostream>
using namespace std;

// Node class for linked list
class CNode {
public:
    int info;
    CNode* pnext;
};

// Linked list class
class Clist {
public:
    CNode* phead;
    CNode* ptail;

    // Constructor
    Clist() {
        phead = NULL;
        ptail = NULL;
    }

    // Attach a new node at the end of the list
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

    // Fill main list
    for (int i = 0; i < n; i++) {
        newNode = new CNode();
        cin >> newNode->info;
        newNode->pnext = NULL;
        mainList.Att(newNode);
    }

    int splitVal;
    cin >> splitVal;

    //-------------------------------------
    // VERSION 1: SplitList_1 (Copy nodes)
    //-------------------------------------
    cout << "\n=== SplitList_1 (Copy version) ===\n";

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

    //-------------------------------------
    // VERSION 2: SplitList_2 (Move nodes)
    //-------------------------------------
    cout << "\n=== SplitList_2 (Move version) ===\n";

    // Rebuild lists (since previous ones are full)
    l1.phead = NULL; l1.ptail = NULL;
    l2.phead = NULL; l2.ptail = NULL;

    p = mainList.phead;
    CNode* prev = NULL;
    bool found2 = false;

    while (p != NULL) {
        if (!found2) {
            // Move to list1
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
            // Move to list2
            if (l2.phead == NULL)
                l2.phead = p;
            else
                l2.ptail->pnext = p;
            l2.ptail = p;
        }

        p = p->pnext;
    }

    // Cut the link between list1 and list2
    if (found2 && prev != NULL)
        prev->pnext = NULL;

    // Empty main list
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