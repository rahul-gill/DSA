#include<cp_debug.h>

string reorganizeString(string s){
    vector<int>V(26);
    int mostFreq = 0, i = 0;
    
    for(char c: s)
        if(++V[c-'a'] > [mostFreq])
            mostFreq = c-'a';
    
    if(2 * V[mostFreq] - 1 > s.size())
        return "";
    
    while(V[mostFreq]){
        s[i] = ('a' + mostFreq);
        i += 2;
        V[mostFreq]--;
    }   

    for(int j=0;j<26;j++){
        while(V[j]--){
            if(i >= s.size())
                i = 1;
            s[i] = ('a' + j);
            i += 2;
        }
    }
    
    return s;
}
