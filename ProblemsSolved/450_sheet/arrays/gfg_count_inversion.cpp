#include<bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long l, long long m, long long r){
    long long n1 = m-l+1, n2 = r-m;
    long long ans = 0;

    long long larr[n1], rarr[n2];
    for(long long i=0; i<n1; i++) larr[i] = arr[i+l];
    for(long long i=0; i<n2; i++) rarr[i] = arr[i+m+1];

    long long i=0,j=0,k=l;
    while (i < n1 and j < n2){
        if(larr[i] <= rarr[j])
            arr[k] = larr[i++];
        else{
            arr[k] = rarr[j++];
            ans+= n1-i;
        }
        k++;
    }
    while (i!= n1) arr[k++] = larr[i++];
    while (j!= n2) arr[k++] = rarr[j++];
    return ans;
    
}
long long modifiedMergeSort(long long arr[], long long l, long long r){
    long long mid = (l+r)/2;
    long long ret = 0;
    if(l<r){
        ret += modifiedMergeSort(arr, l, mid);
        ret += modifiedMergeSort(arr, mid+1, r);
        ret += merge(arr,l,mid,r);
    }
    return ret;
}


long long int inversionCount(long long arr[], long long N){
    return modifiedMergeSort(arr, 0, N-1);
}

int main(){
    long long N =6,arr[] = {5,6,6,1,2,3};
    cout<<inversionCount(arr, N);
}