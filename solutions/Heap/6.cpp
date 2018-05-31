/*
	Problem : Given K sorted linked list your task is to merge them.
*/
Node* SortedMerge(Node* headA, Node* headB)
{
	if (headA == NULL && headB == NULL) {
		return NULL;
	} else if (headA == NULL) {
		return headB;
	} else if (headB == NULL) {
		return headA;
	} else if (headA->data < headB->data) {
		headA->next = SortedMerge(headA->next, headB);
		return headA;
	} else {
		headB->next = SortedMerge(headA, headB->next);
		return headB;
	}
}
// arr is array of LL
// last is length of arr
Node * mergeKList(Node *arr[], int N)
{
	// repeat until only one list is left
	int last = N - 1;
	while (last != 0)
	{
		int i = 0, j = last;
		// (i, j) forms a pair
		while (i < j)
		{
			// merge List i with List j and store
			// merged list in List i
			arr[i] = SortedMerge(arr[i], arr[j]);
			// consider next pair
			i++, j--;
			// If all pairs are merged, update last
			if (i >= j)
				last = j;
		}
	}
	return arr[0];
}