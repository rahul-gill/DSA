vector<vector<int>> dp;
int lcs(int x, int y, const string& s1, const string& s2, int init = 1){
    if(!x || !y)
        return 0;
    if(init)
        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));

    if(dp[x][y] != -1)  
        return dp[x][y];


    if(s1[x-1] == s2[y-1])
        return dp[x][y] =  1 + lcs(x-1,y-1,s1,s2,0);
    else
        return dp[x][y] = max(lcs(x-1,y,s1,s2,0), lcs(x,y-1,s1,s2,0));
}
 

int lcs(int x, int y, string s1, string s2){
    arr_2d dp(s1.size()+1, vector<int>(s2.size()+1, 0));

    for(int i=s1.size()-1; i>=0; --i)
        for(int j=s2.size()-1; j>=0; --j){
            if(s1[i] == s2[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    return dp[0][0];
}
  
