/*	This function takes last element as pivot, places the pivot element
	at its correct position in sorted array, and places all smaller (smaller
	than pivot) to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int low, int high)
{
	// As given
	int pivot = arr[high];
	
	// Initialize index of smaller element
	int i = low-1;
	
	// Elements smaller than pivot are 
	for(int j = low; j < high; j++) {
		if(arr[j] < pivot) {
			i++; // Increments only to point at small elements
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		} // For higher elements, j is incremented
	}
	int temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
	return i+1;
}