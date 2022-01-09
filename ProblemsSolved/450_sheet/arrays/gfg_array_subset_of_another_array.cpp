#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_set<int> a1s;
    for(int i=0; i<n; i++) a1s.insert(a1[i]);
    string s = "Yes";
    for(int i=0; i<m; i++){
        if(a1s.find(a2[i]) == a1s.end()){
            s = "No";
            break;
        }
    }
    return s;
}
