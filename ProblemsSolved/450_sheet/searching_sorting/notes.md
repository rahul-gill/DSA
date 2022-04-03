cycle sort, ternary search

# Lower bound and upper bound

- [ lower_bound, upper_bound )

- s.lower_bound(t) will return iterator to the first element v in set such that v >= t
- s.upper_bound(t) will return iterator to the first element v in set such that v > t.

```cpp
set<int> s = {0,1,2,10,11,12,15};
int A=1, B=11;

//iterate all values equal to A
for(auto iter = s.lower_bound(A); iter != s.upper_bound(A); iter++)
    cout<<*iter<<"\t";

//iterate all values in [A, B)
for(auto iter = s.lower_bound(A); iter != s.lower_bound(B); iter++)
    cout<<*iter<<"\t";

//iterate all values in [A, B]
for(auto iter = s.lower_bound(A); iter != s.upper_bound(B); iter++)
    cout<<*iter<<"\t";

//iterate all values in (A, B)
for(auto iter = s.upper_bound(A); iter != s.lower_bound(B); iter++)
    cout<<*iter<<"\t";

//Iterate all values in (A, B]
for(auto iter = s.upper_bound(A); iter != s.upper_bound(B); iter++)
    cout<<*iter<<"\t";

//in case A is not present in array, both lower_bound and upper_bound return iterator to first element bigger than A
```


# Ternary search
- useful when the array is not monotonic, for example when the values are increasing first and then decreasing
- divide the sorted array in 3 parts to search the specific element
- in beginning l and r are 0 and n-1. Then `mid1 = l + (r-l) / 3, mid2 = r - (r-l) / 3`
- steps to find `target`
  - compare `target` with the element at `mid1`. If found equal, we return mid1.
  - If not, then we compare `target` with the element at `mid2`. If found equal, we return mid2.
  - If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
  - If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
  - If not, then we recur to the second (middle) part.
- time complexity: $\mathcal{O}(\log_3 n)$
- implementation

```cpp
int ternarySearch(int l, int r, int key, int ar[]){
    while (r >= l) {
 
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
 
        if (ar[mid1] == key)
            return mid1;
        
        if (ar[mid2] == key)
            return mid2;
        
        if (key < ar[mid1])
            r = mid1 - 1;
        else if (key > ar[mid2])
            l = mid2 + 1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}
```

# Boyer–Moore majority vote algorithm
- keep track of a counter and maj_index which are initialized to 1 and 0
- traverse through array
    - if next element if equal to element at maj_index, increment the counter
    - else decrement the counter
    - if counter become zero, update maj_index to current index and counter to 1
- at last check if the element at maj_index occurs more than ⌊n / 2⌋ times and return it if it does
- else no majority element exist
