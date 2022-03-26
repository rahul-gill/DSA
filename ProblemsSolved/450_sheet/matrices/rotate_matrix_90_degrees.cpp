#include<bits/stdc++.h>
using namespace std;

/**
 * You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
 * You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
 * DO NOT allocate another 2D matrix and do the rotation.
 */

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<ceil(n/2.0); i++){
        for(int j=i; j<n-i-1; j++){
            int &lt = matrix[i][j];
            int &lb = matrix[n - j - 1][i];
            int &rt = matrix[j][n-i-1];
            int &rb = matrix[n - i - 1][n - j - 1];
            
            int tmp1 = lt, tmp2 = rb;
            
            lt = lb;
            rb = rt;
            lb = tmp2;
            rt = tmp1;
        }
    }
}

