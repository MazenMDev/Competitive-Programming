#include <iostream>  // Include input/output stream library for cin and cout
using namespace std;  // Use standard namespace to avoid writing std:: before cout, cin, etc.

// Define the Node class as specified in the problem
class CNode
{
public:
    int V1, V2;              // V1 and V2 store integer values (V1=height, V2=width for list nodes)
    CNode* pNext, *pPrev;    // Pointers to next and previous nodes (horizontal links)
    CNode* pDown, *pUp;      // Pointers to down and up nodes (vertical links)
    
    // Constructor to initialize all values to 0 and all pointers to NULL
    CNode() {
        V1 = V2 = 0;                           // Initialize V1 and V2 to zero
        pNext = pPrev = pDown = pUp = NULL;    // Initialize all pointers to NULL
    }
};

// Stack class implemented using linked list (no arrays or vectors)
class Stack {
private:
    CNode* top;   // Pointer to the top element of the stack
public:
    // Constructor: Initialize empty stack
    Stack() {
        top = NULL;   // Set top to NULL (empty stack)
    }
    
    // Push a new value onto the top of the stack
    void push(int value) {
        CNode* newNode = new CNode();   // Create a new node dynamically
        newNode->V1 = value;            // Store the value in V1 field
        newNode->pNext = top;           // Link new node to current top
        top = newNode;                  // Update top to point to new node
    }
    
    // Pop and return the top value from the stack
    int pop() {
        if(top == NULL) return -999999; // If stack is empty, return error value
        int val = top->V1;              // Get the value from top node
        CNode* temp = top;              // Store pointer to top node
        top = top->pNext;               // Move top pointer to next node
        delete temp;                    // Free memory of the old top node
        return val;                     // Return the popped value
    }
    
    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;   // Return true if top is NULL, false otherwise
    }
    
    // Destructor: Clean up all nodes when stack is destroyed
    ~Stack() {
        while(top != NULL) {            // Loop while stack is not empty
            CNode* temp = top;          // Store pointer to current top
            top = top->pNext;           // Move to next node
            delete temp;                // Delete the old top node
        }
    }
};

