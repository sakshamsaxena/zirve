
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//function Template for C++
/* Linked List Node structure
   struct Node  {
	 int data;
	 Node *next;
  }
*/
// Should reverse list and return new head.
Node* reverse(Node *head)
{
	Node* current = head;
	Node* previous = NULL;
	if(current == NULL) {
		return current;
	}
	while(current) {
		// Keep the "next" reference intact
		Node* logical_next = current->next;
		// Change the "next" reference of current node to previous node
		current->next = previous;
		// Now setup for next iteration
		// Set the "previous" node to current node
		previous = current;
		// Set the current node to that "next" logical node
		current = logical_next;
	}
	// The new head
	return previous;
}