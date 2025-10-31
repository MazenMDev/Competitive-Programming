#include <iostream>
using namespace std;

class CNode {
public:
    int info;
    CNode* pnext;
};

class Clist {
public:
    CNode* ph;
    CNode* pt;

    Clist() {
        ph = NULL;
        pt = NULL;
    }

    void attach(CNode* pnn) {
        if (ph == NULL) {
            ph = pnn;
            pt = pnn;
        } else {
            pt->pnext = pnn;
            pt = pnn;
        }
    }

    void print() {
        CNode* p = ph;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->pnext;
        }
        cout << endl;
    }
};

int main() {
    Clist l1, l2;
    CNode* pnn;

    int n;
    // build first list
    cin >> n;
    for (int i = 0; i < n; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        l1.attach(pnn);
    }

    // build second list
    cin >> n;
    for (int i = 0; i < n; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->pnext = NULL;
        l2.attach(pnn);
    }

    int t1, t2;
    cin >> t1 >> t2;

    CNode* prevStart = NULL;
    CNode* start = l1.ph;
    while (start && start->info != t1) {
        prevStart = start;
        start = start->pnext;
    }

    if (!start) {
        cout << "t1 not found" << endl;
        return 0;
    }

    CNode* end = start;
    while (end && end->info != t2) {
        end = end->pnext;
    }

    if (!end) {
        cout << "t2 not found" << endl;
        return 0;
    }

    CNode* afterEnd = end->pnext;

    if (prevStart) {
        prevStart->pnext = afterEnd;
    } else {
        l1.ph = afterEnd;
    }

    if (afterEnd == NULL) {
        l1.pt = prevStart;
    }

    end->pnext = NULL;

    if (l2.pt) {
        l2.pt->pnext = start;
        l2.pt = end;
    } else {
        l2.ph = start;
        l2.pt = end;
    }

    cout << "List 1 after cut: ";
    l1.print();
    cout << "List 2 after paste: ";
    l2.print();

    return 0;
}
