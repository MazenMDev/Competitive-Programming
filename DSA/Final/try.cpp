#include <iostream>
using namespace std;

/*
class CNode
class CList
class Stack
class SortedList
class CTNode
class CBSTree
function numNodes
function findNode
function DisplayAll
main
*/

class CNode
{
public:
    int info;
    CNode* pnext;
    CTNode* pLeft;
    CTNode* pRight;

    CNode* pDown;
};

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
};


class Stack {
private:
    CNode* top;
public:
    Stack() {
        top = NULL;
    }
    Stack(int value) {
        CNode* newNode = new CNode();
        newNode->info = value;
        top = newNode;
    }
    ~Stack() {
        CNode* temp = top;
        while (top) {
            top = top->pnext;
            delete temp;
            temp = top;
        }
    }
    void push(CNode * pnn) {
        pnn->pnext = top;
        top = pnn;
    }
    CNode* pop() {
        CNode* node = top;
        int val = top->info;
        top = node->pnext;
        return node;
    }
};


class SortedList {
public:
    CNode* phead;
    CNode* ptail;
    SortedList() {
        phead = NULL;
        ptail = NULL;
    }
    void attach(CNode* pnn) {
        if (phead == NULL) {
            phead = pnn;
            ptail = pnn;
        }
        else {
            CNode* pB = NULL;
            CNode* pTrav = phead;
            while (pTrav != NULL && pnn->info > pTrav->info) {
                pB = pTrav;
                pTrav = pTrav->pnext;
            }
            if (pTrav == phead) {
                pnn->pnext = phead;
                phead = pnn;
            }
            else {
                pB->pnext = pnn;
                pnn->pnext = pTrav;
                if (pTrav == NULL) {
                    ptail = pnn;
                }
            }
        }
    }
    void display() {
        CNode* Ptrav = phead;
        while (Ptrav != NULL) {
            cout << Ptrav->info << " ";
            Ptrav = Ptrav->pnext;
        }
        cout << endl;
    }
};


class CTNode {
public:
    int info;
    CTNode* pLeft;
    CTNode* pRight;
};

class CBSTree {
public:
    CTNode* pRoot;
    CBSTree() {
        pRoot = NULL;
    }
    ~CBSTree() {
        Bye(pRoot);
    }
    void Disp() {
        DispAll(pRoot);
    }

    void Bye(CTNode* pTrav) {
        if (pTrav == NULL) {
            return;
        }

        Bye(pTrav->pLeft);
        Bye(pTrav->pRight);
        delete pTrav;
    }

    void DispAll(CTNode* pTrav) {
        if (pTrav == NULL) {
            return;
        }
        DispAll(pTrav->pLeft);
        cout << pTrav->info << " ";
        DispAll(pTrav->pRight);
    }

    void insert(CTNode* pnn) {
        if (pRoot == NULL) {
            pRoot = pnn;
            return;
        }
        CTNode* pTrav = pRoot;
        CTNode* pB = NULL;
        while (pTrav != NULL) {
            pB = pTrav;
            if (pnn->info < pTrav->info) {
                pTrav = pTrav->pLeft;
            }
            else {
                pTrav = pTrav->pRight;
            }
        }
        if (pnn->info < pB->info) {
            pB->pLeft = pnn;
        }
        else {
            pB->pRight = pnn;
        }
    }

    void displayTree() {
        displayTreeStructure(pRoot, 0);
    }

    void displayTreeStructure(CTNode* p, int space) {
        if (p == NULL) {
            return;
        }

        space += 10;
        displayTreeStructure(p->pRight, space);
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << p->info << "\n";
        displayTreeStructure(p->pLeft, space);
    }
};

void numNodes(CTNode* ptrav, int& count) {
    if (ptrav == NULL) return;

    count++;
    numNodes(ptrav->pLeft, count);
    numNodes(ptrav->pRight, count);
}

void findNode(CTNode* ptrav, int targetCount, CTNode*& targetNode, CTNode*& parentNode, CTNode* parent, int found) {
    if (ptrav == NULL || found) return;

    int count = 0;
    numNodes(ptrav, count);
    if (count == targetCount) {
        targetNode = ptrav;
        parentNode = parent;
        found = 1;
        return;
    }

    findNode(ptrav->pLeft, targetCount, targetNode, parentNode, ptrav, found);
    findNode(ptrav->pRight, targetCount, targetNode, parentNode, ptrav, found);
}

