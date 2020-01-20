/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above

// Link list Node 
struct Node {
	int data;
	Node* next;
}; 

Should return data of middle node. If linked list is empty, then -1
*/
int getMiddle(Node *head)
{
	if(head == NULL) {
		return -1;
	}

	Node* normal = head;
	Node* fast = head;
	// Handles ODD Length cases
	while(fast->next && fast->next->next) {
		normal = normal->next;
		fast = fast->next->next;
	}
	// For even length, there will be a next node but not beyond
	if(fast->next && !fast->next->next) {
		normal = normal->next;
	}
	return normal->data;
}