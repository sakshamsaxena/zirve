/*
	Problem :
	Given an array of integers (both -ve and +ve), find the contiguous sub-array with maximum sum.
	This is the Kadane's Algorithm
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
		int currentMax = 0;
		int globalMax = 0;
		for(int i=0;i<N;i++) {
			cin >> arr[i];
			if(i==0) {
				currentMax = arr[i];
				globalMax = arr[i];
			} else {
				currentMax = max(arr[i], arr[i] + currentMax);
				globalMax = max(globalMax, currentMax);
			}
		}
		cout << globalMax << endl;
	}
	return 0;
}
