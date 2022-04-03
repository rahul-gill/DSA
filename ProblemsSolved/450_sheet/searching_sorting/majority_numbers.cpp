#include<bits/stdc++.h>
using namespace std;

/**
 * Given an array nums of size n, return the majority element
 * The majority element is the element that appears more than ⌊n / 2⌋ times. There might be no majority element.
 */
 
/**
 * Idea: Boyer–Moore majority vote algorithm or  Moore's Voting Algorithm
 */

int majorityElement(int arr[], int size){
    int cnt = 1, maj_index = 0;

    for(int i=1; i<size; i++){
        if(arr[i] == arr[maj_index])
            cnt++;
        else
            cnt--;
        
        if(cnt == 0){
            maj_index = i;
            cnt = 1;
        }
    }

    cnt = 0;
    for(int i=0; i<size; i++){
        if(arr[i] == arr[maj_index]) cnt++;
        if(cnt > size/2) return arr[maj_index];
    }

    return -1;
}

