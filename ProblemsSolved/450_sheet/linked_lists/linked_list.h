#include<cp_debug.h>

struct Node{
    int data;
    Node* next;
    
    Node(int x): data(x) {}
    Node(int x, Node* y): data(x), next(y) {}
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

Node* fromArr(vector<int> arr){
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
