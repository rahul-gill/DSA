#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,k,d;
    cin>>n>>t>>k>>d;

    // int timeDone = 0, itemSimple = 0, itemComplex = 0;
    // while(1){
    //     //every t time
    //     timeDone += t;
    //     if(timeDone > d + t){
    //         itemComplex += k;
    //         if(itemComplex >= n && itemSimple < n){
    //             cout<<"YES\n";
    //             break;
    //     }
    //     }
    //     itemComplex += k; 
        
    //     itemSimple += k;
    //     if(itemSimple >= n){
    //         cout<<"NO\n";
    //         break;
    //     }

    // }

    //Better Solution
    int currt = 0;
 
    while(currt <= d){
        n -= k;
        currt += t;
    }
    (n > 0) ? printf("YES\n") : printf("NO\n");
    
 
    return 0;

}