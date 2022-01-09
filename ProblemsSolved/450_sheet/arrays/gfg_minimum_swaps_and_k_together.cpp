#include<bits/stdc++.h>
using namespace std;


int minSwap(int arr[], int n, int k) {
    if(n <= 2) return 0;
    
    int wnd = 0, cnt = 0;
    for(int i=0; i<n; i++)
        if(arr[i] <= k) wnd++;

    for(int i=0; i<wnd; i++)
        if(arr[i] > k) cnt++;

    int ans = cnt;

    for(int i=1; i<= n-wnd; i++){
        if(arr[i-1] > k) cnt--;
        if(arr[i+wnd-1] > k) cnt++;
        ans = min(ans, cnt);
    }
    return ans;
}

