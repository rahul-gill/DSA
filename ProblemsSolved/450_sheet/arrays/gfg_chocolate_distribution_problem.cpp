#include<bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    long long padd = (n-m) / 2;
    
    long long num= INT_MAX;
    for(int i=0; i+m <= n; i++){
        int j= i+m-1;
        num = min(num, a[j] - a[i]);
    }
   return num;
}   
