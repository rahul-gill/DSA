vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<pair<int, int>> ans;
    if(!head || !head->next)
        return ans;

    auto fst = head, last = head;
    while(last->next)
        last = last->next;

    while(fst != last && last->next != fst){
        if(fst->data + last->data == target){
            ans.push_back({fst->data, last->data});
            fst = fst->next;
            last = last->prev;
        }
        else if(fst->data + last->data < target)
            fst = fst->next;
        else
            last = last->prev;
    }
    return ans;
}