int main(){
    int n;   // Variable to store the number of nodes in the main linked list
    cout << "Enter number of nodes in the main linked list: ";   // Prompt user
    cin >> n;   // Read the number of nodes
    
    // Pointers for the main linked list (stores all list nodes)
    CNode* listHead = NULL;   // Pointer to the first node in the main list
    CNode* listTail = NULL;   // Pointer to the last node in the main list
    
    // Loop through each node in the main linked list
    for(int nodeIdx = 0; nodeIdx < n; nodeIdx++){
        CNode* listNode = new CNode();   // Create a new node for the main list
        
        // Display which node we're processing
        cout << "\nNode " << (nodeIdx + 1) << ":" << endl;
        cout << "Enter V1 (height) and V2 (width): ";
        cin >> listNode->V1 >> listNode->V2;   // Read height and width from user
        
        // Add the new node to the main linked list
        if(listHead == NULL) {               // If this is the first node
            listHead = listNode;             // Set it as head
            listTail = listNode;             // Set it as tail (only one node)
        } else {                             // If list already has nodes
            listTail->pNext = listNode;      // Link old tail's pNext to new node
            listNode->pPrev = listTail;      // Link new node's pPrev to old tail
            listTail = listNode;             // Update tail to point to new node
        }
        
        int h = listNode->V1;   // Store height in a local variable for convenience
        int w = listNode->V2;   // Store width in a local variable for convenience
        int totalNodes = 2*h + 2*w - 4;  // Calculate perimeter nodes: top(h) + right(w-1) + bottom(h-1) + left(w-2)
        
        // Check if dimensions are valid
        if(totalNodes <= 0) {
            cout << "Invalid dimensions!" << endl;   // Display error message
            continue;   // Skip to next node in main list
        }
        
        // Prompt user to enter all values for the cyclic structure
        cout << "Enter " << totalNodes << " values clockwise (including -1 and -2): ";
        
        // Build the cyclic 2D rectangular structure above this list node
        CNode* prevNode = NULL;     // Pointer to the previously created node (for linking)
        CNode* firstNode = NULL;    // Keep track of the very first node to close the cycle later
        
        // Variables to track edges of the rectangle for proper 2D linking
        int edgeCounter = 0;        // Counts which edge we're on (0=top, 1=right, 2=bottom, 3=left)
        int nodesInCurrentEdge = 0; // Counts nodes added to current edge
        
        // Number of nodes per edge (stored as separate variables instead of array)
        int edgeLimit0 = h;          // Top edge: h nodes going up
        int edgeLimit1 = w - 1;      // Right edge: w-1 nodes going right
        int edgeLimit2 = h - 1;      // Bottom edge: h-1 nodes going down
        int edgeLimit3 = w - 2;      // Left edge: w-2 nodes going left
        
        // Read all nodes in clockwise order and link them using pUp/pDown/pNext/pPrev
        for(int i = 0; i < totalNodes; i++){
            CNode* newNode = new CNode();   // Create a new node for the cycle
            cin >> newNode->V1;             // Read the value for this node
            
            if(i == 0) {                          // If this is the first node in the cycle
                firstNode = newNode;              // Remember first node for closing cycle and traversal
                listNode->pUp = firstNode;        // Connect main list node to first cycle node via pUp
            } else {                              // For all subsequent nodes
                // Link based on which edge we're currently building
                if(edgeCounter == 0) {            // Top edge: nodes go UP
                    prevNode->pUp = newNode;      // Previous node's pUp points to new node
                    newNode->pDown = prevNode;    // New node's pDown points to previous node
                } 
                else if(edgeCounter == 1) {       // Right edge: nodes go RIGHT
                    prevNode->pNext = newNode;    // Previous node's pNext points to new node
                    newNode->pPrev = prevNode;    // New node's pPrev points to previous node
                } 
                else if(edgeCounter == 2) {       // Bottom edge: nodes go DOWN
                    prevNode->pDown = newNode;    // Previous node's pDown points to new node
                    newNode->pUp = prevNode;      // New node's pUp points to previous node
                } 
                else if(edgeCounter == 3) {       // Left edge: nodes go LEFT
                    prevNode->pPrev = newNode;    // Previous node's pPrev points to new node
                    newNode->pNext = prevNode;    // New node's pNext points to previous node
                }
            }
            
            prevNode = newNode;           // Update previous node to current node
            nodesInCurrentEdge++;         // Increment counter for current edge
            
            // Check if we've completed the current edge (check against appropriate limit)
            int currentEdgeLimit;  // Variable to hold the limit for current edge
            if(edgeCounter == 0) currentEdgeLimit = edgeLimit0;
            else if(edgeCounter == 1) currentEdgeLimit = edgeLimit1;
            else if(edgeCounter == 2) currentEdgeLimit = edgeLimit2;
            else currentEdgeLimit = edgeLimit3;
            
            if(nodesInCurrentEdge == currentEdgeLimit) {
                edgeCounter++;            // Move to next edge
                nodesInCurrentEdge = 0;   // Reset counter for new edge
            }
        }
        
        // Close the cycle by connecting the last node back to the first node
        if(prevNode && firstNode) {       // Check both pointers are valid
            prevNode->pPrev = firstNode;  // Last node's pPrev points to first node (completing left edge)
            firstNode->pNext = prevNode;  // First node's pNext points to last node (closing the loop)
        }
        
        // Find the positions of marker nodes (-1 and -2) in the cycle
        CNode* marker1 = NULL;  // Pointer to the node containing -1
        CNode* marker2 = NULL;  // Pointer to the node containing -2
        
        // Traverse the 2D structure clockwise to find markers
        CNode* temp = firstNode;   // Start from the first node of the cycle
        int edge = 0;              // Current edge (0=up, 1=right, 2=down, 3=left)
        int nodesInEdge = 1;       // Start at 1 because we're at the first node
        
        // Check first node
        if(temp->V1 == -1) marker1 = temp;
        if(temp->V1 == -2) marker2 = temp;
        
        // Loop through remaining nodes
        for(int i = 1; i < totalNodes; i++){
            // Inline navigation logic (replacing getNextClockwise function)
            // Calculate nodes per edge without using array
            int edgeLimit;  // Number of nodes for current edge
            if(edge == 0) edgeLimit = h;          // Top edge: h nodes
            else if(edge == 1) edgeLimit = w-1;   // Right edge: w-1 nodes
            else if(edge == 2) edgeLimit = h-1;   // Bottom edge: h-1 nodes
            else edgeLimit = w-2;                 // Left edge: w-2 nodes
            
            // Check if we need to move to next edge
            if(nodesInEdge >= edgeLimit) {
                edge++;              // Move to next edge
                nodesInEdge = 0;     // Reset counter
            }
            
            // Move to next node based on current edge direction
            if(edge == 0) temp = temp->pUp;         // Top edge: go UP
            else if(edge == 1) temp = temp->pNext;  // Right edge: go RIGHT
            else if(edge == 2) temp = temp->pDown;  // Bottom edge: go DOWN
            else if(edge == 3) temp = temp->pPrev;  // Left edge: go LEFT
            
            nodesInEdge++;  // Increment nodes in current edge
            
            if(temp->V1 == -1) marker1 = temp;    // If current node has -1, store its pointer
            if(temp->V1 == -2) marker2 = temp;    // If current node has -2, store its pointer
        }
        
        // Validate that both markers were found
        if(marker1 == NULL || marker2 == NULL) {
            cout << "Error: Missing -1 or -2 markers!" << endl;   // Display error
            continue;   // Skip to next main list node
        }
        
        // Count how many nodes are between -1 and -2 (clockwise)
        int count = 0;         // Counter for nodes between markers
        temp = firstNode;      // Start from beginning
        edge = 0;              // Reset edge
        nodesInEdge = 1;       // Reset counter
        bool counting = false; // Flag to track when we're between markers
        
        // Check if first node starts counting
        if(temp == marker1) counting = true;
        
        // Traverse and count
        for(int i = 1; i < totalNodes; i++){
            // Inline navigation logic
            int edgeLimit;  // Number of nodes for current edge
            if(edge == 0) edgeLimit = h;          // Top edge: h nodes
            else if(edge == 1) edgeLimit = w-1;   // Right edge: w-1 nodes
            else if(edge == 2) edgeLimit = h-1;   // Bottom edge: h-1 nodes
            else edgeLimit = w-2;                 // Left edge: w-2 nodes
            
            // Check if we need to move to next edge
            if(nodesInEdge >= edgeLimit) {
                edge++;              // Move to next edge
                nodesInEdge = 0;     // Reset counter
            }
            
            // Move to next node based on current edge direction
            if(edge == 0) temp = temp->pUp;         // Top edge: go UP
            else if(edge == 1) temp = temp->pNext;  // Right edge: go RIGHT
            else if(edge == 2) temp = temp->pDown;  // Bottom edge: go DOWN
            else if(edge == 3) temp = temp->pPrev;  // Left edge: go LEFT
            
            nodesInEdge++;  // Increment nodes in current edge
            
            if(counting && temp != marker2) {
                count++;  // Count this node
            }
            
            if(temp == marker1) counting = true;   // Start counting after marker1
            if(temp == marker2) break;             // Stop when we reach marker2
        }
        
        cout << "Sequence between -1 and -2: ";   // Display message
        
        // Check if the sequence forms a mirror (palindrome) using a stack
        Stack s;                    // Create a stack for palindrome checking
        bool isMirror = true;       // Flag to track if sequence is a mirror
        
        // Reset for mirror check traversal
        temp = firstNode;
        edge = 0;
        nodesInEdge = 1;
        bool started = false;
        int idx = 0;
        
        // Check first node
        if(temp == marker1) started = true;
        
        // Traverse and check mirror
        for(int i = 1; i <= totalNodes; i++){
            if(i < totalNodes) {
                // Inline navigation logic
                int edgeLimit;  // Number of nodes for current edge
                if(edge == 0) edgeLimit = h;          // Top edge: h nodes
                else if(edge == 1) edgeLimit = w-1;   // Right edge: w-1 nodes
                else if(edge == 2) edgeLimit = h-1;   // Bottom edge: h-1 nodes
                else edgeLimit = w-2;                 // Left edge: w-2 nodes
                
                // Check if we need to move to next edge
                if(nodesInEdge >= edgeLimit) {
                    edge++;              // Move to next edge
                    nodesInEdge = 0;     // Reset counter
                }
                
                // Move to next node based on current edge direction
                if(edge == 0) temp = temp->pUp;         // Top edge: go UP
                else if(edge == 1) temp = temp->pNext;  // Right edge: go RIGHT
                else if(edge == 2) temp = temp->pDown;  // Bottom edge: go DOWN
                else if(edge == 3) temp = temp->pPrev;  // Left edge: go LEFT
                
                nodesInEdge++;  // Increment nodes in current edge
            }
            
            if(started && temp != marker2) {
                cout << temp->V1 << " ";       // Print current value
                
                if(idx < count / 2) {          // If we're in the first half
                    s.push(temp->V1);          // Push value onto stack
                } else if(idx >= (count + 1) / 2) {   // If we're in the second half (skip middle if odd)
                    int stackVal = s.pop();           // Pop value from stack
                    if(stackVal != temp->V1) {        // Compare popped value with current value
                        isMirror = false;             // If they don't match, it's not a mirror
                    }
                }
                idx++;
            }
            
            if(temp == marker1) started = true;  // Start after marker1
            if(temp == marker2) break;           // Stop at marker2
        }
        
        cout << endl;   // End the sequence line
        
        // Display the result based on mirror check
        if(isMirror) {
            cout << "Result: MIRROR" << endl;       // Sequence is a palindrome
        } else {
            cout << "Result: NOT MIRROR" << endl;   // Sequence is not a palindrome
        }
    }
    
    // Program cleanup and exit message
    cout << "\nProgram completed successfully!" << endl;   // Display completion message
    
    return 0;   // Return 0 to indicate successful program execution
}
