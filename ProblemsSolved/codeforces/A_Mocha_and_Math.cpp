#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans = INT_MAX;
        vector<int> arr(n),arr2;
        for(auto &x:arr) {
            cin>>x;
            ans &= x;
        }
        cout<<ans<<'\n';
    }
}
