#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

/**
 * Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 * You must find a solution with a memory complexity better than O(n2).
 */

int kthSmallest(int mat[MAX][MAX], int n, int k){
    int pushed = 0;
    priority_queue<int> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            q.push(mat[i][j]);
            if(pushed  < k)
                pushed++;
            else
                q.pop();
        }
    }
    return q.top();
}


//better solution: O(n*log(n))
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n-1][n-1];
    
    while (left < right) {
        int middle = left + ((long long)right - left) / 2;
        int count = countSmallorEqual(middle, matrix);
        //no count == k because count middle may not be in the array
        if (count < k) {
            left = middle + 1;
        } else {
            right = middle;
        }
        
    }
    return left;
}

//max iterations: 2*n
int countSmallorEqual(int m, vector<vector<int>>& matrix) {
    int n = matrix.size();
    int count = 0;
    int row = n - 1, col = 0;
    
    //count smaller or equal elements in each column and return sum of those
    while (row >= 0 && col < n) {
        if (m < matrix[row][col]) {
            row--;
        } else {
            count += (row + 1);
            col++;
        }
    }
    return count;
}
