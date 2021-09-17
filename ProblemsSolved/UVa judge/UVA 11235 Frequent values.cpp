#include<bits/stdc++.h>
using namespace std;

int cnt[200005], strt[200005], values[100005], segTree[400005];
int coding(int i){return i+100000;}

int getFreq(int i, int L, int R){
    int freq = cnt[i], pos1 = strt[i], pos2 = strt[i] + freq-1;
    if(pos1 >=L && pos2<=R) return freq;
    else if(pos1 <L && pos2<=R) return pos2 - L +1 ;
    else if(pos1 >=L && pos2>R) return R - pos1 + 1;
    return R - L + 1;
}
int getFreq(int i, int L, int R, int qL, int qR){
    int freq = cnt[i], pos1 = strt[i], pos2 = strt[i] + freq-1;
    if(qL > L) L =qL;
    if(qR < R) R = qR;
    if(pos1 >=L && pos2<=R) return freq;
    else if(pos1 <L && pos2<=R) return pos2 - L +1 ;
    else if(pos1 >=L && pos2>R) return R - pos1 + 1;
    return R - L + 1;
}
int build(int indxp, int L, int R){
    int indxl = indxp<<1, indxr = indxl+1, M = (L+R)/2;
    if(indxp == 0) return -1;
    if(L == R) {segTree[indxp] = 1;return 1;}

    int lef = build(indxl, L, M);
    int righ = build(indxr, M+1, R);
    int middl = 0;
    if(values[M] == values[M+1]) middl = getFreq(coding(values[M]), L, R);
    return segTree[indxp] = max(middl, max(lef, righ));

}
int querry(int indxp, int L, int R, int qL, int qR){
    if(L>qR || R<qL) return 0;
    if(L>=qL && R<=qR) return segTree[indxp];

    int indxl = indxp<<1, indxr = indxl+1, M = (L+R)/2;
    int lef = querry(indxl, L, M, qL, qR);
    int righ = querry(indxr, M+1, R, qL, qR);
    if(lef == 0) return righ;
    if(righ == 0) return lef;

    int middl = 0;
    if(values[M] == values[M+1]) middl = getFreq(coding(values[M]), L, R,qL,qR);
    //cout<<lef<<' '<<righ<<' '<<middl<<endl;
    //cout<<"("<<L<<','<<R<<")>"<<max(middl, max(lef, righ))<<endl;
    return max(middl, max(lef, righ));
}

int main(){
    int n,q;
    while(cin>>n){
        if(n == 0) break;
        cin>>q;
        int curr,prev;
        int i=0;
        cin>>prev;values[i] = prev;
        strt[coding(prev)] = i++;cnt[coding(prev)] = 1;
        for(int times=0;times<n-1;times++){
            cin>>curr;
            values[i] = curr;
            if(prev != curr) {cnt[coding(curr)] = 1;strt[coding(curr)] = i;}
            else cnt[coding(curr)]++;
            prev = curr;
            i++;
        }
        build(1,0,n-1);
        while(q--){
            int i,j;
            cin>>i>>j;
            cout<<querry(1,0,n-1,i-1,j-1)<<'\n';
        }

    }
}