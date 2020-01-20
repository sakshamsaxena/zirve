/*
	Problem:
	Given an unsorted array of non-negative integers.
	Find a contiguous sub-array which adds to a given number.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		// Inputs
		int N, S;
		cin >> N >> S;

		// Array
		int arr[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		// Vars
		int currentSum = arr[0];
		int index = 0;
		bool flag = false;
		
		// Main
		for(int i=1;i<=N;i++) {
			// Check first if sum has exceeded
			while(currentSum > S && index < i) {
				currentSum-=arr[index];
				index++;
			}
			// Bingo!
			if(currentSum == S) {
				cout << index+1 << " " << i << endl;
				flag = 1;
				break;
			}
			// Increment currentSum
			if(i<N)
				currentSum += arr[i];
		}

		// Fallthrough
		if(flag == false) {
			cout << -1 << endl;
		}
	}
	return 0;
}