void DispAll(CTNode* pTrav) {
    if (pTrav == NULL) return;

    DispAll(pTrav->pLeft);
    cout << pTrav->info << " ";
    DispAll(pTrav->pRight);
}

int main() {
    int n;
    cin >> n;

    CList list;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        CNode* pnn = new CNode();
        pnn->info = val;
        pnn->pnext = NULL;

        int numRight, numLeft;
        cin >> numRight >> numLeft;

        int leftVal, rightVal;
        if (numLeft > 0) {
            cin >> leftVal;

            CTNode* leftNode = new CTNode();
            leftNode->info = leftVal;
            numLeft--;
            CBSTree leftTree;
            leftTree.pRoot = leftNode;
            pnn->pLeft = leftTree.pRoot;

            for (int j = 0; j < numLeft; j++) {
                CTNode* leftNode = new CTNode();
                cin >> leftVal;
                leftNode->info = leftVal;
                leftTree.insert(leftNode);
            }
        } 

        if (numRight > 0) {
            cin >> rightVal;

            CTNode* rightNode = new CTNode();
            rightNode->info = rightVal;
            numRight--;
            CBSTree rightTree;
            rightTree.pRoot = rightNode;
            pnn->pRight = rightTree.pRoot;
            for (int j = 0; j < numRight; j++) {
                CTNode* rightNode = new CTNode();
                cin >> rightVal;
                rightNode->info = rightVal;
                rightTree.insert(rightNode);
            }
        }
        list.attach(pnn);
    }

    int numberOfTimes;
    cin >> numberOfTimes; 
    CNode* prev = NULL;
    for (int i = 0; i < numberOfTimes; i++) {
        int pos, TV;
        cin >> pos >> TV;

        int count = 0;
        CNode* ptrav = list.phead;
        // Traverse to the specified position
        while (ptrav != NULL && count < pos) { 
            ptrav = ptrav->pnext;
            count++;
        } 
        if (ptrav == NULL) {
            cout << "Position out of bounds" << endl;
            continue;
        }

        CTNode *left = ptrav->pLeft; // Left subtree
        CTNode *right = ptrav->pRight; // Right subtree

        CTNode* target = NULL; 
        CTNode* parent = NULL;
        int whichTree = 0;

        while (left != NULL) { // Search in left subtree
            if (left->info == TV) { // if the target value is found
                whichTree = 1; // 1 for left tree
                target = left; // set target 
                break;
            }
            parent = left; // keep track of parent to later link when creating new node
            if (left->info < TV) { // traverse right if target is greater
                left = left->pRight;
            } else if (left->info > TV) { // traverse left if target is smaller
                left = left->pLeft;
            }
        }

        if (whichTree != 1 && whichTree != 2) {
            while (right != NULL) {
                if (right->info == TV) {
                    whichTree = 2;
                    target = right;
                    break;
                }
                parent = right;
                if (right->info < TV) {
                    right = right->pRight;
                } else if (right->info > TV) {
                    right = right->pLeft;
                }
            }
        }

        if (whichTree != 1 && whichTree != 2) {
            cout << "Target value is not found" << endl;
        }
        else {
            int count1 = 0;
            numNodes(target, count1); // count nodes in the target subtree
            CTNode* ptrav1 = NULL;
            if (whichTree == 1) {
                ptrav1 = ptrav->pRight; // search in the opposite subtree
            } else { 
                ptrav1 = ptrav->pLeft; // search in the opposite subtree
            }

            CTNode* newTarget = NULL;
            CTNode* newParent = NULL;
            findNode(ptrav1, count1, newTarget, newParent, NULL, 0);

            CNode* pnn = new CNode();
            pnn->info = count1;

            if (whichTree == 1) { // if target was in left subtree
                pnn->pLeft = parent; // link left to original parent
                pnn->pRight = newParent; // link right to new parent found in opposite subtree
            }
            else {
                pnn->pRight = parent;
                pnn->pLeft = newParent;
            }
            if (i == 0) {
                list.attach(pnn);
                prev = pnn;
            }
            else {
                prev->pDown = pnn;
                prev = pnn; 
            }   
        }
    }




    return 0;   
}
