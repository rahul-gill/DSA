#include<bits/stdc++.h>
using namespace std;

vector<int> factorial(int N){
    vector<int> res = {1};
    for(int i=2; i<=N; i++){
        int carry = 0;
        for(int j=0; j<res.size(); j++){
            int digitProduct =  res[j] * i + carry;
            res[j] = digitProduct % 10;
            carry = digitProduct / 10;
        }
        while (carry != 0){
            res.push_back(carry % 10);
            carry /= 10;
        }   
    }
    reverse(res.begin(), res.end());
    return res;
}
  

int main(){
    auto x = factorial(10);
    for(auto y:x) cout<<y;
    cout<<endl;
}