#include<cp_debug.h>

vector<string>find_permutation(string s){
    sort(s.begin(), s.end());
    vector<string> ret;

    ret.push_back(s);

    while(next_permutation(s.begin(), s.end()))
        ret.push_back(s);
    }
    
    return ret;
}

