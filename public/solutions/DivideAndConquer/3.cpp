
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The task is to complete merge() which is used
   in below mergeSort() */
/* l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l+(r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
} */
// Merges two subarrays of arr[]. First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int nLeft = m - l + 1;
	int nRight = r - m;
	
	int Left[nLeft];
	int Right[nRight];
	
	// Make "Left" and "Right" from "arr"
	// Note the indices
	for(int i = 0; i < nLeft; i++) {
		Left[i] = arr[l+i];
	}// till arr[l+m-l] or arr[m]
		
	for(int i = 0; i < nRight; i++) {
		Right[i] = arr[m + 1 + i];
	}// till arr[m + 1 + r - m -1] or arr[r]
	
	// Our cursor
	int k = l;
	int i = 0;
	int j = 0;
	// Sort and Rewrite "arr"
	while(i < nLeft && j < nRight) {
		if(Left[i] < Right[j]) {
			arr[k] = Left[i];
			i++;
		} else {
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	
	// Fill in the remaining ones
	while(i < nLeft) {
		arr[k] = Left[i];
		i++;
		k++;
	}
	while(j < nRight) {
		arr[k] = Right[j];
		j++;
		k++;
	}
}