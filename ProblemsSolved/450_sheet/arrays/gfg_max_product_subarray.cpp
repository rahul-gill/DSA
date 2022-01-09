#include<bits/stdc++.h>
using namespace std;


long long maxProduct(vector<int> arr, int n) {
    int max_ending_here = arr[0];
    int min_ending_here = arr[0];
    int max_so_far = arr[0];
    for (int i = 1; i < n; i++){
        int temp = max({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        min_ending_here = min({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        max_ending_here = temp;
        max_so_far = max(max_so_far, max_ending_here);
        cout<<min_ending_here<<' '<<max_ending_here<<' '<<max_so_far<<endl;
    }
    return max_so_far;
}

int main(){
    int N = 5; vector<int> arr = {6, 3, 10, 0, 2};
    cout<<maxProduct(arr, N);
}