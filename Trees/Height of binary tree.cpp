// https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem
// Jordan Tonni


/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        
        if(!root)
            return -1;
        
        return 1 + std::max(height(root->left), height(root->right));
        
    }
