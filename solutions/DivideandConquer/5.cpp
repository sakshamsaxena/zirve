/*
	Problem:
	Given two sorted arrays of size m and n respectively.
	Find the element that would be at the k’th position of the final sorted array.
*/

#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, M, K;
		cin >> N >> M >> K;
		int L[N];
		int R[M];
		for(int i = 0; i < N; i++) {
			cin >> L[i];
		}
		for(int i = 0; i < M; i++) {
			cin >> R[i];
		}
		int p = 0;
		int i = 0;
		int j = 0;
		int arr[K];
		while(p < K && i < N && j < M) {
			if(L[i] < R[j]) {
				arr[p] = L[i];
				i++;
			} else if(L[i] > R[j]) {
				arr[p] = R[j];
				j++;
			} else {
				arr[p] = L[i];
				arr[p+1] = R[j];
				p++;
				i++;
				j++;
			}
			p++;
		}
		// Fall through
		if(p < K) {
			// Fast Forward till we're at K
			if(i < N) {// M array got exhausted
				int index = K-M-1;
				cout << L[index] << endl;
			}
			if(j < M) {
				int index = K-N-1;
				cout << R[index] << endl;
			} 
		} else {
			cout << arr[K-1] << endl;
		}
	}
	return 0;
}