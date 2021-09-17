#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(auto &x:arr) cin>>x;

        int planA = -1;
        for(int i=0; i<n-1; i++){
            if(arr[i] == 0 && arr[i+1] == 1){
                planA = i;
                break;
            }
        }

        if(planA != -1){
            for(int i=0;i<=planA;i++) cout<<(i+1)<<' ';
            cout<<(n+1)<<' ';
            for(auto i=planA+1; i<n; i++) cout<<(i+1)<<' ';
        }else if(arr[0] == 1){
            cout<<(n+1)<<' ';
            for(int i=1; i<=n; i++) cout<<i<<' ';
        }else{
            for(int i=1; i<=n+1; i++) cout<<i<<' ';
        }
        cout<<'\n';
    }
}
