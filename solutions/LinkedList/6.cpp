/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
	// Find Loop's slow pointer. Important Observation : 
	// It will be found after X nodes which shall be the length of loop.
	Node *slow = node;
	Node *fast = node;

	while(slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			break;
		}
	}

	// Linear hai list
	if(slow != fast) {
		return;
	}

	// Slow pointer has to go the exact number of steps which would take
	// a new head pointer to reach the beginning of loop.
	// Start with a lead and compare it with the next of slow
	Node *temp = node;
	while(temp->next) {
		if(temp->next == slow->next) {
			slow->next = NULL;
			break;
		}
		temp = temp->next;
		slow = slow->next;
	}
}