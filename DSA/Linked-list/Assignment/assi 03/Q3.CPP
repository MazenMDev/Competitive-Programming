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

int main() {
    CList L[20], NewL;
    CNode* pnn;
    int n, val;

    for (int i = 0; i < 20; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> val;
            pnn = new CNode();
            pnn->info = val;
            pnn->next = nullptr;
            L[i].att(pnn);
        }
    }

    for (int i = 0; i < 10; i++) {
        int pairs[2] = {i, 19 - i};

        for (int k = 0; k < 2; k++) { 
            CList &src = L[pairs[k]];
            CNode* curr = src.phead;
            CNode* prev = nullptr;

            while (curr && curr->next) {
                if (curr->info < 0) { 
                    CNode* start = curr->next;
                    CNode* end = start;

                    while (end && end->info >= 0) end = end->next;

                    if (start != end) {
                        if (prev) prev->next = end;
                        else src.phead = end;

                        if (!end) src.ptail = prev;

                        CNode* temp = start;
                        while (temp != end) {
                            CNode* nextTemp = temp->next;
                            temp->next = nullptr;
                            NewL.att(temp);
                            temp = nextTemp;
                        }
                        curr = end;
                    } else {
                        prev = curr;
                        curr = curr->next;
                    }
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }

    return 0;
}
