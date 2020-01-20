/*
	Problem : Given an array of integers, find the length of the longest sub-sequence such that
	elements in the subsequence are consecutive integers in any order.
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
		map<int,int> m;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			m[arr[i]] = i;
		}
		int count = 1;
		int tempc = 1;
		map<int,int>::iterator it = m.begin();
		int init = it->first;
		it++;
		for(; it!=m.end();it++) {
			int a = it->first;
			if(a == init+1) {
				tempc++;
				if(tempc>count) {
					count = tempc;
				}
			} else {
				tempc = 1;
			}
			init = a;
		}
		cout << count << endl;
	}
	return 0;
}