#include<bits/stdc++.h>
using namespace std;

int areaPops[25];
int offices[5], office_index=0,office_solution[5];
int totalMinDist;
int ham_dist(int x,int y){
    int dx = abs(x/5 - y/5);
    int dy = abs(x%5 - y%5);
    return dx + dy;
}
void solve(int area_start){
    if(office_index < 5){
        for(int area = area_start;area<25; area++){
            offices[office_index++] = area;
            solve(area+1);
            office_index--;
        }
    }else{
        int totalDist = 0;
        for(int i=0;i<25;i++){
            if(areaPops[i] > 0){
                int minDist = INT_MAX;
                for(int office = 0;office<5;office++){
                    minDist = min(minDist, ham_dist(i,offices[office]));
                }
                totalDist += areaPops[i]*minDist;
            }
        }
        if(totalDist < totalMinDist){
            totalMinDist = totalDist;
            for(int k=0;k<5;k++) office_solution[k] = offices[k];
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int nonNulls;
        cin>>nonNulls;
        for(int i=0;i<25;i++) areaPops[i] = 0;
        for(int i=0;i<nonNulls;i++){
            int x,y,val;
            cin>>x>>y>>val;
            areaPops[5*x+y] = val;
            totalMinDist = INT_MAX;
        }
        office_index = 0; totalMinDist = INT_MAX;
        solve(0);
        for(int i=0;i<5;i++) cout<<office_solution[i]<<(i==4 ? '\n':' ');
    }        
}