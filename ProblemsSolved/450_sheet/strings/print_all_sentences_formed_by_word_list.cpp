#include<cp_debug.h>

vector<vector<string>> sentences(vector<vector<string>>& lst){
    vector<vector<string>> res;
    
    for(auto x: lst[0])
        res.push_back(vector<string>{x});

    for(int i = 1; i < lst.size(); i++){
        int prevSize = res.size();
        auto to_add = lst[i];
        auto prevRes = res;
        res.clear();
        for(auto x: prevRes)
            for(int j=0; j<to_add.size(); ++j)
                res.push_back(x);

        int j = 0;
        for(int k = 0; k < prevSize; k++){
            for(auto item: to_add){
                res[j++].push_back(item);  
            }
        }
    }
    return res;
}
