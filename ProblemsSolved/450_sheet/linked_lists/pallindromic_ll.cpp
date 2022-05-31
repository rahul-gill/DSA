bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
        return 1;
    if(!head->next->next)
        return head->val == head->next->val;

    //find middle
    auto fast = head, slow = head;
    while(fast && fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    //reverse second half of list
    ListNode *prev = NULL, *curr = slow->next;
        
    while(curr){
        auto tmp =  curr->next;
        curr -> next = prev;
        prev = curr;
        curr = tmp;
    }
    //check for equality of first half and reversed second half
    slow->next = prev;
    
    fast = head, slow = slow->next;
    while(slow){
        if(fast->val != slow->val)
            return 0;
        slow = slow->next;
        fast = fast->next;
    }
    return 1;
}


