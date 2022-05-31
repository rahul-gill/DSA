ListNode* kth(ListNode* groupStart, int k){
    int num = 1;
    while(groupStart){
        if(num == k)
            return groupStart;
        groupStart = groupStart->next;
        num++;
    }
    return groupStart;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head)
        return head;

    auto dummy = new ListNode(0);    
    dummy->next = head;
    //last of prev group and first of next group
    ListNode* groupPrev = dummy, *groupNext;
    while(1){
        auto kth_node = kth(groupPrev->next, k);
        if(!kth_node)
            break;
        groupNext = kth_node->next;
        debug(groupPrev->val, groupNext->val);
        ListNode* prev = groupNext, *curr = groupPrev->next;
        while(curr != groupNext){
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
    
        auto tmp = groupPrev->next;
        groupPrev->next = kth_node;
        groupPrev = tmp;

    }

    return dummy->next;
}
