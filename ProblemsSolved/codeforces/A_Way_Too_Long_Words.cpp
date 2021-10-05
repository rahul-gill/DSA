#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string word;
        cin>>word;
        if(word.size() > 10) 
            word = word[0] + to_string(word.size() - 2) + word[word.size()-1];
        cout<<word<<'\n';
    }
}