#include<cp_debug.h>

const long long mod = 1e9 + 7;

long long int  countPS(string str){
    int n=str.size();
    long long int dp[n][n];
    
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap==0)
                dp[i][j]=1;
            else if(gap==1)
                dp[i][j] = str[i]==str[j] ? 3 : 2;
            else{
                if(str[i]==str[j])
                    dp[i][j]=(dp[i][j-1]%mod + (dp[i+1][j]%mod+1)%mod) % mod;
                else
                    dp[i][j]=(dp[i][j-1]%mod + dp[i+1][j]%mod - dp[i+1][j-1]%mod) % mod;
                if (dp[i][j] < 0) dp[i][j] += mod;
            }
        }
    }
    return dp[0][n-1]%mod;
}

