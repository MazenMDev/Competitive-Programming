#include <iostream>
using namespace std;

class CNode {
public:
    int info;
    CNode* pnext;
};

int main() {
    CNode* phead = NULL;
    CNode* ptail = NULL;
    CNode* pnn;
    int number;
    cin >> number;
    for (int i = 0; i < number; i++) {
        pnn = new CNode();
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

    int target;
    cin >> target;
    CNode* p = phead;
    int pos = -1;
    for (int i = 0; i < number; i++) {
        if (p->info == target) {
            pos = i;
            break;
        }
        p = p->pnext;
    }
    if (pos == -1) {
        cout << "Not Found" << endl;
    }
    else {
        int quarter = pos / 4;
        int save = quarter;
        int loop = 1;
        int totQ2 = 0;
        int totQ4 = 0;
        CNode* p = phead;
        for (int i = 0; i < pos; i++) {
            if (loop == 2) {
                totQ2 += p->info;
            }
            else if (loop == 4) {
                totQ4 += p->info;
            }
            if (i == quarter - 1) {
                quarter += save;
                loop++;
            }
            p = p->pnext;
        }

        cout << "Q2: " << totQ2 << endl;
        cout << "Q4: " << totQ4 << endl;
    }
}