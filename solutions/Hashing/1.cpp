/*
	Problem : Complete the function maxLen which returns the length of maximum subarray with 0 sum.
	Subarray here means a contiguous sequence in the array.
*/
int maxLen(int A[],int n) {
	map <int,int> m;
	int ans = 0;
	int sum = 0;
	// If sum of array is X, then we can find the
	// sub array with sum X through map. If such
	// exists then it means the intermediate sum
	// of the subarray thus traversed is 0.
	for(int i = 0; i < n; i++) {
		sum += A[i];
		
		// Edge case
		if(A[i] == 0 && ans == 0) {
			ans = 1;
		}
		
		// Lucky case
		if(sum == 0) {
			ans = i+1; // Index+1 gives length
		}
		
		// Logic
		if(m.find(sum) != m.end()) {
			// This sum exists at an earlier index
			// Meaning that from that index till
			// current index i, the sum is zero!
			ans = max(ans, i-m[sum]);
		} else {
			m[sum] = i;
		}
	}
	return ans;
}