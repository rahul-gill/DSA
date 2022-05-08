#include<cp_debug.h>


/*
 * first we remove the balanced expressions from the string
 * then we'll left with string of kind }} {{{ (some closing bracket the some opening brackets)
 * sum of these left will be even as odd size case has been taken care of already
 * if number of opening and closing brackets are even then reversal of half of them both will result in balanced string
 * else if they're even half of both of them + one extra reversal from each will result in balanced string
 * so ans = ceil(no of closing brackets)/ 2 + ceil(no of opening brackets)/ 2;
 */
int countRev (string s){
    if(s.size() % 2 == 1)
        return -1;

    stack<char> stk;
    for(char x: s){
        if(x == '{') stk.push(x);
        else if(x == '}' && !stk.empty() && stk.top() == '{') stk.pop();
        else stk.push(x);
    }
    
    int op, clos;
    while(!stk.empty()){
        if(stk.top() == '{') ++op;
        else ++clos;
        stk.pop();
    }

    op = op/2 + (op & 1 != 0);
    clos = clos/2 + (clos & 1 != 0);
    return op+clos;
}
