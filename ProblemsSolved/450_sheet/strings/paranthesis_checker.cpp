#include<cp_debug.h>

/**
 * Given an expression string x
 * Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
 * For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.
 */

bool ispar(string x){
    stack<char> stk;

    for(auto i: x){
        if(i == '{' || i == '(' || i == '[')
            stk.push(i);
        else if(!stk.empty() && 
                (i == '}' && stk.top() == '{' || 
                i == ']' && stk.top() == '[' || 
                i == ')' && stk.top() == '('))
            stk.pop();
        else
            return false;
    }
    return stk.empty();
}


int main(){
    debug(ispar("{([])}"));
    debug(ispar("[()]{}{[()()]()}"));
    debug(ispar("[(])"));
}
