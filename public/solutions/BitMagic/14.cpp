/*
	Problem :
	Given a set of positive integers.
	Complete the function maxSubarrayXOR to return the maximum XOR subset value in the given set. 
*//*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// Function to return maximum XOR subset in set[]
/*
	Problem :
	Given a set of positive integers.
	Complete the function maxSubarrayXOR to return the maximum XOR subset value in the given set. 
*/
int maxSubarrayXOR(int A[], int n) {
	// Uses Gaussian Elimination
	// Get the max num in array to get max bit length
	int max = 0;
	for(int i = 0; i < n; i++) {
		if(A[i] > max) {
			max = A[i];
		}
	}
	if(n ==1) {
		return A[0];
	}
	int N = log2(max)+1;
	vector<vector<int>> ge(N);
	// Organise each number
	for(int i = 0; i < n; i++) {
		if(A[i]) {
			int k = log2(A[i]);
			(ge[k]).push_back(A[i]);
		}
	}
	
	// Create an empty array which will be our new input
	vector<int> arr;
	
	// Perform GE
	for(int i = N-1; i >= 0; i--) {
		// Only for filled buckets
		if((ge[i]).size()) {
			// Let this bucket be v
			vector<int> v = ge[i];
			// Take the last element and add it to new input list
			int x = v[v.size()-1];
			arr.push_back(x);
			
			// Iterate over remaining numbers to relocate them
			for(int j = 0; j < v.size()-1; j++) {
				int z = v[j] ^ x;
				if(z) {
					int p = log2(z);
					(ge[p]).push_back(z);
				}
			}
		}
	}
	
	// Now we have the new ip
	int m = 0;
	for(int i = 0; i < arr.size(); i++) {
		if( m < (m^arr[i])) {
			m = m ^ arr[i];
		}
	}
	
	return m;
}