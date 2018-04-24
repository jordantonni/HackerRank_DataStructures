// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
// Jordan Tonni

/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
}node;

*/


node *lca(node *root, int v1,int v2)
{
    while(1){
        if (root->data == v1 || root->data == v2){
            return root;
        } else if (v1 <= root->data && v2 <= root->data){
            root = root->left;
            continue;
        } else if (v1 > root->data && v2 > root->data){
            root = root->right;
            continue;
        }
        return root;
    }
}


