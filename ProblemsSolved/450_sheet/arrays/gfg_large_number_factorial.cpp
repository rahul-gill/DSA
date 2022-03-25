#include<bits/stdc++.h>
using namespace std;

/**
 * Since number is large it is represented as a vector of its digits
 * So we multiply numbers the elementary school way
 */

vector<int> factorial(int N){
    vector<int> res = {1};
    for(int i=2; i<=N; i++){
        int carry = 0;
        for(int j=0; j<res.size(); j++){
            int digitProduct =  res[j] * i + carry;
            res[j] = digitProduct % 10;
            carry = digitProduct / 10;
        }
        while (carry != 0){
            res.push_back(carry % 10);
            carry /= 10;
        }   
    }
    reverse(res.begin(), res.end());
    return res;
}

/**
 * Multiply numbers represented as str1 and str2, and prints result.
 * str1 = str1[0] + str1[1] * 10^1 + str1[2] * 10^2 + ... + str1[str1.size() - 1] * 10^1(str1.size() - 1)
 * str2 = str2[0] + str2[1] * 10^1 + str2[2] * 10^2 + ... + str2[str2.size() - 1] * 10^1(str2.size() - 1)
 * str1 * str2 =
 *              E(i = 0 to i = str1.size() - 1) E(j = 0 to j = str2.size() - 1)
 *                      str1[i] * str2[j] * 10 ^ (i + j)
 * To keep single digits at every place, we propagate the carry forward
 */
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0, i_n2 = 0; // location of current digit of both numbers
    int n1, n2; // current digit of both numbers

    // traverse the digits of first number from right to left
    for (int i=len1-1; i>=0; i--){
        n1 = num1[i] - '0';

        i_n2 = 0;
        int carry = 0;

        for (int j=len2-1; j>=0; j--) {
            // Take current digit of second number
            n2 = num2[j] - '0';

            // Multiply with current digit of first number and add result to previously stored result at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        /**
         * store carry in next cell
         */
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;

    // If all were '0's - means either both or one of num1 or num2 were '0'
    if (i == -1)
        return "0";

    // generate the result string
    string s = "";
    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}





int main(){
    auto x = factorial(10);
    for(auto y:x) cout<<y;
    cout<<endl;
}