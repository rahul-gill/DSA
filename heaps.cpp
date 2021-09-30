#include<bits/stdc++.h>
using namespace std;


vector<int> arr;
int heap_size;

//Basic operations
void max_heapify(vector<int> &arr, int i){
	int left = (i<<1) + 1, right = left + 1, largest;
	if(left < heap_size && arr[left] > arr[i]) largest = left;
	else largest = i;
	if(right< heap_size && arr[right] > arr[largest]) largest = right;
	/
	if(largest != i){
		swap(arr[i], arr[largest]);
		max_heapify(arr, largest);
	}
}

void build_max_heap(vector<int> &arr){
	heap_size = arr.size();
	for(int i = arr.size()/2; i>=0; i--) max_heapify(arr, i);
}

void heap_sort(vector<int> &arr){
	build_max_heap(arr);

	for(int i = arr.size()-1; i>0; i--){
		swap(arr[0], arr[i]);
		heap_size--;
		max_heapify(arr, 0);
	}
}


//Priority Queue

int heap_max(vector<int> &arr){
	return arr[0];
}
int extract_max(vector<int> &arr){
	if(heap_size == 0) throw runtime_error("Trying to extract max from empty heap");
	int max = arr[0];
	arr[0] = arr[heap_size-1];
	--heap_size;
	max_heapify(arr,0);
	return max;
}
int parent(int i){ return (i+1)>>1 - 1; }
void heap_increase_key(vector<int> &arr, int i, int key){
	if(key < arr[i]) throw runtime_error("Supplied key is less than current key of item");
	arr[i] = key;
	while(i > 0 && arr[parent(i)] < arr[i]){
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

void insert(vector<int> &arr, int key){
	heap_size++;
	arr.push_back(INT_MIN);	//put at index heap_size - 1
	heap_increase_key(arr, heap_size-1, key);
}



int main(){
	vector<int> arr2(1000000);

	for(int test = 1; test < 30; test++){
		for(int i=0; i<arr2.size(); i++) arr2[i] = rand();
		arr = arr2;
		heap_sort(arr);
		sort(arr2.begin(), arr2.end());
		if(arr2 != arr){
			cout<<"failure on test: "<<test<<'\n';
			exit(1);
		}else{
			cout<<"success on test: "<<test<<'\n';
		}
	}
};
