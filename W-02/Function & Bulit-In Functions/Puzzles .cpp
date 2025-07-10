#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int* num= new int[n];
    for(int i=0; i<m; i++){
        cin >> num[i];
    }
    sort(num,num+n);
    reverse(num,num+n);
    int sum = 0;
    int min = 9999999;
    for(int i=0; i<=(m-n); i++){
        for(int j=0; j<n; j++){
            sum+=num[i];
        }
        if (min > sum){
            min = sum;
        }
    }
    cout << min << endl;
}