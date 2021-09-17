#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<long long> towers;
vector<vector<int>> commns;
vector<long long> commns_values;
inline int digsum(int dig){
    int summ = 0;
    while(dig > 0){
        summ += dig%2;
        dig /= 2;
    }
    return summ;
}
//the function to use when customer numbers are equal and output based on tower number
inline bool supVAL(int in, int in2){
    while(in > 0 && in2>0){
        if(in%2 > in2%2) return 1;
        else if(in%2 < in2%2) return 0;
        else{ in/=2; in2/=2; }
    }
    return (in<in2);
}
int main(){
    int CN = 1;
    while(cin>>n>>m && n>0 && m>0){
        //reading input
        towers = vector<long long>(n,0);
        for(auto &x:towers) {cin>>x;}
        int nCom;
        cin>>nCom;
        commns.clear();
        commns_values.clear();
        while(nCom--){
            long long nnn;cin>>nnn;
            commns.push_back(vector<int>(nnn));
            for(auto &x: commns[commns.size()-1]) {cin>>x;x--;}
            cin>>nnn;
            commns_values.push_back(nnn);
        }
        
//i will traverse over combinations of choosing m out of n towers, lim in (11....00) where '1' m times and total n digits
//initially i is (1111...) m times(choosing the first m towers of total n towers)
        int i = 0b1, lim = 0;
        for(int kkk = n-1;kkk>=n-m;kkk--) lim |= (1<<kkk);
        for(int k=1;k<m;k++) i |= (1<<k);
        long long totalMax = 0, locrecom;//max customer and recommeded tower locations
        while(i <= lim){
            if(digsum(i) != m) {i++;continue;}//if number of towers in this combinations is not m
            vector<long long> minuses(n,0);
            long long total = 0;
            vector<bool> taken(commns.size(),0);
            for(int k=0;k<n;k++){
                if((1<<k) & i){
                    total += towers[k] + minuses[k];
                    int ValIndx=0;
                    for(auto x:commns){
                        auto pos = find(x.begin(), x.end(), k);
                        if(pos != x.end() && !taken[ValIndx]){
                            auto posIndx = pos - x.begin();
                            for(auto kk=0;kk<x.size();kk++) 
                                if(kk != posIndx && !taken[ValIndx])
                                    minuses[x[kk]]-= commns_values[ValIndx];
                            taken[ValIndx] = 1;
                        }
                        ValIndx++;
                    }
                }
            }
            if(total >= totalMax){
                if(total == totalMax && supVAL(locrecom,i)){;}
                else {
                    totalMax = total;locrecom = i;
                }
            }
            i += 1;
        }
        //Ouput the result
        printf("Case Number  %d\n", CN++);
        printf("Number of Customers: %lld\n",totalMax);
        printf("Locations recommended: ");
        for(int k=0;k<n;k++){
            if((1<<k) & locrecom) {
                printf("%d",k+1);
                if(!((1<<k) & (1<<int(log2(locrecom))))) printf(" ");//critical; comparing 1<<k and MSB of locrecom
            }
        }
        cout<<"\n\n";
    }

}