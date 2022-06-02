string longestCommonPrefix(vector<string>& strs) {
    string s;
    int i = 0;  
    while(i != -1){
        char x = 0; 
        for(auto str: strs){
            if(str.size() <= i || (x && x != str[i])){
                i = -1;
                break;
            }
            if(!x)
                x = str[i];
        }
        if(i != -1){
            s += strs[0][i];
            i++;
        }
    }
    return s;
}
