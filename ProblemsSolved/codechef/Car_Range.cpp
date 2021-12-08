#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int p,m,v;
        cin>>p>>m>>v;
        int rate = (m-p+1 > 0) ? (m-p+1) : 0;
        cout<<rate*v<<"\n";
    }
}