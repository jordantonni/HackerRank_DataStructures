// https://www.hackerrank.com/challenges/tree-top-view/problem
// Jordan Tonni

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

#include <stack>
void topView(node * root) {
 
    node* real_root = root;
    stack<int> s;
    
    while(root->left){
        root = root->left;
        s.push(root->data);
    }
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    
    root = real_root;
    cout << root->data << " ";
    
    while(root->right){
        root = root->right;
        cout << root->data << " ";
    }
}

