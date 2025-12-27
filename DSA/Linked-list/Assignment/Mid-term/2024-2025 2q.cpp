#include<iostream>
using namespace std;

class CNode {
public:
    int v1 , v2;              
    CNode* pnext, * pprev;    
    CNode* pdown, * pup;      
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

    // إضافة عقدة في نهاية القائمة
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
};

class Stack {
private:
    CNode* top;   // Pointer to the top element of the stack
public:
    Stack() {
        top = NULL;   // Initialize stack as empty
    }

    Stack(int value) {
        CNode* newNode = new CNode(); // Create a new node
        newNode->v1 = value;          // Store the value in v1
        top = newNode;                // Set this node as the top
    }

    ~Stack() {
        CNode* temp = top;         // Start from the top of the stack
        while (top) {              // Loop until stack is empty
            top = top->pnext;      // Move top to next node
            delete temp;           // Delete previous top
            temp = top;            // Update temp to new top
        }
    }

    void push(int value) {         // Push a new value on top of the stack
        CNode* newNode = new CNode(); // Create a new node
        newNode->v1 = value;          // Store value in node
        newNode->pnext = top;         // Link new node to previous top
        top = newNode;                // Update top to new node
    }

    CNode * pop() {                // Pop and return the top node
        CNode* node = top;         // Store current top node
        top = node->pnext;         // Move top to next element
        return node;               // Return popped node (caller must delete it)
    }
};



int main() {
    CList a; // Create a list to store multiple shapes/grids
    
    int num; cin >> num; // Read number of shapes to input
    
    for (int i = 0; i < num; i++) { // Loop over each shape
        
        int width, height;
        cin >> height >> width; // Read dimensions of shape

        CNode* pnn = new CNode(); // Create root node for this shape
        pnn->v1 = height;         // Store height in v1
        pnn->v2 = width;          // Store width in v2
        
        CNode* prev = pnn;        // Pointer used to chain nodes

        // Move upward direction for "height" steps
        for (int h = 0; h < height; h++) {
            int val;
            cin >> val;               // Read value
            CNode* n = new CNode();   // Create new node
            n->v1 = val;              // Store the value
            prev->pup = n;            // Link previous node UP to this node
            prev = n;                 // Move prev pointer to new node
        }

        // Move right direction for "width-1" steps
        for (int w = 0; w < width - 1; w++) {
            int val;
            cin >> val;
            CNode* n = new CNode();
            n->v1 = val;
            prev->pnext = n;          // Link to the right
            prev = n;
        }

        // Move downward direction
        for (int h = 0; h < height-1; h++) {
            int val;
            cin >> val;
            CNode* n = new CNode();
            n->v1 = val;
            prev->pdown = n;          // Link downward
            prev = n;
        }

        // Move left direction (width - 2) steps to close shape
        for (int w = 0; w < width - 2; w++) {
            int val;
            cin >> val;
            CNode* n = new CNode();
            n->v1 = val;
            prev->pprev = n;          // Link to the left
            prev = n;
        }

        // Close the loop (last left node connects to the first up node)
        prev->pprev = pnn->pup;
     
        a.attach(pnn); // Add this shape to the list
    }



    CNode* trav = a.phead; // Start traversing shapes list
    int currNode = 0;      // Shape index

    while (trav) {         // For each shape
        
        CNode* start = trav->pup; // Start walking from the top node
        
        int length = 0;           // Will count nodes between -1 and -2
        int startCt = 0;          // Flag to start recording sequence
        CNode* startmirr = NULL;  // Pointer for the mirror check starting point

        cout << "\n Node: " << currNode << " [";

        while (true) { // Walk boundary of shape in a loop
            
            if (start->v1 == -1) { // When encountering -1 → start recording
                startCt = 1;
                // Decide where to move next based on available pointer
                if (start->pdown) startmirr = start->pdown;
                else if (start->pnext) startmirr = start->pnext;
                else if (start->pprev) startmirr = start->pprev;
                else if (start->pup) startmirr = start->pup;
            }

            if (startCt == 1) { // If recording started

                if (start->v1 != -1 && start->v1 != -2)
                    cout << start->v1 << ","; // Print value

                length++; // Count node
                
                if (start->v1 == -2) // Stop when hitting -2
                    break;
            }

            // Continue walking shape boundary in priority order
            if (start->pdown) start = start->pdown;
            else if (start->pnext) start = start->pnext;
            else if (start->pprev) start = start->pprev;
            else if (start->pup) start = start->pup;
        }

        cout << "]\n";

        length -= 2; // Ignore -1 and -2

        int ct = 0;
        Stack s; // Create stack to store first half of values

        while (ct < length / 2) { // Push first half into stack
            s.push(startmirr->v1);

            if (startmirr->pdown) startmirr = startmirr->pdown;
            else if (startmirr->pnext) startmirr = startmirr->pnext;
            else if (startmirr->pprev) startmirr = startmirr->pprev;
            else if (startmirr->pup) startmirr = startmirr->pup;

            ct++;
        }

        int isMirror = 1; // Assume mirror unless proven otherwise

        while (ct < length) { // Walk second half and compare
            CNode* sNode = s.pop(); // Get last pushed value (reverse order)
            
            if (sNode->v1 != startmirr->v1) { // If mismatch → not mirror
                isMirror = 0;
                delete sNode;
                break;
            }

            delete sNode;

            if (startmirr->pdown) startmirr = startmirr->pdown;
            else if (startmirr->pnext) startmirr = startmirr->pnext;
            else if (startmirr->pprev) startmirr = startmirr->pprev;
            else if (startmirr->pup) startmirr = startmirr->pup;

            ct++;
        }
        
        // Output result
        if (isMirror == 1) cout << "Mirror\n";
        else cout << "Not mirror\n";

        trav = trav->pnext; // Move to next shape
        currNode++;         // Increase shape index
    }
}
