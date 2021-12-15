#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc=1;
	cin>>tc;
	while(tc--){
        long long n;
        cin>>n;
        if(n == 1) cout<<"1\n";
        else if(n == 2) cout<<"2\n";
        else if((n & (n - 1)) == 0){
            cout<<(n*2-1) % mod<<'\n';
        }
        else{
            long long x = ceil(log2(n));
            cout<<(1l<<x) % mod<<'\n';
        }
	}

}
