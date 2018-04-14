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
			// If max was in between window
			if(max != arr[i-K]) {
				if(newNum > max) {
					max = newNum;
				}
			} else {
				if(newNum > max) {
					max = newNum;
				} else {
					max = -1;
					for(int j = i+1-K; j < i+1; j++) {
						if(arr[j] > max) {
							max = arr[j];
						}
					}
				}
			}
			cout << max << " ";
		}
		cout << endl;
	}
	return 0;
}