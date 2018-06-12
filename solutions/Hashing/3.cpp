/*
	Problem :
	Given an array A[] of size n and an integer k,
	your task is to complete the function countDistinct which
	prints the count of distinct numbers in all windows of size k in the array A[]
*/
void countDistinct(int A[], int k, int n)
{
	map<int,int> m;
	for(int j = 0; j < k; j++) {
		m[A[j]]++;
	}
	int c = m.size();
	cout << c << " ";

	for(int i = 1; i < n-k+1; i++) {
		if(!m[A[i+k-1]]) {
			// Newly added number in window does not exist, so inc size
			c++;
			m[A[i+k-1]]++;
		} else {
			m[A[i+k-1]]++;
		}
		if(m[A[i-1]] == 1) {
			// It was distince but we lost it so dec size
			c--;
			m[A[i-1]]--;
		} else {
			m[A[i-1]]--;
		}
		cout << c << " ";
	}
}