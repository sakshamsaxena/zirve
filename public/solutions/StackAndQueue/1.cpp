/*
	Problem :
	Given an array having distinct elements.
	Find the next greater element for each element of array in order of their appearance.
*/
#include <iostream>
using namespace std;
/*
DIDNT USE STACK AS THAT APPROACH IS OVER COMPLICATED
*/
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
		
		// Logic
		for(int i = 1; i < N; i++) {
			if(arr[i-1] < arr[i]) {
				cout << arr[i] << " ";
			} else {
				int j = i;
				while(arr[i-1] > arr[j] && j < N) {
					j++;
				}
				if(j == N) {
					cout << -1 << " ";
				} else {
					cout << arr[j] << " ";
				}
			}
		}
		cout << -1 << endl;
	}
	return 0;
}