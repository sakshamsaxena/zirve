/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node
struct Node {
	int data;
	Node* next;
}; */
Node* SortedMerge(Node *headA, Node* headB)
{

	if(headA == NULL && headB == NULL) {
		return NULL;
	} else if(headA == NULL){
		return headB;
	} else if(headB == NULL){
		return headA;
	} else if(headA->data < headB->data) {
		headA->next = SortedMerge(headA->next, headB);
		return headA;
	} else {
		headB->next = SortedMerge(headA, headB->next);
		return headB;
	}
}