#include<bits/stdc++.h>
using namespace std;

int n,m, p[110], f[110];
int dp[110][10000];

int solve(int indx=0, int moneyDone = 0){
	if(indx == n) return 0;	
	int &ret = dp[indx][moneyDone];
	if(ret != -1) return ret;
	int xx=0,yy;
	int newMoney = moneyDone + p[indx];
	if((newMoney > 2000 && newMoney <= m + 200) || newMoney <=m) 
		xx = solve(indx+1, newMoney) + f[indx];
	yy = solve(indx+1, moneyDone);
	return ret = max(xx,yy);
}

int main(){
	while(cin>>m>>n){
		for(int i=0;i<n;i++) cin>>p[i]>>f[i];
		memset(dp,-1,sizeof(dp));
		int res = solve();
		cout<<res<<'\n';
	}
} 
