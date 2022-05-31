bool hasCycle(ListNode *head) {
    if(!head || !head->next)
        return 0;

    auto fast = head, slow = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}
