#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int ,int>m;
        int a=0;
        for(int i=0; i<n; i++){
            int b=k-arr[i];
            if(m[b]) a += m[b];
            m[arr[i]]++;
        }
        return a;    
    }
};
