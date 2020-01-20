/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node
  {
	int data;
	Node *next;
  }
*/
void sortList(Node *head)
{
	int zeros = 0;
	int ones = 0;
	int twos = 0;
	Node *current = head;
	while(current) {
		int data = current->data;
		if(data == 0) {
			zeros++;
		}
		if(data == 1) {
			ones++;
		}
		if(data == 2) {
			twos++;
		}
		current = current->next;
	}
	current = head;
	while(zeros--) {
		current->data = 0;
		current = current->next;
	}
	while(ones--) {
		current->data = 1;
		current = current->next;
	}
	while(twos--) {
		current->data = 2;
		current = current->next;
	}
}