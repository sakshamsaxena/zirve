/*
	Problem :Given two arrays. Find whether arr2[] is a subset of arr1[] or not. 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int M, N;
		cin >> M >> N;
		int arr1[M], arr2[N];
		map<int,int> n;
		for(int i = 0; i < M; i++) {
			cin >> arr1[i];
		}
		for(int i = 0; i < N; i++) {
			cin >> arr2[i];
			n[arr2[i]]++;
		}
		for(int i = 0; i < M; i++) {
			int val = arr1[i];
			if(n.find(val) != n.end()) {
				n.erase(val);
			}
		}
		if(n.size() == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}