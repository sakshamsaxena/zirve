/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
	int data;
	Node* next;
}; */
Node *addnode(Node *tempHead, Node *newNode) {
	// concat lists here
	if(tempHead == NULL) {
		tempHead = newNode;
	} else {
		Node *foo = tempHead;
		while(foo->next) {
			foo = foo->next;
		}
		foo->next = newNode;
	}
	return tempHead;
}
//write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second){
	Node* answer = NULL;
	int carry = 0;
	while(first && second) {
		Node* temp = new Node;
		int sum = carry + first->data + second->data;
		int digit = sum%10;
		carry = sum/10;
		// cout << digit << " ";
		temp->data = digit;
		temp->next = NULL;
		answer = addnode(answer, temp);
		first = first->next;
		second = second->next;
	}
	while(first) {
		Node *temp = new Node;
		int sum = first->data + carry;
		temp->data = sum%10;
		temp->next = NULL;
		answer = addnode(answer, temp);
		carry = sum/10;
		first = first->next;
	}
	while(second) {
		Node *temp = new Node;
		int sum = second->data + carry;
		temp->data = sum%10;
		temp->next = NULL;
		answer = addnode(answer, temp);
		carry = sum/10;
		second = second->next;
	}
	if(carry) {
		Node *temp = new Node;
		temp->data = carry;
		temp->next = NULL;
		answer = addnode(answer, temp);
	}
	return answer;
}