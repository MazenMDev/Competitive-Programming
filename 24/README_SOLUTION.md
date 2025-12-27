# Problem 1 Solution - Linked List with Cyclic Structures

## Problem Understanding

This program creates a linked list where each node has a **clockwise cyclic structure** attached to it. The structure is a rectangular perimeter defined by:

- **V1**: Height
- **V2**: Width

Each cyclic structure contains:

- One marker with value **-1**
- One marker with value **-2**
- Other integer values

The program checks if the sequence of values **between -1 and -2** (clockwise) forms a **mirror** (palindrome).

## Key Concepts

### CNode Structure

```cpp
class CNode {
public:
    int V1, V2;          // Values or dimensions
    CNode* pNext;        // Right neighbor
    CNode* pPrev;        // Left neighbor
    CNode* pDown;        // Down neighbor
    CNode* pUp;          // Up neighbor
};
```

### Cyclic Structure

For a node with dimensions V1=3 (height) and V2=3 (width):

- Total perimeter nodes = 2*h + 2*w - 4 = 2*3 + 2*3 - 4 = 8 nodes

```
    [0] [1] [2]         (Top edge: h nodes going up)
    [7]     [3]         (Right edge: w-1 nodes going right)
    [6] [5] [4]         (Bottom edge: h-1 nodes going down)
                        (Left edge: w-2 nodes going left)
```

### Reading Order (Clockwise)

1. **Top edge**: h nodes (going up)
2. **Right edge**: w-1 nodes (going right)
3. **Bottom edge**: h-1 nodes (going down)
4. **Left edge**: w-2 nodes (going left)

## Algorithm

1. **Read main linked list size** (n nodes)
2. **For each list node:**
   - Read V1 (height) and V2 (width)
   - Calculate total perimeter nodes: `2*h + 2*w - 4`
   - Read all values in clockwise order
   - Build the cyclic structure with proper links (pUp, pNext, pDown, pPrev)
   - Close the cycle by connecting last node to first
3. **Find markers:**
   - Locate position of -1
   - Locate position of -2
4. **Extract sequence between -1 and -2** (clockwise direction)
5. **Check if palindrome:**
   - Compare first element with last
   - Compare second with second-to-last
   - Continue until middle
6. **Output result:** MIRROR or NOT MIRROR

## Example Test Case

### Input:

```
2
3 3
5 -1 3 3 -2 1 1 1
4 4
1 2 -1 4 5 6 -2 7 8 9 10 11
```

### Explanation:

**Node 1:** V1=3, V2=3

- Cyclic structure: [5, -1, 3, 3, -2, 1, 1, 1]
- Position of -1: index 1
- Position of -2: index 4
- Sequence between -1 and -2: [3, 3]
- Check: 3 == 3 ✓
- **Result: MIRROR**

**Node 2:** V1=4, V2=4

- Cyclic structure: [1, 2, -1, 4, 5, 6, -2, 7, 8, 9, 10, 11]
- Position of -1: index 2
- Position of -2: index 6
- Sequence between -1 and -2: [4, 5, 6]
- Check: 4 != 6 ✗
- **Result: NOT MIRROR**

## Compilation and Execution

```bash
# Compile
g++ -o 25.exe 25.cpp

# Run
./25.exe

# Or with input file
Get-Content test_input.txt | ./25.exe
```

## Time Complexity

- O(n \* m) where:
  - n = number of nodes in main list
  - m = perimeter nodes in each cyclic structure (2*h + 2*w - 4)

## Space Complexity

- O(n \* m) for storing all nodes and structures
