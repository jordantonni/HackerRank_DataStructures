// https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
// Jordan Tonni


/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#include <map>
multimap<int,int> ma;

void inOrderTrav(node* root, int level)
{
    if(!root)
        return;
    
    inOrderTrav(root->left, level + 1);
    std::pair<int,int> p {level, root->data};
    ma.insert(p);
    inOrderTrav(root->right, level + 1);
}
    

void levelOrder(node * root) 
{
    inOrderTrav(root,0);
    
    for(auto i = ma.begin(); i != ma.end() ; ++i)
        cout << i->second << " ";
    
  
}

