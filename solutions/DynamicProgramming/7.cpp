/*
	Problem : Subset Sum Problem
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int S[N];
		int Sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> S[i];
			Sum+=S[i];
		}
		if(Sum % 2) {
			cout << "NO" << endl;
		} else {
			// Find if a subset exists with the sum or not
			Sum = Sum / 2;
			// Matrix is made up of 0 to Sum and N array values
			bool matrix[N+1][Sum+1];
			// With an empty array, we can't sum up to anything.
			// Setting all corresponding cases as false.
			for(int i = 1; i <= Sum; i++) {
				matrix[0][i] = false;
			}
			// With a total sum as 0, we can have empty subsets.
			// Setting all corresponding cases as true.
			for(int i = 0; i <= N; i++) {
				matrix[i][0] = true;
			}
			// If the current sum value we're seeing is less than the
			// current array value we're seeing, then obviously we can't
			// proceed and set solution as was for previous value.
			// If it is greater or equal to the array value, then
			// for the given sum, we see that if either the 
			// previous array value is true or if current value's worth's
			// 'step' behind that is true. It'll affirm that a subset
			// with these values (and values similarly calculated before)
			// we can have that sum. 
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= Sum; j++) {
					if(j < S[i-1]) {
						matrix[i][j] = matrix[i-1][j];
					} else {
						matrix[i][j] = matrix[i-1][j] || matrix[i-1][j-S[i-1]];
					}
				}
			}
			cout << ((matrix[N][Sum] == 1) ? "YES" : "NO") << endl;
		}
	}
	return 0;
}