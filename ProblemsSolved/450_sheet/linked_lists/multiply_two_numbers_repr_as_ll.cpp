const long long mod = 1e9+7;
long long  multiplyTwoLists (Node* l1, Node* l2){
    long long n1=0,n2=0;
    while(l1){
        n1 = (10 * n1 + l1->data) % mod;
        l1 = l1->next;
    }
    while(l2){
        n2 = (10 * n2 + l2->data) % mod;
        l2 = l2->next;
    }
    return (n1*n2) % mod;
}

