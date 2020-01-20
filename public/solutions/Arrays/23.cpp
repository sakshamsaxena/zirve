/*
	Problem :
	Given a list of non negative integers
	Arrange them in such a manner that they form the largest number possible.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool func(string i, string j) {
	return i+j > j+i;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		string arr[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr+N, func);
		for(int i = 0; i < N; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}