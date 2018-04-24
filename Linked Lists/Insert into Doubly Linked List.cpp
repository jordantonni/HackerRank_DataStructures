// https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem
// Jordan Tonni

/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
    // Do not write the main method. 
    
    Node* temp = new Node();
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    
    Node* ret = head;
    
    if(head == NULL){
        head = temp;
        return head;
    }
    
    while(head->next != NULL && (head->data < temp->data)){
        head = head->next;
    }
    
    // New tail node
    if(head->next == NULL && head->data < temp->data){
        head->next = temp;
        temp->prev = head;
        return ret;
    }
    
    //Smaller than head, so add before
    temp->next = head;  
    temp->prev = head->prev;
    head->prev = temp;
    
    if(temp->prev != NULL)
        temp->prev->next = temp;
    
    if(temp->prev == NULL)
        return temp;
    
    return ret;
    
    
}

