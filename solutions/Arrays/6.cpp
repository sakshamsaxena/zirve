/*
	Problem:
	Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers in the subsequence are sorted in increasing order.
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
		// In a non negative array, max sum will be in longest
		// subsequence, and that is what we have to find.
		int iSum[N];
		for(int i = 0; i < N; i++) {
			iSum[i] = arr[i];
		}
		for(int i = 1; i < N; i++) {
			// Get a subseuqence here to analyse with others.
			for(int j = 0; j < i; j++) {
				// Check for overall increasing order.
				if(arr[j] < arr[i]) {
					// If any intermediate sum is greater than the 
					// updated corner sum, then update the corner
					// sum (which is the sum of ith subsequence).
					if(iSum[i] < iSum[j] + arr[i]) {
						iSum[i] = iSum[j]+arr[i];
					}
				}
			}
		}
		int max = -1;
		// Find the max from all the subsequences.
		for(int i = 0; i < N; i++) {
			if(max < iSum[i]) {
				max = iSum[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}