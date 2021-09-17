#include<bits/stdc++.h>
using namespace std;

/**
 * charge = 1.1*(sum(charges_of_dimsums) + n*t )
 * charge/n <= x; 
 *  - don't pay too much
 *  - don't buy too many dishes
*/
int n,x,t,k;
int dimsums[210], favours[210]; 
int maxPrice;
int dp[30][1010];

int main(){
	while(cin>>n>>x>>t>>k && n!=0){
		n++;
		for(auto &x:favours) x = 0;
		for(int i=0;i<2*k;i+=2){
			cin>>dimsums[i];
			dimsums[i+1] = dimsums[i];
			int temp;
			for(int j=0;j<n;j++){ cin>>temp; favours[i]+= temp;}
			favours[i+1] = favours[i];
		}

		maxPrice = ((double)(n) * (double)x) / 1.1 + 1e-9 - (double)((n) * t);
        for(int i=0; i<k*2; i++){
			for(int j=2*n; j>0; j--) for(int kk=maxPrice; kk>=dimsums[i]; kk--)
   	        	dp[j][kk] = max(dp[j -  1 ][kk - dimsums[i]] + favours[i], max(dp[j -  1 ][kk], dp[j][kk]));
		}
		
        int res = INT_MIN; 
        for(int i=0;i<=2*n;i++) { 
            res = max(dp[i][maxPrice], res); 
        } 
		printf("%.2f\n",1.0*res/(n));
	}
} 
