#include<bits/stdc++.h>
using namespace std;

/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

class Solution {
public:
    int maxSubarray(vector<int> arr){
        int maxSoFar = 0, maxi = INT_MIN;
        for(int i=0; i<arr.size(); ++i){
            maxSoFar += arr[i];
            if(maxSoFar < 0) maxSoFar = 0;
            maxi = max(maxi, maxSoFar);
        }
        return maxi;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<int> diffArray(prices.size()-1);
        for(int i=1; i<prices.size(); ++i)
            diffArray[i-1] = prices[i] - prices[i-1];
        return maxSubarray(diffArray);
    }
};