int idx = 0;
node_t* construct_h(string &str){
    node_t* root = NULL;
    if(idx >= str.size())
        return root;

    if(str[idx] != '(' && str[idx] != ')'){
        root = new node_t(str[idx] - '0');
        idx++;
    }
    if(str[idx] == '('){
        idx++;
        root->left = doit(str);
    }
    if(str[idx] == ')'){
        idx++;
        return root;
    }
    if(str[idx] == '('){
        idx++;
        root->right = doit(str);
    }
    if(str[idx] == ')'){
        idx++;
        return root;
    }
    return root;
}

node_t* construct(string &str){
    idx = 0;
    return construct_h(str);
}





















