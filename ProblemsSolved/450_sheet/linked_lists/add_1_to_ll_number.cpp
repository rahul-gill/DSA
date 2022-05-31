Node* addOne(Node *head) {
    if(!head)
        return new Node(1);

    Node * dummy = new Node(0);
    dummy->next = head;

    Node *node = head, *prev = dummy, *before_nine = NULL, *last;

    while(node){
        if(node->data == 9 && !before_nine)
            before_nine = prev;
        else if(node->data != 9)
            before_nine = NULL;

        prev = node;
        last = node;
        node = node->next;
    }

    //do the addition
    if(before_nine == NULL)
        last->data = last->data + 1;
    else{
        before_nine->data = before_nine->data + 1;
        before_nine = before_nine->next;
        while(before_nine){
            before_nine->data = 0;
            before_nine = before_nine->next;
        }
    }
    if(dummy->data)
        return dummy;
    return head;
}
