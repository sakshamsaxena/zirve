/*
	Problem :
	Given a sorted array of integers, every element appears twice except for one. Find it.
*/
#include <iostream>
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
		for(int i = 0; i < N; i+=2) {
			if(arr[i] != arr[i+1]) {
				cout << arr[i] << endl;
				break;
			}
		}
	}
	return 0;
}