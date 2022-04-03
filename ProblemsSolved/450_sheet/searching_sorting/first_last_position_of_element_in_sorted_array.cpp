#include<bits/stdc++.h>
using namespace std;

/** 
 * Given a sorted array arr containing n elements with possibly duplicate elements, 
 * the task is to find indexes of first and last occurrences of an element x in the given array.
 */


vector<int> find(int arr[], int n , int x ){
    auto low = lower_bound(arr, arr + n, x);

    if(low == arr + n || *low != x) return vector<int>{-1,-1};

    return vector<int>{ int(low - arr), int(upper_bound(arr, arr + n, x) - 1 - arr) };
}

int main(){
    int arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 };
    
    for(auto x: find(arr, 9 , 5)){
        
        cout<<x<<' ';
    }

}
