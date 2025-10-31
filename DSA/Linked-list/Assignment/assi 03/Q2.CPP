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
    void att(CNode* pnn) {
        if (phead == NULL) {
            phead = pnn;
            ptail = pnn;
        }
        else {
            ptail->next = pnn;
            ptail = pnn;
        }
    }
};

void main() {
    CList l1, l2;
    CNode* pnn;
    int number;
    cin >> number;
    for (int i = 0; i < number; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->next = NULL;
        l1.att(pnn);
    }
    cin >> number;
    for (int i = 0; i < number; i++) {
        pnn = new CNode();
        cin >> pnn->info;
        pnn->next = NULL;
        l2.att(pnn);
    }

    int first = l1.phead->info;
    int second = l1.phead->next->info;
    int third;
    CNode* p1 = l1.phead;
    while (p1 != NULL) {
        if (p1 != l1.ptail) {
            third = p1->info;
        }
        p1 = p1->next;
    }
    int forth = l1.ptail->info;
    cout << endl << "First: " << first << " Second: " << second << " Third: " << third << " Forth: " << forth << endl;
    CNode* p2 = l2.phead;
    CNode* prev = NULL;
    while (p2 != NULL && p2->next != NULL) {
        if (p2->info == first and p2->next->info == second) {
            if (prev == NULL) {
                l2.phead = p2->next->next;
            }
            else {
                prev->next = p2->next->next;
            }
            p2->next->next = NULL;
            break;
        }
        prev = p2;
        p2 = p2->next;
    }

    p2 = l2.phead;
    prev = NULL;
    while (p2 != NULL && p2->next != NULL) {
        if (p2->info == third and p2->next->info == forth) {
            if (prev == NULL) {
                l2.phead = p2->next->next;
            }
            else {
                prev->next = p2->next->next;
            }
            p2->next->next = NULL;
            break;
        }
        prev = p2;
        p2 = p2->next;
    }


    cout << endl;
    //cout l2
    CNode* p = l2.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
}
