Node* segregate(Node *head) {
    if(!head)
        return head;
    int ones = 0, twos = 0, zeros = 0;

    auto node = head;
    while(node){
        if(node->data == 0)
            ++zeros;
        if(node->data == 1)
            ++ones;
        else
            ++twos;
        node = node->next;
    }
    node = head;
    while(node){
        if(zeros){
            node->data = 0;
            --zeros;
        }
        else if(ones){
            node->data = 1;
            --ones;
        }
        else if(twos){
            node->data = 2;
            --twos;
        }
        else break;
        node = node->next;
    }
}
