#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k; 
        cin>>n>>k;
        vector<int> arr(n);
        for(auto &x: arr) cin>>x;
        if(n == 1){
            cout<<"YES\n";
            continue;
        }

        sort(arr.begin(), arr.end());
        int element0 = arr[0], arrSizeCurrent = arr.size();
        for(auto x = arr.begin()+1; x != arr.end(); ++x)
            if(*x + element0 <= k) arrSizeCurrent--;
        if(arrSizeCurrent == 1) cout<<"YES\n";
        else cout<<"NO\n";
    }
}