#ifdef ONLINE_JUDGE
    #include<bits/stdc++.h>
    using namespace std;
    #define debug(...) 42
#else
    #include "cp_debug.h"
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,m,a,d,cnt;
        cin>>n>>m>>a>>d;
        if(m < n) swap(m, n);
        long long arr[5];
        for(int i=0; i<5; ++i)
            arr[i] = a + i*d;

        auto calc = [&](long long num){ return m/num - (n%num ? n/num + 1 : n/num) + 1; };
        
        for(int i=0; i<5; ++i){
            cnt += calc(arr[i]);
            for(int j=0; j<i; ++j){
                long long ij = lcm(arr[i], arr[j]);
                cnt -= calc(ij);
                for(int k=0; k<j; ++k){
                    long long ijk = lcm(ij, arr[k]);
                    cnt += calc(ijk);
                    for(int l=0; l<k; ++l){
                        long long ijkl = lcm(ijk, arr[l]);
                        cnt -= calc(ijkl);
                        for(int z=0; z<l; ++z){
                            cnt += calc(lcm(ijkl, arr[z]));
                        }
                    }
                }
            }
        }

        cout<<(m-n+1)-cnt<<'\n';
    }
}