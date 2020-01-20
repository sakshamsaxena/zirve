/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct node
{
int data;
Node* next;
};*/
int detectloop(Node *list)
{
	Node *normal = list;
	Node *fast = list;
	
	while(normal && fast && fast->next) {
		normal = normal->next;
		fast = fast->next->next;
		if(normal == fast) {
			return 1;
		}
	}
	return 0;
}