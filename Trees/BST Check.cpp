// https://www.hackerrank.com/challenges/is-binary-search-tree/problem
// Jordan Tonni

#include <iostream>
vector<int> v;

void bfs(Node* root)
{
    if(root == NULL)
        return;
    
    bfs(root->left);
    v.push_back(root->data);
    bfs(root->right);
}

bool checkBST(Node* root) 
{
    bfs(root);
    
    for(int i=0; i < v.size()-1; ++i){
        if(v[i+1] == v[i] || v[i+1] < v[i])
            return false;
    }
    
    return true;
      
}

