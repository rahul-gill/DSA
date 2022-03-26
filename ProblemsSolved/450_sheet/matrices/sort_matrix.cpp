#include<bits/stdc++.h>
using namespace std;

/**
 * Given an NxN matrix Mat. Sort all elements of the matrix.
 */


vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    vector<int> arr(N*N);
    for(int i=0; i< N*N; i++)
        arr[i] = Mat[i / N][i % N];  
    

    sort(arr.begin(), arr.end());
    
    for(int i=0; i< N*N; i++)
        Mat[i / N][i % N] = arr[i];   
    
    return Mat;
}


int main(){

}
