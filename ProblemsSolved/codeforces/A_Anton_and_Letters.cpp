#include<bits/stdc++.h>
using namespace std;

int main(){
    char x;
    bool cnt[26];
    for(int i=0; i<26; i++) cnt[i] = 0;

    while(cin>>x){
        int character = x - 'a';
        if(character >= 0 && character < 26) cnt[character] = 1;
    }
    int sum_val =  0;
    for(int i=0; i<26; i++)  sum_val += cnt[i];
    cout<<sum_val<<'\n';
}