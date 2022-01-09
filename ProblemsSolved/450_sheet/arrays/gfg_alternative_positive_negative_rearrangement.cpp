#include<bits/stdc++.h>
using namespace std;




void rearrange(vector<int> &arr){
    int n = arr.size(), i=0, j = n-1;
    //shifting negative numbers to the end
    while (i < j) {
        while (i < n and arr[i] > 0) ++i;
        while (j >= 0 and arr[j] < 0) --j;
        if (i < j )
            swap(arr[i], arr[j]);
    }
    if (i == 0 || i == n) return;
    
    int x = 0;
    while (x < n && i < n ) {
        swap(arr[x], arr[i]);
        ++i;
        x += 2;
    } 
}

int main(){
    vector<int> arr{-5, -2, -1, 5, 2, 4, 7, 1, 8, 0, -8 };
    rearrange(arr);
    for(auto x: arr) cout<<x<<' ';
}  