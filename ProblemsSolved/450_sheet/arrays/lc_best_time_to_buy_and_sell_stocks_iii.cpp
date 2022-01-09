#include<bits/stdc++.h>
using namespace std;


int maxProfitByBuyingSellingInfiniteTimes(int prices[], int n){
    int mi = prices[0], ma = prices[n-1];
    int profit[n];
    fill(profit, profit+n, 0);

    for(int i = n-2; i<=0; i--){
        ma = max(ma, prices[i]);
        profit[i] = max(profit[i+1], ma - prices[i]);
    }    
    for(int i = 1; i<n; i++){
        mi = min(mi, prices[i]);
        profit[i] = max(profit[i-1], profit[i] + prices[i] - mi);
    }    
    return profit[n-1];
}

int maxtwobuysell(int arr[],int size) {
    int first_buy = INT_MIN;
    int first_sell = 0;
    int second_buy = INT_MIN;
    int second_sell = 0;
    
    for(int i=0;i<size;i++) {
        first_buy = max(first_buy,-arr[i]);
        first_sell = max(first_sell,first_buy+arr[i]);
        second_buy = max(second_buy,first_sell-arr[i]);
        second_sell = max(second_sell,second_buy+arr[i]);
    }
     return second_sell;
}

int main(){
    int price[] = {10, 22, 5, 75, 65, 80};
    int n = 6;
    maxProfitByBuyingSellingInfiniteTimes(price, n);
}