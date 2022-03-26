#include<bits/stdc++.h>
using namespace std;

/**
 * Given an n x n matrix mat[n][n] of integers, 
 * find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.
 */

const int n = 5;

int maxValOfDifference(int mat[n][n], int n){
    int maxV = INT_MIN;

    int dp[n][n];
    for(int i=0; i< n; i++)
        for(int j=0; j<n; j++)
            dp[i][j] = mat[i][j];


    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++) if(i | j != 0){
            if(i>=1 && j>=1){
                maxV = max({ maxV, mat[i][j] - dp[i-1][j-1] });
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            }
            if(i>=1)
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j>=1)
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }

    return maxV;
}

int main(){

    int mat[n][n] = {
        { 1, 2, -1, -4, -20 },
        { -8, -3, 4, 2, 1 }, 
        { 3, 8, 6, 1, 3 },
        { -4, -1, 1, 7, -6 },
        { 0, -4, 10, -5, 1 }
    };
    
    cout<<maxValOfDifference(mat, n);
}
