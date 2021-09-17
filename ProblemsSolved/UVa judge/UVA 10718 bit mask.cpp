#include<bits/stdc++.h>
using namespace std;

long long n,l,u;

int main(){
	while(cin>>n>>l>>u){
		long long msb = (int)(log2(u)), ans=0;
		for(int i=msb+1;i>=0;i--){
			long long m = 1ll<<i;
			if(!(m & n)){
				if(ans + m <= u) ans += m;
			}else{
				if(ans + m <= l) ans += m;
			}
		}
		cout<<(ans)<<'\n';
	}
}