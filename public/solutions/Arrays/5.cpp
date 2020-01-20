/*
	Problem:
	Given an array A your task is to tell at which position the equilibrium first occurs in the array.
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
		int Sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			Sum += arr[i];
		}
		if(N == 1)
			cout << 1 << endl;
		else {
			int lSum = arr[0];
			int flag = 0;
			for(int i = 1; i < N-1; i++) {
			   if((lSum*2) + arr[i] == Sum) {
				   cout << i+1 << endl;
				   flag = 1;
				   break;
			   }
			   lSum += arr[i];
			}
			if(flag == 0) {
				cout << -1 << endl;
			}
		}
	}
	return 0;
}