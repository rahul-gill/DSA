#include<bits/stdc++.h>
using namespace std;

/**
 * Let missing no be x and repeating number be y
 * then sum Of N Numbers - sum Of Array Elements = x - y
 * and sum Of Squares of N Numbers - sum Of Square Of Array Elements = x*x - y*y = (x+y)*(x-y)
 * so we get x - y = a and (x+y)*(x-y) = b where a and b are known
 * => x-y = a and (x+y) = b/a
 * => x = (a + b/a)/2, y = (b/a - a) /2
 * => x = (a*a + b)/2a, y = (b - a*a)/2a
 */

int *findTwoElement(int *arr, int n) {
    int *ans=new int[2];

    long long a = 0, b = 0;

    for(int i=0; i<n; i++){
        a += arr[i] - (i+1);
        b += 1l * arr[i] * arr[i] - 1l * (i+1)*(i+1);
    }

    ans[1] = (a*a + b)/(2*a);
    ans[0] = (b - a*a)/(2*a);
    return ans;
}

int main(){
    int arr[] = {2,2};

    auto x = findTwoElement(arr, 2);
    cout<<x[0]<<' '<<x[1];
}
