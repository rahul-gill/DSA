#include<bits/stdc++.h>
using namespace std;

string nextFromPrev(string s){
    int z = 1;
    string res = "";

    for(int i=1; i<=s.size(); i++){
        if(i<s.size() &&s[i] == s[i-1])
            z++;
        else{
            res += to_string(z) + s[i-1];
            z =1;
        }
    }
    return res;
}

string countAndSay(int n) {
    string res = "1";
    if(n == 1)
        return res;

    for(int i=2; i<=n; i++ )
        res = nextFromPrev(res);

    return res;
}
