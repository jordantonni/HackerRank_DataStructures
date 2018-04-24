// https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
// Jordan Tonni

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    string output{};
    node* temp = root;
    
    for(int i = 0; i<s.length(); ++i){
        char c = s[i];
        
        if(c == '0')
            temp = temp->left;
        else
            temp = temp->right;
        
        if(temp->data != '\0'){
            output += temp->data;
            temp = root;
        }
    }
    
    cout << output << "\n";
}

