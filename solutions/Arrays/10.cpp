/*
	Problem :
	Given an array, reverse every consecutive sub-array formed by consecutive k elements.
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
		int K;
		cin >> K;
		for(int i = 0; i < N/K; i++) {
			for(int j = (K-1)+(K*i), p=0; p<K && j<N; j--,p++) {
			   cout << arr[j] << " ";
			}
		}
		for(int i = N-1; i >= N-(N%K); i--) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}