#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
        int n;
        cin>>n;
        vector<int> arr(n);

        int maxi = INT_MIN, already_good = 1, prev = INT_MIN;
        int i =0, maxiIndex = 0;
        for(auto &x: arr){
            cin>>x;
            if(x >= maxi){
                maxi = x;
                maxiIndex = i;
            }
            if(prev == INT_MIN) prev = x;
            else if(prev != x) already_good = 0;
            i++;
        }
        if(already_good == 1) cout<<"0\n";
        else if(maxi == arr[n-1]) cout<<"1\n";
        else{
            int elementsNotEqualToMaxi = 0, biggestSuch = 0;
            for(int i=0; i<n; i++){
                if(arr[i] != maxi and i > maxiIndex){
                    elementsNotEqualToMaxi++;
                    biggestSuch = i;
                }
            }
            if(elementsNotEqualToMaxi == 0){
                cout<<"1\n";
            }else{
                cout<<"2\n";
            }
        }
	}
}
