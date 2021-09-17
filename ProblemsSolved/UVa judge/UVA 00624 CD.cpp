#include<bits/stdc++.h>
using namespace std;

int n,tracks,bestsum;
vector<int> nums; int best;

int main(){
    while(cin>>n){
        cin>>tracks;
        nums = vector<int>(tracks);
        for(auto &x:nums) cin>>x;
        bestsum=0;
    
        for(int i=1;i<pow(2,tracks);i++){
            if(bestsum == n) break;
            int cursum = 0, indx = 0;
            for(;indx < tracks; indx++)
                if((1<<indx) & i)
                    cursum += nums[indx];
            if(cursum<=n && cursum > bestsum){
                bestsum = cursum;
                best = i;
            }
        }

        for(int i=0; i<tracks; i++){
            if((1<<i) & best) cout<<nums[i]<<' ';
        }
        printf("sum:%d\n",bestsum);
    }
}