#include <bits/stdc++.h>
using namespace std;


int main() {
	//input
	int n,q;
	cin>>n;

	vector<int> soldiers(n);
	for(auto &x: soldiers) cin>>x;

    cin>>q;

    vector<int> powers(q);
    for(auto &x: powers) cin>>x;

    //algo
    sort(soldiers.begin(), soldiers.end());
    
    for(auto roundPower: powers){
        int cnt = upper_bound(soldiers.begin(), soldiers.end(), roundPower) - soldiers.begin();
        int powerTotal = 0;

        for(int i=0; i<cnt; i++)
            powerTotal += soldiers[i];
        
        cout<<cnt<<' '<<powerTotal<<'\n';
    }

}

