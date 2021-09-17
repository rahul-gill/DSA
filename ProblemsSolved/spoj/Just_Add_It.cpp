#include<bits/stdc++.h>
using namespace std;
#define MOD 10000007
long long binexp(long long base, long long index){
    base %= MOD;
    long long res = 1;
    while(index>0){
        if(index & 1) res = (res*base) % MOD;
        base = (base * base) % MOD;
        index >>= 1;
    }
    return res;
}

int main(){
    long long n,k;
    while(cin>>n>>k && (n+k)){
        long long result = (binexp(n,k) + 2*binexp(n-1,k)+ binexp(n,n) + 2* binexp(n-1,n-1) ) % MOD;
        cout<<result<<'\n';
    }
}