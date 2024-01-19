#include<bits/stdc++.h>
using namespace std;

int powrem(int n, int k){
    int res = 1;
    n %= 1000;
    while(k>0){
        if(k & 1) res = (res * n) % 1000;
        n = (n * n) % 1000;
        k >>= 1;
    }
    return res;
}

int main(){
   int t;
   cin>>t;
   while (t--){
       int n,k;
       cin>>n>>k;
       long double power = (double)k * log10(n);
       int firstDigits = pow(10, power - floor(power)) * 100.0;
       printf("%d...%.3d\n",firstDigits,powrem(n,k));
   }
    
}