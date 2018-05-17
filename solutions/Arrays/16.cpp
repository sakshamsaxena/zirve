/*
	Problem :
	Given an unsorted array of size N. 
	Find the first element in array such that all of its left elements are 
	smaller and all right elements to it are greater than it.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N], left[N];
		left[0] = -1;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			if(i>0) {
				left[i] = max(left[i-1], arr[i-1]);
			}
		}
		int rt = 2999999;
		int ind = -1;
		for(int i = N-1; i >= 0; i--) {
			if(left[i] <= arr[i] && rt >= arr[i] && i!=N-1 && i!=0) {
				ind = i;
			}
			rt = min(rt, arr[i]);
		}
		cout << ((ind == -1) ? -1 : arr[ind]) << endl;
	}
	return 0;
}