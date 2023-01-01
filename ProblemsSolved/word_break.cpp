#include "bits/stdc++.h"
using namespace std;

/**
 * Solutions 1 :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 */

struct trie {
    bool isWord = false;
    unordered_map<char, trie *> children;

    void add_word(const string &word) {
        auto curr = this;
        for (const auto &item: word) {
            if (curr->children[item] == nullptr)
                curr->children[item] = new trie;
            curr = curr->children[item];
        }
        curr->isWord = true;
    }
};


bool wordBreak1(const string &s, const vector<string> &wordDict) {
    trie dict;
    for (const auto &item: wordDict)
        dict.add_word(item);

    vector<bool> dp(s.size() + 1);
    dp.back() = true;

    for (int i = (int) s.size() - 1; i >= 0; --i) {
        auto curr = dict;
        for (int j = i + 1; j <= s.size(); ++j) {
            auto c = s[j - 1];
            if (curr.children.find(c) == curr.children.end()) break;
            curr = *curr.children[c];
            if (curr.isWord && dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.front();
}


/**
 * Solutions 2 :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 */

bool wordBreak2(const string &s, const vector<string> &wordDict) {
    unordered_set<string> wordDictSet;
    for (const auto &item: wordDict)
        wordDictSet.insert(item);

    vector<bool> dp(s.size() + 1);
    dp.back() = true;

    for (int i = (int) s.size() - 1; i >= 0; --i) {
        for (int j = i + 1; j <= s.size(); ++j) {
            if(dp[j] && wordDictSet.find(s.substr(i,j-i)) != wordDictSet.end()){
                dp[i] = true;
                break;
            }
        }
    }
    return dp.front();
}


/**
 * Solutions 3 :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 */


bool wordBreak3(const string &s, const vector<string> &wordDict) {
    unordered_set<string> wordDictSet;
    for (const auto &item: wordDict)
        wordDictSet.insert(item);

    vector<bool> dp(s.size() + 1);
    dp.back() = true;

    for (int i = (int) s.size() - 1; i >= 0; --i) {
        for (const auto &word : wordDict){
            if(word.size() <= s.size() - i){
                int same = true;
                for(int j=0; j<word.size(); ++j)
                    if(word[j] != s[j+i]){
                        same = false;
                        break;
                    }
                if(same && dp[i+word.size()]){
                    dp[i] = true;
                }
            }
        }
    }
    return dp.front();
}
