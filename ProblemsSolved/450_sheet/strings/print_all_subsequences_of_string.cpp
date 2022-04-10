#include<cp_debug.h>

vector<string> subsequences(string str){
	vector<string> ret;

    int n = (int)(pow(2, str.size())); 

    for(int i=1; i<n; i++){
        string s;
        for(int j=0; j<str.size(); j++)
            if(i & 1<<j)
                s += str[j];
        ret.push_back(s);
    }

	return ret;
}
