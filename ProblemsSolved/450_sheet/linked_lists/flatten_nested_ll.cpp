Node* merge(Node* list1, Node* list2) {
    auto tmp1 = list1, tmp2 = list2;

    if(!list1)
        return list2;
    if(!list2)
        return list1;

    Node* node = new Node(0);    
    auto h = node;
    while(list1 && list2){
        if(list1->data > list2->data){
            node->bottom = list2;
            list2 = list2->bottom;
        }
        else{
            node->bottom = list1;
            list1 = list1->bottom;
        }
        node = node->bottom;
    }
    while(list1){
        node->bottom = list1;
        list1 = list1->bottom;
        node = node->bottom;
    }
    while(list2){
        node->bottom = list2;
        node = node->bottom;
        list2 = list2->bottom;
    }
    ///
    if(h->bottom == tmp1)
        h->bottom->next = tmp2->next, tmp2->next =  0;
    if(h->bottom == tmp2)
        tmp1->next = 0;
    return h->bottom;
}

Node *flatten(Node *root){
    if(!root || !root->next)
        return root;
    
    while(root->next)
        root = merge(root);
    return root;
}
