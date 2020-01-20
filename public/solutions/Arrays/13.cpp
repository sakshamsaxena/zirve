/*
	Problem :
	Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			arr[i] = temp*temp;
		}
		sort(arr,arr+N);
		bool found = false;
		for(int i = N-1; i >= 2; i--) {
			int c = arr[i];
			int l = 0;
			int r = i-1;
			while(l<r) {
				int a = arr[l];
				int b = arr[r];
				if(a+b == c) {
					cout << "Yes" << endl;
					found = true;
					break;
				}
				if(a+b > c) {
					r--;
				}
				if(a+b < c) {
					l++;
				}
			}
			if(found) {
				break;
			}
		}
		if(found == false) {
			cout << "No" << endl;
		}
	}
	return 0;
}