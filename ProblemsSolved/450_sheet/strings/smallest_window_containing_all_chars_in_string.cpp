int findSubString(string str){
    string tmp, wd;
    int vis[256];
    memset(vis, 0, sizeof(vis));
    for(auto &x: str){
        vis[x]++;
        tmp += x;
        if(vis[x] == 1)
            wd = tmp;
        else while(1){
            if(vis[tmp[0]] > 1)
                vis[tmp[0]]--, tmp.erase(tmp.begin());
            else
                break;            
        }
        if(tmp.size() < wd.size())
            wd = tmp;
    }
    return wd.size();
}

int findSubString(string str){
    int n = str.length();
    unordered_map<char,int> u;
    for(auto &x: str)
        u[x] = 0;

    int i=0,j=0,ans=INT_MAX,count=0;
    string res;
    while(j<n){
        u[str[j]] += 1;
        if(u[str[j]] == 1) 
            count++;
       
        if(count == u.size()){
            while(i<n && u[str[i]]>1){
                u[str[i]]--;
                i++;
            }
            if(ans > (j-i+1)){
                ans = j-i+1;
                res = str.substr(i,j-i+1);
            }
        }
        j++;
    }
    return ans;
}
