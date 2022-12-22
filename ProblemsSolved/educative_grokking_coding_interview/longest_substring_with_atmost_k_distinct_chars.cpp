#include<cp_debug.h>

/**
 * - the count variable is important becuase 
 *    in inner while loop, if we decrease size then duplicates won't be processed(for example "aaa" case, removed a but 2 a's are still in the st-end range)
 *    we can use size but using count variable would be less code
 * - we can't use the values of the map as last index where the char occured(for example for string "aaabcc" the map will be {(a,2), (b,3), (c,5)}
 *   because in the inner loop if we just do st = chars[s[st]] + 1, then we'll be removing other chars(e.g. in case "abb'a'ccd") without accounting for them 
 */

/**
 * Summarized idea:
 * - keep a map of count of chars in current window, the starting and ending ending of the window
 * - keep expanding window from the right(by increasing end index), during that:
 *   - increase the count of added character in the map
 *   - if map's size gets bigger than k i.e. distinct characters in window are more than k, then until the size becomes less than or equal to k
 *     - shrink the window by increasing start index and decrease the count of the char which was at the start index
 *     - if count of that char gets zero, remove it from the map
 *   - update the maxSize if size of current window is the biggest ever
 */

int getLengthofLongestSubstring(int k, string s){
    unordered_map<char, int> chars;
    int st = 0, end = 0, longestSub = 0, cnt = 0;


    for(;end <s.size(); end++){
        if(chars[s[end]] == 0)
            cnt++;
        chars[s[end]]++;

        while(cnt > k){
            if(chars[s[st]] == 1)
                cnt--;
            chars[s[st]]--;
            st++;
        }
        longestSub = max(longestSub, end-st+1);
    }
    return longestSub;
}

