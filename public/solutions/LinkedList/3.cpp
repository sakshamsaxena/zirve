/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Rotate a linked list after node k
  The input list will have at least one element  
  Return pointer to head of rotated linked list 
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/
void rotate(struct node **head_ref, int k)
{
	// Make list circular by changing EOL
	node *current = *head_ref;
	while(current->next){
		current = current->next;
	}
	current->next = *head_ref;
	
	// Iterate again till kth and just set NULL to the next of it
	node *newnode = *head_ref;
	int count = 1;
	while(newnode) {
		if(count == k) {
			*head_ref = newnode->next;
			newnode->next = NULL;
			break;
		} else {
			newnode = newnode->next;
			count++;
		}
	}
}
