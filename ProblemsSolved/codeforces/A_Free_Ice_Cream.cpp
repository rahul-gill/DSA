#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,x;
    cin>>n>>x;
    long long distressed = 0;
    for(int i=0; i<n; i++){
        char sign;cin>>sign;
        long long val;cin>>val;
        if(sign == '+') x += val;
        else{
            if(x >= val) x -= val;
            else ++distressed;
        }
    }
    cout<<x<<' '<<distressed<<'\n';
}