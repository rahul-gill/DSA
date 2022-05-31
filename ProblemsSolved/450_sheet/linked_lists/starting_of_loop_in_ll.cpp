ListNode* detectCycle(ListNode* head){
    if(!head || !head->next || !head->next->next)
        return NULL;

    ListNode* slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow != fast)
        return NULL;

    fast = head;
    if(slow==fast) while(fast->next != slow)
        fast = fast->next;
    else while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    return fast->next;
}


