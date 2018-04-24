// https://www.hackerrank.com/challenges/self-balancing-tree/problem
// Jordan Tonni

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int getHeight(node* root)
{
    if(!root)
        return -1;
    
    return root->ht;
}

int getBalanceFactor(node* root)
{
    return getHeight(root->left) - getHeight(root->right);
}

node* rightRotate(node* root)
{
    node* left = root->left;
    node* leftRight = left->right;
    
    left->right = root;
    root->left = leftRight;
    
    root = left;
    
    root->right->ht = max(getHeight(root->right->left), getHeight(root->right->right)) + 1;
    root->ht = max(getHeight(root->left), getHeight(root->right)) + 1;
    
    return root;
}


node* leftRotate(node* root)
{
    node* right = root->right;
    node* rightLeft = right->left;
    
    right->left = root;
    root->right = rightLeft;
    
    root = right;
    
    root->left->ht = max(getHeight(root->left->left), getHeight(root->left->right)) + 1;
    root->ht = max(getHeight(root->left), getHeight(root->right)) + 1;
    
    return root;
}


node * insert(node * root,int val)
{
    if(!root){
        root = new node();
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        root->ht = 0;
        
        return root;
    }
    
    if(val < root->val)
        root->left = insert(root->left, val);
    else if(val > root->val)
        root->right = insert(root->right, val);
    else
        return root;
    
    root->ht = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balanceFactor = getBalanceFactor(root);
    

    
    // Left heavy
    if(balanceFactor > 1){
        // Left subtree is right heavy
        if(getBalanceFactor(root->left) < 0 )
            root->left = leftRotate(root->left);
        
        return rightRotate(root);
    }
    
    // Right heavy
    if(balanceFactor < -1){
        // Right subtree is left heavy
        if(getBalanceFactor(root->right) > 0)
            root->right = rightRotate(root->right);
        
        return leftRotate(root);
    }
    
    return root;
  
}

