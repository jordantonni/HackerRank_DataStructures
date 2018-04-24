// https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem
// Jordan Tonni

/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value) 
{
    
    node* temp = new node{};
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    
    if(!root){
        root = temp;
        return root;
    }
    
    node* ret = root;
    
    while(true){
        if(value <= root->data){
            if(root->left){
                root = root->left;
            }else{
                root->left = temp;
                break;
            }
        }else{
            if(root->right){
                root = root->right;
            }else{
                root->right = temp;
                break;
            }
        }
    }
    
    return ret;
}

