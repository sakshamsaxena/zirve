/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
	Pairwise swap a linked list
	The input list will have at least one element  
	node is defined as 
	struct node
	{
		 int data;
		 struct node *next;
	}
*/
void pairWiseSwap(struct node *head)
{
	node *temp = head;

	while(temp && temp->next) {
		int badal = temp->data;
		temp->data = temp->next->data;
		temp->next->data = badal;
		temp = temp->next->next;
	}
}