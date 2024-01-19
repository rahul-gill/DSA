#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    printf("%d^%d\t",a,b);
    if (b % 2){
        printf("%lld = %lld * %lld * %lld\n",res*res*a,res,res,a);
        return res * res * a;
    }
    else{
        printf("%lld = %lld * %lld\n",res*res,res,res);
        return res * res;
    }
}

int main(){
    binpow(3,13);
}