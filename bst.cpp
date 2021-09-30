#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    Node *left;
    T data;
    Node *right;
    Node *parent;
    Node():left(NULL), right(NULL), parent(NULL), data(T()) {}
    Node(T data_): left(NULL), right(NULL), parent(NULL), data(data_) {}
};



template<typename T>
struct BinarySearchTree{
    Node<T>* tree;
    size_t size_;


    struct Iterator{
        Node<T>* node;
        Iterator(Node<T>* node_): node(node_) {}//not explicit
        Iterator& operator++(){
            //successor
            auto right_node =  node->right;
            if(right_node != NULL){
                while(right_node->left != NULL) right_node = right_node->left; 
                node = right_node;
            }else{
                T main_node_data = node->data;
                if(node->parent == NULL) return *this;
                while(node->parent != NULL && (node->parent)->data < main_node_data) node = node->parent;
                node = node->parent;
            }
            return *this;
        }
        Iterator& operator--(){
            //predecessor
            auto left_node = node->left;
            if(left_node != NULL){
                while(left_node->right != NULL) left_node = left_node->right;
                node = left_node;
            }else{
                T main_node_data = node->data; 
                if(node->parent == NULL) return *this;
                while(node->parent != NULL && (node->parent)->data > main_node_data) node = node->parent;
                node = node->parent;
            }
            return *this;
        }
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




    BinarySearchTree(): tree(NULL) {}
    ~BinarySearchTree(){ deleteSubTree(NULL,1);}
    void deleteSubTree(Iterator it,bool full_do = 1) {
        auto node = (full_do)?tree : it.node;
        if(node != NULL) {
            deleteSubTree(Iterator(node->left),0);
            deleteSubTree(Iterator(node->right),0);
            delete node;
        }
    }



    BinarySearchTree<T>& insert(T data){
        Node<T> *new_node = new Node<T>(data);

        if(tree == NULL) tree = new_node;
        else {
            Node<T> *parentNode = NULL;
            Node<T> *currentNode = tree;
            while(currentNode != NULL) {
                parentNode = currentNode;
                if(data < currentNode->data) currentNode = currentNode->left;
                else currentNode = currentNode->right;
            }

            if(data < parentNode->data) parentNode->left = new_node;
            else parentNode->right = new_node;
            new_node->parent = parentNode;
        }
        ++size_;
        return *this;
    }
    BinarySearchTree<T>& remove(Iterator it){
        auto node = it.node;
        if(node == NULL) return *this;
        auto node_parent = node->parent;

        if(node->left == NULL){
            if(node_parent->left == node) node_parent->left = node->right;
            else node_parent->right = node->right;
            if(node->right != NULL) (node->right)->parent = node_parent;
            delete node;
        }else if(node->right == NULL){
            if(node_parent->left == node) node_parent->left = node->left;
            else node_parent->right = node->left;
            if(node->left != NULL) (node->left)->parent = node_parent;
            delete node;

        }else{
            auto successor = ++it;
            if(node_parent->left == node) node_parent->left = successor.node;
            else node_parent->right = successor.node;
            successor.node->left = node->left;
            if(successor.node != node->right) successor.node->right = node->right;
            delete node;
        }
        --size_;
        return *this;
    }
    BinarySearchTree<T>& remove(T value){
        auto value_it = search(value);
        if(value_it.node == NULL) return *this;
        else return remove(value_it);
    }

    Iterator search(T data) const{
        auto node = tree;
        while(node != NULL){
            if(node->data > data) node = node->left;
            else if(node->data < data) node = node->right;
            else if(node->data == data) return Iterator(node);
        }
        return Iterator(NULL);
    }


    void preOrderTraversal(const function<void(T)>& func,Iterator it = NULL,bool full_do=1) const{
        auto t_node = (full_do)? tree : it.node;
        if(t_node != NULL){
            func(t_node->data);
            preOrderTraversal(func,t_node->left,0);
            preOrderTraversal(func,t_node->right,0);
        }
    }
    void postOrderTraversal(const function<void(T)>& func,Iterator it = NULL,bool full_do=1) const{
        auto t_node = (full_do)?tree : it.node;
        if(t_node != NULL){
            postOrderTraversal(func,t_node->left,0);
            postOrderTraversal(func,t_node->right,0);
            func(t_node->data);
        }
    }
    void inOrderTraversal(const function<void(T)>& func,Iterator it = NULL,bool full_do=1) const{
        auto t_node = (full_do)?tree : it.node;
        if(t_node != NULL){
            inOrderTraversal(func,t_node->left,0);
            func(t_node->data);
            inOrderTraversal(func,t_node->right,0);
        }
    }

    size_t treeHeight(Iterator it = NULL,bool full_do=1) const{
        auto t_node = (full_do)?tree : it.node;
        if(t_node == NULL) return 0;
        size_t left_height = treeHeight(t_node->left,0);
        size_t right_height = treeHeight(t_node->right,0);

        if(left_height > right_height) return left_height + 1;
        else return right_height + 1;
    }
    size_t size() const{ return size_; }
    Iterator begin() const{ 
        //return iterator to smallest element
        auto node = tree;
        if(node == NULL) return NULL;
        while(node->left != NULL) node = node->left;
        return Iterator(node);
    }
    Iterator end() const{ 
        //return iterator to largest element
        auto node = tree;
        if(node == NULL) return NULL;
        while(node->right != NULL) node = node->right;
        return Iterator(node);
    }


};


int main(){

   
    //this will exclude the last element
    BinarySearchTree<int> bst;
    auto i = bst.begin();
    for(; i != bst.end(); i++) cout<<(*i)<<' ';
    cout<<'\n';
    //this can be done instead
    bst.inOrderTraversal(
        [](int val){ cout<<val<<' '; }
    );
    cout<<'\n';




    multiset<int> std_bst;

	for(int test = 1; test <= 30; test++){
		for(int i=0; i<1000; i++){
            int a_number = rand();
            bool insert_or_delete = rand() % 100;
            if(insert_or_delete > 20){ 
                std_bst.insert(a_number);
                bst.insert(a_number);
            }else{
                std_bst.erase(a_number);
                bst.remove(a_number);
            }
            
        }
		vector<int> res1, res2;
        for(auto i=std_bst.begin(); i != std_bst.end(); i++) res1.push_back(*i);
        bst.inOrderTraversal(
            [&](int val){ res2.push_back(val); }
        );
		if(res1 != res2){
			cout<<"failure on test: "<<test<<'\n';
			exit(1);
		}else{
			cout<<"success on test: "<<test<<'\n';
		}
	}
  
   
}