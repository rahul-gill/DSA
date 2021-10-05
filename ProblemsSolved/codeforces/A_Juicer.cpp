#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,b,d;
    cin>>n>>b>>d;
    vector<int> orange_sizes;
    for(int i=0; i<n; ++i){
        int inp;
        cin>>inp;
        if(inp <= b) orange_sizes.push_back(inp);
    }
    int res = 0, currSize = 0;
    for(int i=0; i<orange_sizes.size(); ++i){
        currSize += orange_sizes[i];

        if(currSize > d){
            currSize = 0;
            ++res;
        }
    }

    cout<<res<<'\n';
}