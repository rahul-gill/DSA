#include<bits/stdc++.h>
using namespace std;

template<typename T> class FenwickTree {
private:
    vector<T> ftree;
    inline int lsbit(int a){return (a & -a);}
public:
	void build(const vector<T> &arr) {
		int arr_size = arr.size();                   
		ftree.assign(arr_size+1, 0);
		copy(arr.begin(), arr.end(), ftree.begin()+1);
		for (int i = 1; i <= arr_size; ++i) {                     
			if (i+lsbit(i) <= arr_size)                    
				ftree[i+lsbit(i)] += ftree[i];                
		}
	}
	FenwickTree(int m) { ftree.assign(m+1, 0); }
	FenwickTree(const vector<T> &f) { build(f); }

	//RSQ(1, j)
	T rsq(int j) {   
		T sum = 0;
		for (; j; j -= lsbit(j))
			sum += ftree[j];
		return sum;
	}
	T rsq(int i, int j) { 
		return rsq(j) - rsq(i-1); 
	}

  	// updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
	void update(int i, T v) {
		for (; i < ftree.size(); i += lsbit(i))
			ftree[i] += v;
	}
};
