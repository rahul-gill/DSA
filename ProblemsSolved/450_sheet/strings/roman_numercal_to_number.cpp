int romanToDecimal(string &str) {
    static unordered_map<char, int> numeral{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    
    int n=str.size(), ans=0;

    for (int i = 0; i < n; i++){
        if (m[str[i]]>=m[str[i+1]])           
            ans += m[str[i]];
        else
            ans -= m[str[i]];
    }
    return ans;
}
