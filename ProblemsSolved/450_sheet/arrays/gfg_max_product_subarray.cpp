#include<bits/stdc++.h>
using namespace std;


long long maxProduct(vector<int> arr, int n) {
    //Minimum is also tracked because smaller negative numbers can make large positive number after multiplying
    int max_ending_here = arr[0];
    int min_ending_here = arr[0];
    int max_so_far = arr[0];

    for (int i = 1; i < n; i++){
        min_ending_here = min({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        max_ending_here = max({arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here});
        max_so_far = max(max_so_far, max_ending_here);
        cout<<min_ending_here<<' '<<max_ending_here<<' '<<max_so_far<<endl;
    }
    return max_so_far;
}

int main(){
    int N = 5; vector<int> arr = {6, 3, 10, 0, 2};
    cout<<maxProduct(arr, N);
}