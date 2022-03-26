#include<bits/stdc++.h>
using namespace std;

/**
 * Given an m x n matrix, 
 * find all common elements present in all rows in O(mn) time and one traversal of matrix.
 */

vector<int> findCommonElements(vector<vector<int>> &mat){
    if(mat.size() == 1) return mat[0];

    unordered_map<int, int> elems;
    vector<int> ans;
    for(auto x: mat[0]) elems[x] = 1;

    for(int i=1; i<mat.size(); i++){
        for(auto x: mat[i]){
            if(elems[x] == i){
                elems[x]++;
                if(i == mat.size()-1 && elems[x] == mat.size())
                    ans.push_back(x);
            }
        }
    }

    return ans;
}

