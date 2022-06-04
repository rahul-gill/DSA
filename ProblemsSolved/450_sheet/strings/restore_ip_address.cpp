#include<cp_debug.h>

string is_valid(string s, int st, int end){
    end++;
    if(st>=end ||  st+1 < end && s[st] == '0')
        return "";

    string sub = s.substr(st, end-st);
    int num = stoi(sub);
    return (num>=0 && num<=255) ? sub : "";
}

vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    int n = s.size();
    if(!n || n > 12)
        return ans;

    
    for(int i=0; i<3; ++i){
        auto first = is_valid(s,0,i);
        if(first != "") 
            for(int j = i+1; j<i+4 && j<n-1; j++){

                auto second = is_valid(s,i+1,j);
                if(second != "") 
                    for(int k = j+1; k<j+4 && k<n-1; k++){

                        auto third = is_valid(s,j+1,k), fourth = is_valid(s,k+1,n-1);
                        if(third != "" && fourth != "")
                            ans.push_back(first + "." + second + "." + third + "." + fourth);
                }
        }
    }
    return ans;
}

int main(){
    string s = "0000";
    is_valid(s,3,4);
    debug(s);
    debug(restoreIpAddresses(s));
}
