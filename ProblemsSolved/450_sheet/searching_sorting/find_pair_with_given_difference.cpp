#include<bits/stdc++.h>
using namespace std;


bool findPair(int arr[], int size, int n){
    sort(arr, arr + size);

    for(int i = 0; i<size; i++){
        auto it = lower_bound(arr, arr+size, arr[i] - n);
        if(it != arr + size && it != arr + i && *it == arr[i] - n)
            return true;
    }
    return false;
}

