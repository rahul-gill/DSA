#include<iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data_):data(data_), next(NULL), prev(NULL) {}
    Node():data(T()), next(NULL), prev(NULL)  {}
};

template<typename T>
struct Iterator{
    Node<T>* node;
    Iterator(Node<T>* node_): node(node_) {}
    Iterator& operator++(){
        node = node->next;
        return *this;
    }
    Iterator& operator--(){
        node = node->prev;
        return *this;
    }
    //postix versions: see why prefix ++ is efficient
    Iterator operator++(int){
        Iterator res(*this);
        ++(*this);
        return res;
    }
    Iterator operator--(int){
        Iterator res(*this);
        --(*this);
        return res;
    }


    bool operator==(Iterator b) const { return node == b.node; }
    bool operator!=(Iterator b) const { return node != b.node; }
    T operator*() const {return node->data;}
};



template<typename T>
struct LinkedList{
    Node<T> *head,*tail;
    size_t size_;
    //costructor
    LinkedList(): head(NULL), tail(NULL) {}
    ~LinkedList(){
        while(head != NULL){
            auto nxt = head->next;
            delete head;
            head = nxt;
        }
    }
    LinkedList(const LinkedList<T>& lst): head(NULL), tail(NULL){
        for(auto it=lst.begin(); it != lst.end(); ++it) push_back(*it);
    }
    LinkedList<T>& operator=(const LinkedList<T>& lst) {
        for(auto it=lst.begin(); it != lst.end(); ++it) push_back(*it); 
    }

    //methods
    bool is_empty() const{ return head == NULL; }
    size_t size() const{ return size_;}

    LinkedList<T>& push_front(T data){
        auto new_node = new Node<T>(data);
        new_node->next = head;
        if(head!=NULL) head->prev = new_node;

        head = new_node;
        if(tail == NULL) tail = head;
        size_++;
        return (*this);
    }

    LinkedList<T>& push_back(T data){
        auto new_node = new Node<T>(data);
        new_node->prev = tail;
        if(tail != NULL) tail->next = new_node;
        tail = new_node;
        if(head==NULL) head = tail;
        size_++;
        return (*this);
    }

    Iterator<T> begin() const{ return Iterator<T>(head); }
    Iterator<T> end() const{ return Iterator<T>(tail->next); }

    LinkedList<T>& push_after(Iterator<T> it, T data){
        if(it.node == tail) return push_back(data);
         
        auto it_node = it.node;
        auto new_node = new Node<T>(data);

        new_node->next = (it_node->next);
        (it_node->next)->prev = new_node;
        it_node->next = new_node;
        new_node->prev = it_node;
        size_++;
        return (*this);
    }
    LinkedList<T>& push_before(Iterator<T> it, T data){
        if(it.node == head) return push_front(data); 

        auto it_node = it.node;

        auto new_node = new Node<T>(data);

        new_node->prev = it_node->prev;
        (it_node->prev)->next = new_node;
        it_node->prev = new_node;
        new_node->next = it_node;
        size_++;
        return (*this);
    }
    LinkedList<T>& remove(Iterator<T> it){
        auto prev_node = it.node->prev, next_node = it.node->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        delete it.node;
        return *this;
    }


    void printList(){
        //see you can do this with the iterator class
        for(auto it = begin(); it != end(); it++) cout<<(*it)<<' ';
        cout<<'\n';
    }
};

