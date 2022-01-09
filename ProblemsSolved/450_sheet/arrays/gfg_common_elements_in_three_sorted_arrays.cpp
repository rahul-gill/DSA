#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        int lastA = INT_MIN, lastB = INT_MIN, lastC = INT_MIN;
        vector<int> commmons;
        
        int i=0, j=0, k=0;
        while (i!=n1 and j!=n2 and k!=n3){
            while (A[i] == lastA and i != n1) lastA = A[i++];
            while (B[j] == lastB and j != n2) lastB = B[j++];
            while (C[k] == lastC and k != n3) lastC = C[k++];
            if(i == n1 or j == n2 or k == n3) break;

            if(A[i] < B[j] or A[i] < C[k]) lastA = A[i++];
            else if(B[j] < C[k] or B[j] < A[i]) lastB = B[j++];
            else if(C[k] < B[j] or C[k] < A[i]) lastC = C[k++];
            else{
                commmons.push_back(A[i]); 
                lastA = A[i++];
                lastB = B[j++]; 
                lastC = C[k++];
            }
        }
        return commmons;
    }
    
};