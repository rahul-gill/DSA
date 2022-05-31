Node* findIntersection(Node* head1, Node* head2){
    if(!head1 && !head2)
        return NULL;
    
    auto head = new Node(0);
    auto node = head;
    while(head1 && head2){
        if(head1->data < head2->data)
            head1 = head1->next;
        else if(head2->data < head1->data)
            head2 = head2->next;
        else{
            node->next = new Node(head1->data);
            head1 = head1->next;
            head2 = head2->next;
            node = node->next;
        }
    }
    return head->next;
}
