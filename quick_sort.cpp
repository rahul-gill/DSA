#include<bits/stdc++.h>
using namespace std;



int partition(vector<int> &arr, int l,int r){
    int ramdom_index = l + (rand() % (r-l));
    swap(arr[ramdom_index], arr[r-1]);
    int pivot = arr[r-1];
    int i = l;
    for(int j = l; j<r-1;j++){
        if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[r-1], arr[i]);
    return i;
}

void quick_sort(vector<int> &arr, int l = 0,int r = INT_MIN){
    if(r == INT_MIN) r = arr.size();
    if(l >= r) return;
    int m = partition(arr,l,r);
    quick_sort(arr, l, m );
    quick_sort(arr, m + 1, r);
}



int main(){
	vector<int> arr,arr2(1000000);

	for(int test = 1; test < 30; test++){
		for(int i=0; i<arr2.size(); i++) arr2[i] = rand();
		arr = arr2;
		quick_sort(arr);
		sort(arr2.begin(), arr2.end());
		if(arr2 != arr){
			cout<<"failure on test: "<<test<<'\n';
			exit(1);
		}else{
			cout<<"success on test: "<<test<<'\n';
		}
	}
};