/*
	Problem:
	Given an array and an integer k, find the max for each contiguous subarray of size k.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		int K;
		cin >> N >> K;
		int arr[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int max = -1;
		for(int i = 0; i < K; i++) {
			if(max < arr[i]) {
				max = arr[i];
			}
		}
		cout << max << " ";
		for(int i = K; i < N; i++) {
			int newNum = arr[i];
			if(newNum > max) {
				max = newNum;
			} else {
				if(max == arr[i-K]) {
					// It is at the lost index
					max = -1;
					for(int j = i+1-K; j < i+1; j++) {
						if(arr[j] > max) {
							max = arr[j];
						}
					}
				} else {
					// It was somewhere in between only,
					// So it will be unchanged. No computation.
				}
			}
			cout << max << " ";
		}
		cout << endl;
	}
	return 0;
}