Node* merge(Node* list1, Node* list2) {
    if(!list1)
        return list2;
    if(!list2)
        return list1;

    Node* node = new Node(0);    
    auto h = node;
    while(list1 && list2){
        if(list1->data > list2->data){
            node->next = list2;
            list2 = list2->next;
        }
        else{
            node->next = list1;
            list1 = list1->next;
        }
        node = node->next;
    }
    while(list1){
        node->next = list1;
        list1 = list1->next;
        node = node->next;
    }
    while(list2){
        node->next = list2;
        node = node->next;
        list2 = list2->next;
    }
    return h->next;
}

Node* middle(Node* head) {

    auto fast = head->next, slow = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* mergeSort(Node* head) {
    if(!head || !head->next)
        return head;
    
    auto x = middle(head);
    auto right_s = x->next;
    x->next = NULL;
    auto l = mergeSort(head);
    auto r = mergeSort(right_s);

    return merge(l,r);
}

int main(){
    auto x = new Node(3, new Node(2, new Node(5)));
    mergeSort(x);
    while(x)
        cout<<x->data<<' ', x = x->next;
}
