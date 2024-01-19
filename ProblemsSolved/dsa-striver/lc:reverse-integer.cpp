#include<bits/stdc++.h>
using namespace std;


int reverse(int n) {
	if(n == 0) return 0;
	bool neg = n < 0;
	string rev;
	if(neg) rev.push_back('-');
	n = abs(n);
	while(n > 0){
		rev.push_back('0' + (n % 10));
		n /= 10;
	}
	string m =  to_string(neg ? INT_MIN : INT_MAX);
		if(m.size() == rev.size()) for(int i=0; i<m.size(); ++i){
			if(m[i] < rev[i])
				return 0;
			if(m[i] > rev[i])
				break;
		}
	return stoi(rev);
}
