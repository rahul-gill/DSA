#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> bird_count(n);
    for(auto &x: bird_count) cin>>x;
    int m;
    cin>>m;
    vector<pair<int,int>> shot_position(m);//wire, bird position
    for(auto &x: shot_position) cin>>(x.first)>>(x.second);;

    for(auto x: shot_position){
        int shot_wire = x.first;
        int shot_bird = x.second;
        if(shot_wire > 1) 
            bird_count[shot_wire-2] += shot_bird -1;
        if(shot_wire < n )
            bird_count[shot_wire] += bird_count[shot_wire-1] - shot_bird;
        bird_count[shot_wire-1] = 0;
    }
    for(auto x: bird_count) cout<<x<<'\n';
}