//Since only adjacent swaps are allowed so when we have traversed some closing brackets and we get an openinig one and the diff is positive, then we move the the opening bracket to left by `diff` positions 
int minimumNumberOfSwaps(string S){
    int diff = 0, swaps = 0;
    for(auto& c: S){
        if(c == ']')
            diff++;
        else{
            if(diff)
                swaps += diff;
            diff--;
        }
    }
    return swaps;
}
