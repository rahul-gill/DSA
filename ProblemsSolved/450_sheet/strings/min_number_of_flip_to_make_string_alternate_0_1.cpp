int minFlips(string s){
    int ans = 0, len = s.size();
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0 && s[i] == '1')
            ans++;
        if (i % 2 == 1 && s[i] == '0')
            ans++;
    }
    return min(ans, len - ans);
}
