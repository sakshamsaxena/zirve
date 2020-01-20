/*
	Problem :
	Given an array of integers and a number k,
	write a function that returns true if given array can be divided into pairs
	such that sum of every pair is divisible by k.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		int sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			sum+= arr[i];
		}
		int K;
		cin >> K;
		map<int,int> m;
		for(int i = 0; i < N; i++) {
			m[arr[i] % K] += 1; // Map of remainders only
		}
		// Logic
		if(sum%K || N%2) {
			// Total sum itself isn't divisble
			cout << "False" << endl;
		} else {
			if(K == 1 || m.size() == 1) { // Divisor is 1, or all are divisible
				cout << "True" << endl;
			} else {
				// Total sum is divisible, checking for pairs
				map<int,int>::iterator it = m.begin();
				for(it = m.begin(); it!=m.end(); it++) {
					int a = it->first;
					int b = K-a;
					map<int,int>::iterator tempIt;
					tempIt = m.find(b);
					if(tempIt == m.end()) {
						// Not found
						cout << "False" << endl;
						break;
					} else {
						// clear that entry
						if(m[b] > 1 && m[a] != m[b]) {
							m[b]--;
						} else if(m[b] > 1 && m[a] == m[b]) {
							m[a] -= 2;
						}
					}
				}
				if(it==m.end()) {
					cout << "True" << endl;
				}
			}
		}
	}
	return 0;
}