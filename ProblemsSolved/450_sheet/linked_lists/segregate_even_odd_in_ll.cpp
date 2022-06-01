Node* divide(int N, Node *head){
    if(!head || !head->next)
        return head;

    Node *even_head = 0, *odd_head =0, *even_end=0, *odd_end=0, *prev=0;

    while(head){
        if(head->data & 1){
            if(!odd_head)
                odd_head = odd_end = head;
            else{
                odd_end->next = head;
                odd_end = head;
            }
        }
        else{
            if(!even_head)
                even_head = even_end = head;
            else{
                even_end->next = head;
                even_end = head;
            }

        }
        head = head->next;
    }
    if(!even_head)
        return odd_head;
    if(!odd_head)
        return even_head;

    odd_end->next = NULL;
    even_end->next = odd_head;
    return even_head;
}
