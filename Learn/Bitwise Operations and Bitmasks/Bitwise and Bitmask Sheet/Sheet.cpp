#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {

    uint32_t num;
    cin >> num;

    // ------------------------------
    // 1. **Extract a single bit**
    int i = 3;
    int bit = (num >> i) & 1; // Extract ith bit
    cout << "Bit at position " << i << " = " << bit << "\n";

    // ------------------------------
    // 2. **Set a bit (make it 1)**
    num |= (1u << i);

    // ------------------------------
    // 3. **Clear a bit (make it 0)**
    num &= ~(1u << i);

    // ------------------------------
    // 4. **Toggle a bit (flip)**
    num ^= (1u << i);

    // ------------------------------
    // 5. **Check if bit is set**
    bool isSet = (num & (1u << i)) != 0; // 0 == NOT SET   

    // ------------------------------
    // 6. **Count set bits**
    int cnt = __builtin_popcount(num); // For 32-bit
    // __builtin_popcountll(num) for 64-bit

    // ------------------------------
    // 7. **Swap adjacent bits**
    uint32_t result = 0;
    for (int i = 0; i < 32; i += 2) {
        uint32_t bit1 = (num >> i) & 1;
        uint32_t bit2 = (num >> (i + 1)) & 1;
        result |= (bit1 << (i + 1));
        result |= (bit2 << i);
    }

    // ------------------------------
    // 8. **Reverse all bits**
    uint32_t rev = 0;
    uint32_t temp = num;
    for (int i = 0; i < 32; i++) {
        rev = (rev << 1) | (temp & 1);
        temp >>= 1;
    }

    // ------------------------------
    // 9. **Check if number is power of 2**
    bool powerOf2 = (num && !(num & (num - 1)));

    // ------------------------------
    // 10. **Get lowest set bit**
    int lowest = num & -num;

    // ------------------------------
    // 11. **Turn off lowest set bit*
    num = num & (num - 1);

    // ------------------------------
    // 12. **Generate all subsets of a mask**
    int mask = 5;
    for (int sub = mask; sub; sub = (sub - 1) & mask) {
        cout << sub << "\n"; // All submasks of mask
    }

    // ------------------------------
    // 13. **Even or Odd**
    if(num & 1) // Even
    //else is Odd

    

    return 0;
}
