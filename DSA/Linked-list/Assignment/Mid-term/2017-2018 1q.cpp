#include <iostream>
using namespace std;

class CNode
{
public:
    int info;
    CNode* pnext;
    CNode* pextra;
};

class Clist
{
public:
    CNode* phead;
    CNode* ptail;

    Clist()
    {
        phead = NULL;
        ptail = NULL;
    }

    void Att(CNode* pnn)
    {
        if (phead == NULL)
        {
            phead = pnn;
            ptail = pnn;
        }
        else
        {
            ptail->pnext = pnn;
            ptail = pnn;
        }
    }

    CNode* Cut_Flip_And_Return(int val)
    {

        CNode* start = NULL;
        CNode* midpoint = NULL;
        CNode* end = NULL;

        int count = 0;

        CNode* ptrav = phead;
        CNode* prevN = NULL;


        // 15 70 33 10 12 10 40 31 17 10 50 10 60 80 36 10 10 14 6 10 2 8
        // N0 N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14 N15 N16 N17 N18 N19 N20 N21 NULL
        while (ptrav != NULL)
        {
            if (ptrav->pnext) {
                if (ptrav->pnext->info == val and count == 0) {
                    start = ptrav;
                    end = ptrav;
                    count++;
                    prevN = ptrav;
                }
                else if (ptrav->pnext->info == val) {
                    end = ptrav;
                    count++;

                    if (count == 2) {
                        midpoint = ptrav;
                    }
                    else if (count % 2 == 0) {
                        midpoint = midpoint->pextra;
                    }
                    prevN->pextra = ptrav;
                    prevN = ptrav;
                }
            }
            ptrav = ptrav->pnext;
        }

        CNode* first10 = start->pnext;
        start->pnext = end->pnext->pnext;

        CNode* mid = midpoint->pnext;
        CNode* newStart = mid->pnext;

        mid->pnext = first10;
        midpoint->pnext = NULL;

        end->pnext->pnext = mid;


        return newStart;
    }
};

int main() {
    Clist a;
    int x;

    // Build the list
    cout << "Enter list values, end with -1:\n";
    while (true) {
        cin >> x;
        if (x == -1) break;
        CNode* pnn = new CNode();
        pnn->info = x;
        pnn->pnext = NULL;
        pnn->pextra = NULL;
        a.Att(pnn);
    }

    // Display original list
    cout << "\nOriginal List:\n";
    CNode* p = a.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    int val;
    cout << "\nEnter val to Cut & Flip: ";
    cin >> val;

    CNode* returned = a.Cut_Flip_And_Return(val);

    // Display the returned list part
    cout << "\nReturned Part:\n";
    if (returned == NULL)
        cout << "NULL\n";
    else {
        p = returned;
        while (p != NULL) {
            cout << p->info << " ";
            p = p->pnext;
        }
    }
    cout << endl;

    // Display the list after change
    cout << "\nList After Modification:\n";
    p = a.phead;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->pnext;
    }
    cout << endl;

    return 0;
}
