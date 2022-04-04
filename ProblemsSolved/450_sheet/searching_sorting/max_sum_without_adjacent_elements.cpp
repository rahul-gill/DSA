#include<bits/stdc++.h>
using namespace std;

int findMaxSum(int arr[], int n){
    vector<int> dp(n);
    dp[0] = a[0];
    dp[1] = max(a[1], a[0]);
    
    for(int i = 2; i < n; ++i) {
        dp[i] = max(a[i] + dp[i-2], dp[i-1]);
    }
    
    return dp.back();
}


int main(){

}
