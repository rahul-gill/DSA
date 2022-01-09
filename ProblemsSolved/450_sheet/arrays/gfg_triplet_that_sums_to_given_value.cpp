#include<bits/stdc++.h>
using namespace std;


bool find3Numbers(int A[], int n, int X)
{
    sort(A, A+n);
    for (int i = 0; i < n-3; i++){
        int j = i+1;
        int k =  n - 1;
        while (j < k){
            int sum = A[i] + A[j] + A[k];
            if (sum == X)
                return true;
            else if (sum > X)
               k -= 1;
            else if (sum < X)
               j += 1;
       }
   }
   return false;

}


