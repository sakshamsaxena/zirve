/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
	int data;
	struct Node* next;
};*/
// Should reverse list and return new head.
Node* reverse(Node *head)
{
	Node* current = head;
	Node* previous = NULL;
	if(current == NULL) {
		return current;
	}
	while(current) {
		Node* logical_next = current->next;
		current->next = previous;
		previous = current;
		current = logical_next;
	}
	return previous;
}
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
	Node *current = head;
	Node *middle = NULL;
	Node *fast = head;
	int len = 0;
	while(current) {
		current = current->next;
		len++;
	}
	current = head;
	while(current && fast && fast->next) {
		current = current->next;
		fast = fast->next->next;
	}
	// For ODD, current will be exactly middle
	// For EVEN, current will be second middle
	if(len%2) {
		middle = current->next;
	} else {
		middle = current;
	}
	// Reverse post middle
	Node *newhead = reverse(middle);
	// check now
	current = head;
	while(current&&newhead) {
		if(current->data != newhead->data) {
			return false;
		}
		current = current->next;
		newhead = newhead->next;
	}
	// fallthrough
	return true;
}