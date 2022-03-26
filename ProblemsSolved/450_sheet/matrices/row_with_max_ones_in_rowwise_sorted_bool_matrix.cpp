#include<bits/stdc++.h>
using namespace std;

/**
 * Given a boolean 2D array of n x m dimensions where each row is sorted. 
 * Find the 0-based index of the first row that has the maximum number of 1's.
 */

//wrong variable names
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int rowWithMaxOnes = 0, i = 0, maxOnesUptoNow = 0;
    for(auto row: arr){
        int ones = row.end() -  lower_bound(row.begin(), row.end(), 1);
        if(ones > maxOnesUptoNow){
            rowWithMaxOnes = i;
            maxOnesUptoNow = ones;
        }
        i++;
    }
    if(maxOnesUptoNow == 0) return -1; 
    return rowWithMaxOnes;
}


int main(){

}
