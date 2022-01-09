#include<bits/stdc++.h>
using namespace std;

long long trappingWater(int arr[], int n){
    vector<int> l(n), r(n);
    l[0] = arr[0];
    r[0] = arr[n-1];
    for(int i=1; i<n; i++) l[i] = max(l[i-1], arr[i-1]);
    for(int i=n-2; i>=0; i--) r[i] = max(r[i+1], arr[i+1]);
    
    long long tot = 0;
    for(int i=0; i<n; i++){
        int amnt = min(l[i], r[i]) - arr[i];
        if(amnt > 0) tot += amnt; 
    }
    return tot;
}
