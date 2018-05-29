/*
	Problem : Heap Sort
*/

/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n) {
	buildHeap(arr, n);
	// SWAP AND HEAPIFY FIRST INDEX WITH ITH (IT STARTS FROM END)
	// BECAUSE EACH HEAPIFY ENSURES AT LEAST THAT
	// THE FIRST INDEX HAS THE MAX VALUE IN 0-ITH SUB ARRAY. 
	// THIS IS HOW YOU SORT BRUH.
	for (int i=n-1; i>=0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
} */
// To heapify a SUBTREE rooted with node i which is an index in arr[].
void heapify(int arr[], int n, int i) {
	int max = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if(l < n && arr[l] > arr[max]) {
		max = l;
	}
	if(r < n && arr[r] > arr[max]) {
		max = r;
	}
	
	if(max != i) {
		swap(arr[i], arr[max]); // make the subtree a max heap
		heapify(arr,n,max); // Heapify trees under this subtree, thus
	}
}
// It's important to build a heap at least once as the first step
// To ensure at least the first index has the overall max value.
void buildHeap(int arr[], int n) {
	int ind = n/2 - 1; // so that r is at the edge
	// Right half will always have only leaves
	for( ; ind >= 0; ind--) {
		heapify(arr, n, ind);
	}
}
