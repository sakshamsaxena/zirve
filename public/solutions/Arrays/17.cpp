/*
	Problem :
	Given an array of distinct elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f.
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
		bool flag = true; // "<"
		for(int i = 0; i < N-1; i++) {
			if(flag) {
				if(arr[i] > arr[i+1]) {
					int t = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = t;
				}
			} else {
				if(arr[i] < arr[i+1]) {
					int t = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = t;
				}
			}
			flag = !flag;
		}
		for(int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}