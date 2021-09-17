#include<bits/stdc++.h>
using namespace std;

int n;
int primes[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
bool isprime(int k){ return ( find(primes,primes+12,k) != primes+12); }
vector<int> ring;

vector<bool> used;
void solve(int depth = 0){
	if(depth == n){
		for(int i=0;i<n;i++) printf(i==n-1 ? "%d":"%d ",ring[i]);printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(depth == n-1 && (!isprime(ring[0] + i) || used[i]) ) continue;
		if((i==1 || isprime(ring[depth-1]+i)) && !used[i]){
			used[i] = 1;
			ring[depth] = i;
			solve(depth+1);
			used[i] = 0;
		}
		if(depth == 0) break;
	}	
}

int main(){
	int CN = 1;
	while(cin>>n){
		if(CN != 1) printf("\n");
		printf("Case %d:\n",CN++);
		ring = vector<int>(n);
		used = vector<bool>(n+1,0);
		solve();	
	}
}