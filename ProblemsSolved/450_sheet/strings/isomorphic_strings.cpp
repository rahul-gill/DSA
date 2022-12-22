bool areIsomorphic(string str1, string str2){
    if(str1.size() != str2.size())
        return 0;

    map<char,char> mp;


    for(int i=0; i<str1.size(); ++i)
        mp[str1[i]] = str2[i];

    for(int i = 0; i<str1.size(); i++ ){
        if(mp[str1[i]] != str2[i])
            return 0;
    }

    for(int i=0; i<str2.size(); ++i)
        mp[str2[i]] = str1[i];

    for(int i = 0; i<str2.size(); i++ ){
        if(mp[str2[i]] != str1[i])
            return 0;
    }

    return 1;
}
