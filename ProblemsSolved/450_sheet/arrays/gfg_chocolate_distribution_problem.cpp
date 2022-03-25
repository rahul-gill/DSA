#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array of n integers where each value represents the number of chocolates in a packet.
 * Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:
 * - Each student gets one packet.
 * - The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to
 * the students is minimum.
 * return that minimum difference
 */


/**
 * we have to chose m elements of array such that difference of minimum & maximum elements is minimum
 * for that they should be closest in sorted array
 */

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());

    long long num= INT_MAX;
    for(int i=0; i+m <= n; i++){
        int j= i+m-1;
        num = min(num, a[j] - a[i]);
    }
   return num;
}   
