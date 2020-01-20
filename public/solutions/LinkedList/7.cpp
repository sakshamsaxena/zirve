/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* struct Node
 {
   int data;
   Node* next;
 }; */
/* Should return data of n'th node from the end of linked list */
int getNthFromLast(Node *head, int n) {
	Node *current = head;
	Node *ans = head;
	
	int count = 1;
	
	while(current) {
		if(count > n) {
			ans = ans->next;
		}
		current = current->next;
		count++;
	}
	return ans->data;
}