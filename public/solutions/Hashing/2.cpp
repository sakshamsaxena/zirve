/*
	Problem :
	Given two arrays of integers, write a program to check if a pair of values
	(one value from each array) exists such that swapping the elements of the
	pair will make the sum of two arrays equal.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		int L[N], R[M];
		int sL = 0;
		int sR = 0;
		map<int,int> l,r;
		for(int i = 0; i < N; i++) {
			cin >> L[i];
			sL+=L[i];
			l[L[i]]++;
		}
		for(int i = 0; i < M; i++) {
			cin >> R[i];
			sR+=R[i];
			r[R[i]]++;
		}
		int diff;
		bool gotIt = false;
		if(abs(sR-sL) % 2) {
			cout << -1 << endl;
		} else {
			if(sR <= sL) {// L is shorter
				diff = (sL-sR)/2;
				for(int i = 0;i < M;i++) {
					if(l[(R[i]+diff)]) {
						cout << 1 << endl;
						gotIt = true;
						break;
					}
				}
			} else {
				diff = (sR-sL)/2;
				for(int i = 0;i < N;i++) {
					if(l[(L[i]+diff)]) {
						cout << 1 << endl;
						gotIt = true;
						break;
					}
				}
			}
			if(!gotIt) {
				cout << -1 << endl;
			}
		}
	}
	return 0;
}