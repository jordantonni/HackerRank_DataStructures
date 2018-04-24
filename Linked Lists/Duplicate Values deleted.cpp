// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem
// Jordan Tonni

/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    
    Node* ret = head;
    Node* temp = NULL;
    
   while(head != NULL){
       temp = head->next;
       
       while(temp != NULL && temp->data == head->data){
           Node* t = temp;
           temp = temp->next;
           delete(t);
           
       }
       
       head->next = temp;
       head = head->next;
   } 
    
    
    return ret;
}

