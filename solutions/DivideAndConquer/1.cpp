/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You need to complete this function */
int bin_search(int A[], int left, int right, int k)
{
	if(right >= left) {
		int midIndex = (left + right)/2;
		int midVal = A[midIndex];
		if(k == midVal) {
			return midIndex;
		}
		if(k > midVal) {
			return bin_search(A, midIndex+1, right, k);
		}
		return bin_search(A, left, midIndex-1, k);
	}
	return -1;
}