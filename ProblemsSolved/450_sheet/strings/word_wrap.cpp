#include<cp_debug.h>

/**
 * Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. 
 * Let K be the limit on the number of characters that can be put in one line (line width). 
 * Put line breaks in the given sequence such that the lines are printed neatly.
 * Assume that the length of each word is smaller than the line width. 
 * When line breaks are inserted there is a possibility that extra spaces are present in each line. 
 * The extra spaces include spaces put at the end of every line except the last one. 
 * You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)^2.
 */

int solveWordWrap(vector<int> arr, int k) { 
    int n = arr.size();
    int i, j, currlen, cost;
 
    // dp[i]: cost of line starting with word arr[i].
    int dp[n];
 
    // ans[i]: index of last word in line starting with word arr[i]. Not needed is only cost is asked
    int ans[n];
 
    dp[n - 1] = 0;
    ans[n - 1] = n - 1;
 
    for (i = n-2; i>=0; --i) {
        currlen = -1;
        dp[i] = INT_MAX;
 
        for (j = i; j < n; j++) {
 
            currlen += (arr[j] + 1);
            if (currlen > k)
                break;
 
            if (j == n - 1)
                cost = 0;
            else
                cost = (k - currlen) * (k - currlen) + dp[j + 1];
 
            if (cost < dp[i]) {
                dp[i] = cost;
                ans[i] = j;
            }
        }
    }


    i = 0;
    while (i < n) {
        cout << "{"<< i + 1 << "," << ans[i] + 1 << "} ";
        i = ans[i] + 1;
    }
 
    return  dp[0];
}

int main(){
    solveWordWrap(vector<int>{3,2,2,5}, 6);
}
