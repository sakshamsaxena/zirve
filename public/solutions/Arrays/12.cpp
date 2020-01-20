/*
	Problem :
	Given n non-negative integers in array representing an elevation map.
	Compute how much water it is able to trap after raining.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		// Left and Right arrays to hold max values
		int L[N];
		int R[N];
		
		// Fill Left Array
		L[0] = arr[0];
		for(int i = 1; i < N; i++) {
			L[i] = max(L[i-1], arr[i]);
		}
		// Fill Right Array
		R[N-1] = arr[N-1];
		for(int i = N-2; i >= 0; i--) {
			R[i] = max(R[i+1], arr[i]);
		}
		
		// Water at any point in array will be min of L/R value minus the current value
		int result = 0;
		for(int i = 0; i < N; i++) {
			result += min(L[i], R[i]) - arr[i];
		}
		cout << result << endl;
	}
	return 0;
}