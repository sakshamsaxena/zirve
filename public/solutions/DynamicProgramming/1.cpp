/*
	Problem : Longest Increasing Subsequence (LIS)
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
		int lis[N];
		int max = 0;
		for(int i = 0; i < N; i++) {
			lis[i] = 1; // Initialise LIS Array
			cin >> arr[i];
		}
		for(int i = 1; i < N; i++) { // Bottom-up Approach
			for(int j = 0; j < i; j++) { // Check if we've any better LIS
				if(arr[i] > arr[j]) { // As it is increasing subsequence
					if(lis[i] < lis[j] + 1) { // If we need to update it
						lis[i] = lis[j] + 1;
					}
				}
			}
		}
		for(int i = 0; i < N; i++) {
			if(max < lis[i]) {
				max = lis[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}