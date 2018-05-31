/*
	Problem :
	Given an input stream of N integers
	Insert integers to stream and print the kth largest element in the stream at each insertion.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Kthlargest(priority_queue<int> P,int K){
	// This is a copy so it's okay to pop it out totally!
	for(int i = 0; i < K-1; i++) {
		P.pop();
		if(P.empty()) {
			return -1;
		}
	}
	return P.top();
}

int main() {
	int T;
	cin >> T;
	while(T--){
		int N, K, L;
		cin >> K >> N;
		priority_queue<int> pq;
		for(int i = 0; i < N; i++){
			cin >> L;
			pq.push(L);
			int s = Kthlargest(pq,K);
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}