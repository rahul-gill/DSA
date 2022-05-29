vector<int> inorder(const vector<int>& A, int index = 0){
    if(index >= A.size())
        return vector<int>();

    auto l = inorder(A, 2*index + 1);
    l.push_back(A[index]);
    auto r = inorder(A, 2*index + 2);
    l.insert(l.end(), r.begin(), r.end());

    return l;
}
int minSwaps(vector<int>&A, int n){
    vector<int> arr = inorder(A);
    vector<pair<int,int>> node_to_idx;
    for(int i=0; i<arr.size(); ++i)
        node_to_idx.push_back({arr[i], i});
    sort(node_to_idx.begin(), node_to_idx.end());

    int ans = 0;
    for(int i=0; i<node_to_idx.size();){
        if(i != node_to_idx[i].second){
            ++ans;
            swap(node_to_idx[i], node_to_idx[node_to_idx[i].second]);
        }
        else
            i++;
    }
    return ans;
}
