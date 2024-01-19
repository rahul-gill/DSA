#include<bits/stdc++.h>
using namespace std;


int binexp(int a, int b, int m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,n;
        cin>>x>>y>>n;
        cout<<binexp(x,y,n)<<'\n';
    }   
    cout<<flush; 
}