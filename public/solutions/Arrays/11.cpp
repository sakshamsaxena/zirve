/*
	Problem :
	Given an array and a number k where k is smaller than size of array.
	Find the K'th smallest element in the given array
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
	//code
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
		// At K'th position, the local maximum would be present
		// which is the overall K'th smallest
		priority_queue<int> pq;
		for(int i = 0; i < K; i++) {
			pq.push(arr[i]);
		}
		for(int i = K; i < N; i++) {
			// Check the rest of the array
			if( pq.top() > arr[i] )	{
				pq.pop();
				pq.push(arr[i]);
			}
		}
		cout << pq.top() << endl;
	}
	return 0;
}