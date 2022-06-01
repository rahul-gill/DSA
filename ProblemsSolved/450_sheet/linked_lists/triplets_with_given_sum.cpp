int countTriplets(DLLNode* head, int x){
    if(!head || !head->next || !head->next->next)
        return 0;
    int cnt = 0;
    auto last_st = head;
    while(last_st->next)
        last_st = last_st->next;

    auto node = head;
    while(node && node->next){
        auto fst = node->next, last = last_st;
        
        while(fst != last && last->next != fst){
            if(fst->data + last->data + node->data == x){
                ++cnt;
                fst = fst->next;
                last = last->prev;
            }
            else if(fst->data + last->data + node->data < x)
                fst = fst->next;
            else
                last = last->prev;
        }
        node = node->next;
    }
    return cnt;
}

