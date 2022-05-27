#include<cp_debug.h>

int main(){
    long long t, n, q;
    cin>>t;

    while(t--){
        long long n,q;

        cin>>n;
        cin>>q;

        vector<pair<long long, long long>> rngs(n);
        for(auto &x:rngs)
            cin>>x.first>>x.second;
        
        vector<long long> qs(q);
        for(auto &x: qs)
            cin>>x;
        


        //algo
        sort(rngs.begin(), rngs.end());
        long long rngsLst = 0;
        for(long long i=1; i<rngs.size(); i++){
            if(rngs[rngsLst].second >= rngs[i].first)
                rngs[rngsLst].second = max(rngs[rngsLst].second, rngs[i].second);
            else
                rngs[++rngsLst] = rngs[i];
        }

        for(long long k: qs){
            long long ans = -1; 
            
            for(long long i=0; i<=rngsLst; ++i){
                long long sz = rngs[i].second - rngs[i].first + 1;
                if(sz >= k){
                    ans = rngs[i].first + k - 1;
                    break;
                }
                else
                    k -= sz;
            }
            cout<<ans<<'\n';
        }    
        
    }
}
