bool palindrome(int n)
{
    if(n < 0) return false;
    string s = to_string(n);
    for(int i=0; i< s.size(); ++i)
        if(s[i] != s[s.size()-i-1]) return false;
    return true;
}
