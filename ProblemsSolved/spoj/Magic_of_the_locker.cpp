#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
long long solve(long long indx){
    long long res = 1, base = 3;
    while(indx>0){
        if(indx & 1) res = (res*base) % MOD;
        base = (base*base) % MOD;
        indx >>= 1;
    }
    return res;
}

int main(){
   int t;
   cin>>t;
   while(t--){
        long long n;
        cin>>n;
        if(n<3) { cout<<n<<'\n';continue; }
        long long ans;
        if(n%3 == 1)
            ans = 4ll*solve((n - 4) / 3);
		else if(n%3 == 2) 
            ans = 2ll*solve((n-2)/3);
		else ans = solve(n/3);
		ans %= MOD;
		cout << ans << endl;
   } 
}