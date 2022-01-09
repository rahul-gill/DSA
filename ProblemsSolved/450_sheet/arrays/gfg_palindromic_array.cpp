#include<bits/stdc++.h>
using namespace std;

int PalinArray(int a[], int n)
{
    for(int k=0; k<n; k++){
        string s = to_string(a[k]);
        int i = 0, j = s.size() - 1;
        while(i<j){
            if(s[i] != s[j]) return 0;
            i++,j--;
        }
    }
    return 1;
}
