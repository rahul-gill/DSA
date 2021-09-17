#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        if(l*2 <= r){
            int x = (r+1)/2;
            cout<<((x*2-1)%x)<<'\n';
        }else{
            cout<<(r%l)<<'\n';
        }
    }
}
