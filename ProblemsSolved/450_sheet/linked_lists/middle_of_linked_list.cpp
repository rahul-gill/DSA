ListNode* middleNode(ListNode* head) {
    auto fast = head, slow = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
