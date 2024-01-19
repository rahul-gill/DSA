#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long ans = 2ll*4*3*pow(4,n-3);
    if(n>3) ans += (n-3)*4ll*3*3*pow(4,n-4);
    cout<<ans<<'\n';
}