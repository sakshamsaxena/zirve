/*
	Problem :Given two arrays of equal length, the task is to find if given arrays are equal or not.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int a[n], b[n];
		map<int,int> m;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for(int i = 0; i < n; i++) {
			if(m.find(b[i]) != m.end()) {
				m.erase(b[i]);
			}
		}
		if(m.size()) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}
	return 0;
}