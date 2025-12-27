#include<iostream>
using namespace std;

class CNode {
public:
    int info;
    int val;
    CNode* pnext;
    CNode* pdown;

};
/*
class CNode
{
public:
    int info;
    CNode* pnext;
};
*/
class CList
{
public:
    CNode* phead;
    CNode* ptail;
    CList()
    {
        phead = NULL;
        ptail = NULL;
    }
    ~CList()
    {
        CNode* current = phead;
        while (current != NULL)
        {
            CNode* nextNode = current->pnext;
            delete current;
            current = nextNode;
        }
        phead = NULL;
        ptail = NULL;
    }

    void attach(CNode* pnn)
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
        pnn->pnext = NULL;
    }

    void display()
    {
        CNode* Ptrav = phead;
        while (Ptrav != NULL)
        {
            cout << Ptrav->info << " ";
            Ptrav = Ptrav->pnext;
        }
        cout << endl;

    }

    CNode * Attach_And_Eat(CNode* pnn, int F, int isEat) {


        if (F == 1) {
            if (phead == NULL) {
                phead = pnn;
                ptail = pnn;
            }
            else {
                ptail->pnext = pnn;
                pnn->pnext = ptail;
                ptail = pnn;
            }
        }
        else {
            if (ptail->pdown == NULL) {
                ptail->pdown = pnn;
                pnn->pdown = NULL;
                ptail->pdown->pnext = pnn;
                ptail->val = 1;
            }
            else if (ptail->pdown->pdown == NULL) {
                ptail->pdown->pdown = pnn;
                ptail->pdown->pnext = pnn;
                pnn->pdown = NULL;
                ptail->pdown->pdown->pnext = pnn;
                ptail->val = 2;

            }
            else {
                ptail->pdown->pnext->pdown = pnn;
                ptail->pdown->pnext = pnn;
                pnn->pdown = NULL;
                ptail->val++;

                
                if (ptail->val % 2 == 0 || ptail->val % 3 == 0) {
                    if (ptail->val > 3) {
                        ptail->pdown->pdown->pnext = ptail->pdown->pdown->pnext->pdown;
                    }
                }
            }
        }
        
        if (isEat == 1) {
            CNode* lastOneThird = ptail->pnext->pdown->pdown->pnext->pdown;

            ptail->pnext->pdown->pdown->pnext->pdown = NULL;
            return lastOneThird;
        }
        else return NULL;
        






    }



};

//For Testing
int main() {
	CList list;
	int t;
	cin >> t;
	while (t--) {
			int val; cin >> val;
			CNode* pnn = new CNode();
			pnn->info = val;
            list.Attach_And_Eat(pnn, 1, 0);
		int NumNodes; cin >> NumNodes;
		while (NumNodes--) {
				int v; cin >> v;
				CNode* pnn1 = new CNode();
				pnn1->info = v;
			    list.Attach_And_Eat(pnn1 , 2 , 0);
			
		}
	}
	int val; cin >> val;
	CNode* pnn = new CNode();
	pnn->info = val;
	CNode* eaten = list.Attach_And_Eat(pnn, 2, 1);
	if (eaten != NULL) {
		CNode* trav = eaten;
        cout << "\n----------\n";
		while (trav != NULL) {
			cout << trav->info << " ";
			trav = trav->pnext;
		}
		cout << endl;
		delete eaten;
	}
}


/*
INPUT

6
0
6
1 2 3 4 5 6
1
9
7 8 9 10 11 12 13 14 15
2
3
16 17 18
3
6
19 20 21 21 22 23
4
9
24 25 26 27 28 29 30 31 32
5
2
33 34
35


EXPECTED OUTPUT:
30 31 32 (last 1/3 of the before last column)
*/