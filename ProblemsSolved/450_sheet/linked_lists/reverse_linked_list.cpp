ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* next = head;
    while(next){
        auto tmp = next->next;
        next->next = prev;
        prev = next;
        next = tmp;
    }
    return prev;
}

ListNode* reverseList(ListNode* head, ListNode* prev = NULL) {
    if(!head)
        return prev;
    auto tmp =  head->next;
    head->next = prev;
    return reverseList(tmp, head);
}
//creating a new list which is reverse of current list
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;

    ListNode* new_l = new ListNode(head->val);

    ListNode* next = head;
    while(head && head->next){
        auto tmp = new ListNode(head->next->val);
        tmp->next = new_l;
        new_l = tmp;
        head = head->next;
    }
    return new_l;
}
