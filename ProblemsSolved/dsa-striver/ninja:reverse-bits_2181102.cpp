long reverseBits(long n) {
    long ans = 0;
    int bit = 31;
    while(n > 0){
        if(n & 1) {
            ans += 1u << bit;
        }
        --bit;
        n /= 2;
    }
    return ans;
}
