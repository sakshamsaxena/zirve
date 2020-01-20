/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list node 
struct Node
{
	int data;
	Node* next;
}*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{
	// Your code here
	Node *nex = node->next;
	node->data = nex->data;
	node->next = nex->next;
}