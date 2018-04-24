// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem
// Jordan Tonni

/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        if(position == 0)
        {
            new_node->next = head;
            head = new_node;
        }
        else
        {
            --position;
            Node* temp = head;
            
            while(position>0)
            {
                --position;
                temp = temp->next;
            }
            
            new_node->next = temp->next;
            temp->next = new_node;
        }
        
    }
    
    return head;
}

