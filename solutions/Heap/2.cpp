/*
	Problem : Heap Sort
*/

/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n) {
	buildHeap(arr, n);
	// Swap and heapify first index (max value) with ith (starting
	// from end) because each heapify called here does only one
	// traversal down the tree from the root and swaps, thereby
	// not always rechecking "INTERMEDIATE" subtrees after swaps.
	// See the heapify notes below.
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
	
	// Note that the traversal is "vertical" and not all nodes
	// in the same level are picked in a single traversal. 
	// That's exactly why we have used loops above to call for
	// each node.
	if(max != i) {
		swap(arr[i], arr[max]); // make the subtree a max heap
		heapify(arr,n,max); // Heapify trees UNDER this subtree, thus
	}
}
// It's important to build a heap at least once as the first step.
// By traversing the tree BOTTOM UP, it ensures that the max value
// reaches the root node while the tree satisfies the HEAP CONDITION
// which is to have children lesser than parent. Bottom up approach
// ensures this, and thus it is the first step we do in Heap Sort.
void buildHeap(int arr[], int n) {
	int ind = n/2 - 1; // so that r is at the edge
	// Right half will always have only leaves
	for( ; ind >= 0; ind--) {
		heapify(arr, n, ind);
	}
}
