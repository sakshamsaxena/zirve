/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
  struct node
  {
	 int data;
	 struct Node *next;
  }
*/
node *addList(node *tempHead, struct node *newNode) {
	// concat lists here
	if(tempHead == NULL) {
		tempHead = newNode;
	} else {
		node *foo = tempHead;
		while(foo->next) {
			foo = foo->next;
		}
		foo->next = newNode;
	}
	return tempHead;
}
struct node *reverse (struct node *head, int k)
{
	// Get length
	int length = 0;
	node *temp = head;
	while(temp) {
		temp = temp->next;
		length++;
	}
	node *finalHead = NULL;
	node *current = head; //1
	int count = 0;
	for(int i = 1; i <= length/k; i++) {
		// Go till we are at K*i
		node *previous = NULL;
		while(count != k*i) {
			// Keep the "next" reference intact
			node* logical_next = current->next;
			// Change the "next" reference of current node to previous node
			current->next = previous;
			// Now setup for next iteration
			// Set the "previous" node to current node
			previous = current;
			// Set the current node to that "next" logical node
			current = logical_next;
			count++;
		}
		finalHead = addList(finalHead, previous);
	}
	count = (length-(length%k)+1);
	node *previous = NULL;
	while(count != length+1) {
		// Keep the "next" reference intact
		node* logical_next = current->next;
		// Change the "next" reference of current node to previous node
		current->next = previous;
		// Now setup for next iteration
		// Set the "previous" node to current node
		previous = current;
		// Set the current node to that "next" logical node
		current = logical_next;
		count++;
	}
	finalHead = addList(finalHead, previous);
	return finalHead;
}