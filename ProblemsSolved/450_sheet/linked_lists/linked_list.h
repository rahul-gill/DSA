#include<cp_debug.h>

struct Node{
    int data;
    Node* next;
    Node* prev;
    
    Node(int x): data(x) {}
    Node(int x, Node* y): data(x), next(y) {
        y->prev = this;
    }
    Node(std::initializer_list<int> arr){
        data = (arr.size()) ? *(arr.begin()) : 0;

        Node* node = this;
        auto it = arr.begin();
        ++it;
        for (; it != arr.end(); ++it){
            node->next = new Node(*it);
            node = node->next;
        }
    }
};

string to_string(Node* x){
    string s;
    while(x){
        s += to_string(x->data) + " -> ";
        x = x->next;
    }
    s += "n/a";
    return s;
}

Node* arr_to_ll(vector<int> arr){
    if(!arr.size())
        return NULL;
    int i=0;
    auto head = new Node(arr[i++]);
    auto head_ref = head;
    while(i < arr.size()){
        head->next = new Node(arr[i++]);
        head = head->next;
    }
    return head_ref;
}

using ListNode = Node;
