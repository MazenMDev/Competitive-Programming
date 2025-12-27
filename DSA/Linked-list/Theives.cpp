#include <iostream>
using namespace std;

class cnode
{
public:
	char s1[6] = { 'y','y','y','y','y','y' };
	char s2[6] = { 'n','n','n','n','n','n' };
	int boat = 1;
	cnode* pnext;
};

class clist
{
public:
	cnode* phead;
	cnode* ptail;

	clist()
	{
		phead = NULL;
		ptail = NULL;
	}

	void attach(cnode* pnn)
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
};

class cstack
{
public:
	cnode* phead;

	cstack()
	{
		phead = NULL;
	}

	void push(cnode* pnn)
	{
		pnn->pnext = phead;
		phead = pnn;
	}

	cnode* pop()
	{
		if (phead == NULL)
			return NULL;

		cnode* temp = phead;
		phead = phead->pnext;
		temp->pnext = NULL;
		return temp;
	}
};

int main()
{
	clist l;
	cstack s;
	cnode* pcur = NULL;
	int m[3], ct = 0;

	cout << "Amount of money: ";
	for (int i = 0; i < 3; i++)
		cin >> m[i];

	// CreateInit inline 
	cnode* pinit = new cnode;
	for (int i = 0; i < 6; i++)
	{
		pinit->s1[i] = 'y';
		pinit->s2[i] = 'n';
	}
	pinit->boat = 1;
	pinit->pnext = NULL;

	s.push(pinit);

	while (true)
	{
		pcur = s.pop();
		if (pcur == NULL)
		{
			cout << "no solution\n";
			break;
		}

		// isend inline 
		int endct = 0;
		for (int i = 0; i < 6; i++)
		{
			if (pcur->s1[i] == 'n' && pcur->s2[i] == 'y')
				endct++;
		}
		if (endct == 6)
		{
			cout << "solution found\n";
			break;
		}

		l.attach(pcur);

		// ExpandNextGen inline 
		for (int j = 0; j < 3; j++)
		{
			for (int i = j; i < 6; i++)
			{
				cnode* pnn = new cnode;

				// Copy inline 
				for (int k = 0; k < 6; k++)
				{
					pnn->s1[k] = pcur->s1[k];
					pnn->s2[k] = pcur->s2[k];
				}
				pnn->boat = pcur->boat;
				pnn->pnext = NULL;

				// Move logic 
				if (i == j)
				{
					if (pnn->s1[j] == 'y' && pnn->boat == 1)
					{
						pnn->s1[j] = 'n';
						pnn->s2[j] = 'y';
						pnn->boat = 2;
					}
					else if (pnn->s1[j] == 'n' && pnn->boat == 2)
					{
						pnn->s1[j] = 'y';
						pnn->s2[j] = 'n';
						pnn->boat = 1;
					}
				}
				else
				{
					if (pnn->s1[j] == 'y' && pnn->s1[i] == 'y' && pnn->boat == 1)
					{
						pnn->s1[j] = 'n';
						pnn->s2[j] = 'y';
						pnn->s1[i] = 'n';
						pnn->s2[i] = 'y';
						pnn->boat = 2;
					}
					else if (pnn->s1[j] == 'n' && pnn->s1[i] == 'n' && pnn->boat == 2)
					{
						pnn->s1[j] = 'y';
						pnn->s2[j] = 'n';
						pnn->s1[i] = 'y';
						pnn->s2[i] = 'n';
						pnn->boat = 1;
					}
				}

				// isLegal inline 
				int nt = 0, totm = 0, totm2 = 0;
				for (int x = 0; x < 3; x++)
				{
					if (pnn->s1[x] == 'y')
					{
						nt++;
						totm += m[x];
					}
					if (pnn->s1[x + 3] == 'y')
						totm2 += m[x];
				}
				if (totm2 > totm && nt > 0)
				{
					delete pnn;
					continue;
				}

				nt = totm = totm2 = 0;
				for (int x = 0; x < 3; x++)
				{
					if (pnn->s2[x] == 'y')
					{
						nt++;
						totm += m[x];
					}
					if (pnn->s2[x + 3] == 'y')
						totm2 += m[x];
				}
				if (totm2 > totm && nt > 0)
				{
					delete pnn;
					continue;
				}

				// isvisited inline (FIX FOR INFINITE LOOP) 
				bool visited = false;
				cnode* t = l.phead;

				while (t != NULL)
				{
					int same = 0;
					for (int k = 0; k < 6; k++)
					{
						if (t->s1[k] == pnn->s1[k] &&
							t->s2[k] == pnn->s2[k] &&
							t->boat == pnn->boat)
							same++;
					}
					if (same == 6)
					{
						visited = true;
						break;
					}
					t = t->pnext;
				}

				t = s.phead;
				while (t != NULL && visited == false)
				{
					int same = 0;
					for (int k = 0; k < 6; k++)
					{
						if (t->s1[k] == pnn->s1[k] &&
							t->s2[k] == pnn->s2[k] &&
							t->boat == pnn->boat)
							same++;
					}
					if (same == 6)
					{
						visited = true;
						break;
					}
					t = t->pnext;
				}

				if (visited == false)
				{
					ct++;
					cout << "LEGAL " << ct << endl;

					for (int d = 0; d < 3; d++)
					{
						if (pnn->s1[d + 3] == 'y')
							cout << pnn->s1[d] << " " << m[d] << "----------" << pnn->s2[d] << endl;
						else
							cout << pnn->s1[d] << "----------" << m[d] << " " << pnn->s2[d] << endl;
					}
					cout << "=======================\n";

					s.push(pnn);
				}
				else
				{
					delete pnn;
				}
			}
		}
	}
}
