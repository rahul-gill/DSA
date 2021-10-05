#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, r;
    cin>>k>>r;
    int ans = 10;
    for(int i=1; i<10; i++)
        if((k*i)%10 == r || (k*i)%10 == 0){
            ans = i;break;
        }
    cout<<ans<<'\n';
    
}