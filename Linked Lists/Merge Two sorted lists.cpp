// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem
// Jordan Tonni

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    
    if(headA == NULL)
        return headB;
    if(headB == NULL)
        return headA;
    
    // Get new head at smallest first element
    Node* head = NULL;
    if(headA->data < headB->data){
        head = headA;
        headA = headA->next;
    }
    else{
        head = headB;
        headB = headB->next;
    }
    
    // Keep adding next smallest node and increment head of list you took it from
    Node* current = head;
    while(headA != NULL && headB != NULL){  // O(N)
        if(headA->data < headB->data){
            current->next = headA;
            headA = headA->next;
        }
        else if(headB->data < headA->data){
            current->next = headB;
            headB = headB->next;
        }
        
        current = current->next;
    }
    
    
    // Add remaining of list when one of them is empty
    if(headA == NULL)
        current->next = headB;
    else
        current->next = headA;
    
    return head;
    
}

