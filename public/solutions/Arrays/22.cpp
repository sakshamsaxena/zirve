/*
	Problem :
	Given an array of integers, sort the array according to frequency of elements.
	If frequencies of two elements are same, print them in increasing order.
*/
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2) {
	if(p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		map<int,int> M;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			M[arr[i]]++;
		}
		int l = M.size();
		pair<int,int> P[l];
		map<int,int>::iterator it;
		int i = 0;
		for(it = M.begin(); it != M.end(); i++, it++) {
			P[i] = make_pair(it->second, it->first);
		}
		sort(P, P+l, comp);
		for(int j = 0; j < l; j++) {
			int f = P[j].first;
			while(f--) {
				cout << P[j].second << " ";
			}
		}
		cout << endl;
	}
	return 0;
}