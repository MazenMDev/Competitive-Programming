#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

bool comp (pair<string , int> & a , pair<string , int> & b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    fast_io();
    int x , y , z; cin >> x >> y >> z;

    string str; cin >> str;

    //------------------STACK--------------------//

    //Stack is the exact opposite of a queue
    //No random access , no iterators , no constructors
    //used in stuff such as function call management and memory management
    //You could only access the top of the stack (the last item), think of it as a container.
    //LAST IN FIRST OUT (LIFO) means you pop only the last element
    stack <int> s;
    s.push(x);
    s.push(y);
    s.push(z);
    // Output: Z Y X . last in first out , first in last out
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl << endl;

    //------------------QUEUE--------------------//
    //As mentioned, a queue is the exact opposite of a stack;
    //No random access , no iterators , no constructors
    //used in stuff such as operating systems and web servers.
    //You could only access the front and back of the queue , similar to a real queue.
    //FIRST IN FIRST OUT (FIFO) , means you pop out the first element.
    queue<int> q;
    q.push(x);
    q.push(y);
    q.push(z);

    // Output: X Y Z. First in first out , last in last out
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl << endl;


    //------------------PRIORITY QUEUE--------------------//
    //Similar to the properties of a queue but it's organized.
    priority_queue<int> pq; //organizes the items from smaller to greater , so top is always the greatest

    //but on the other side if you add a vector and greater it organizes it from greater to smaller so the top is always the smallest.
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq.push(x);
    pq.push(y);
    pq.push(z);

    pq2.push(x);
    pq2.push(y);
    pq2.push(z);

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl << endl;

    while (!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl << endl;

    //================================ASSOSIATIVE CONTAINERS==================================//
    //they have dynamic sizes and very fast sorting (log n) , also insert and erase are (log n)


    //------------------Pair--------------------//
    //used in various of applications. such as storing related data (databases for students' grade maybe)
    //it's like an array with 2 cells "pair" :)
    //you dont have to use int and strings only , you can use any datatype.
    pair<string , int> p;
    p.second = x;
    p.first = str;
    cout << p.first << " " << p.second << endl;

    cout << endl;
    //you can make an array of pairs , or even a vector of pairs
    // vector<pair<string , int>> p;

    pair<string , int> p2[3];
    p2[0].first = "first";
    p2[0].second = 50;

    p2[1].first = "second";
    p2[1].second = y;

    p2[2].first = "a";
    p2[2].second = z;

    for(int i = 0; i < 3; i++) {
        cout << p2[i].first << " " << p2[i].second << endl;
    }
    cout << endl <<endl;

    //sorting in pairs sorts depending on first datatype inside , in our case its the string
    sort(begin(p2) , end(p2));
    for(int i = 0; i < 3; i++) {
        cout << p2[i].first << " " << p2[i].second << endl;
    }
    cout << endl << endl;

    //you can sort to the second in the pair by making a function that returns a bool and takes parameters of 2 pairs.

    /*

    bool comp (pair<string , int> & a , pair<string , int> & b){
        return a.second < b.second;
    }

    then add a parameter of the name of the function "comp" to the sorting function.

    so it becomes
    sort(begin(p2) , end(p2));

    */
    sort(begin(p2) , end(p2) , comp);
    for(int i = 0; i < 3; i++) {
        cout << p2[i].first << " " << p2[i].second << endl;
    }
    cout << endl << endl;

    //------------------SET--------------------//
    //it organizes the numbers and removes any duplicates.
    //it was explained in the course we took as a hash table  , but the difference is that a hash table lets duplicates but a set does not

    set<int> st;
    st.insert(z);
    st.insert(x);
    st.insert(y);
    st.insert(z); //we duplicated z to test if it lets a duplicate or not
    //st.erase removes the number you send (its value) not the index only if it exists;
    //if you want to erase through index then do st.erase(next( st.begin() , idx));

    //you could also erase a number of cells;
    //.find() returns an iterator of the argument , use auto as datatype , but if the number doesnt exist the auto vaariable you set now points as an iterator to the end of the set
    for ( auto i : st) {
        cout << i << " ";
    }
    cout << endl << endl;

    st.erase(20);

    for ( auto i : st) {
        cout << i << " ";
    }
    cout << endl << endl;

    st.erase(next(st.begin() ,1));
    for ( auto i : st) {
        cout << i << " ";
    }
    cout << endl << endl;
}