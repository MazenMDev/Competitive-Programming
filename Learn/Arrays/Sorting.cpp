#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int32_t number;
    cin >> number;
    int32_t num[number];
    for(int i=0; i<number; i++)
        cin >> num[i];

    for(int i=0; i<number; i++){
        int32_t min =i;
        for(int j=i+1 ; j<number; j++){
            if(num[j] < num[min]){
                min = j;
            }
        }
        swap(num[i], num[min]);
    }

    for(int i=0; i<number; i++){
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}