#include<bits/stdc++.h>
using namespace std;

/**
 * Examples:
    Input: arr[] = {121, 131, 20}
    Output: Array is not a PalinArray
    For the given array, element 20 is not a palindrome. Thus the array is not a PalinArray.
    Input: arr[] = {111, 121, 222, 333, 444}
    Output: Array is a PalinArray
    For the given array, all the elements of the array are palindromes. Thus the array is a PalinArray.
 */

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
