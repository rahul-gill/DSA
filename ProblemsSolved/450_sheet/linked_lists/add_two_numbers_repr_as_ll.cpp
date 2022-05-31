ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    ListNode* res = new ListNode(0);
    auto ret = res;
    int carry = 0;
    while(l1 || l2){
        int sum = carry;
        sum += (l1) ? l1->val: 0;        
        sum += (l2) ? l2->val: 0;        

        carry = sum / 10;
        int digit  = sum % 10;
        res->next = new ListNode(digit);
        res = res->next;
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }
    if(carry){
        res->next = new ListNode(carry);
    }
    return ret->next;
}
