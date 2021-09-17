#include<bits/stdc++.h>
using namespace std;

int n,q,d,m;
long long nums[250];
int dp[210][15][25];//currentIndex(<=n) x leftToConsider(<=m) x sum%d(<=d)

int solve(int indx=0, int chosen=0, int rem=0){
	if(chosen == m && rem == 0) return 1;
	if(chosen == m && rem !=0) return 0;
	if(indx == n) return 0;
	int &ret =	dp[indx][chosen][rem];
	if(ret != -1) return ret;;

	int tmp = (rem + nums[indx]) % d;
	if(tmp < 0 ) tmp += d;

	int xx = solve(indx+1, chosen+1, tmp);
	int yy = solve(indx+1, chosen, rem);
	return ret = (xx + yy);
}

int main(){
	int sett = 1;
	while(cin>>n>>q && n!=0){
		for(int i=0;i<n;i++) cin>>nums[i];
		printf("SET %d:\n",sett++);
		for(int qq=1;qq<=q;qq++){
			cin>>d>>m;
			memset(dp,-1,sizeof(dp));
			int ans = solve();
			printf("QUERY %d: %d\n",qq,ans);
		}
	}	
} 