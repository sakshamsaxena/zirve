/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node
struct Node {
	int data;
	struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
	// Find total length
	int l1 = 0;
	Node* t1 = head1;
	while(t1) {
		t1 = t1->next;
		l1++;
	}
	int l2 = 0;
	Node* t2 = head2;
	while(t2) {
		t2 = t2->next;
		l2++;
	}
	Node* longer;
	Node* shorter;
	int diff;
	if(l1 > l2) {
		longer = head1;
		shorter = head2;
		diff = l1-l2;
	} else {
		longer = head2;
		shorter = head1;
		diff = l2-l1;
	}
	while(diff--) {
		longer = longer->next;
	}
	
	while(longer->next) {
		longer = longer->next;
		shorter = shorter->next;
		if(longer == shorter) {
			return longer->data;
		}
	}
	return -1;
}