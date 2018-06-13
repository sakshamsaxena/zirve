/*
	Problem : Find the first element that occurs exactly k number of times.
	If no element occurs k times the print -1
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N,K;
		cin >> N >> K;
		int arr[N];
		int ans = -1;
		int ind = 1000000;
		map<int,pair<int,int>> m;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			if(m[arr[i]].second) {
				int j = m[arr[i]].first;
				int f = m[arr[i]].second;
				m[arr[i]] = make_pair(j,++f);
			} else {
				m[arr[i]] = make_pair(i,1);
			}
		}
		map<int,pair<int,int>>::iterator it;
		for(it = m.begin(); it != m.end(); it++) {
			pair<int,int> val = it->second;
			if(val.second == K) {
				if(ind > val.first) {
					ind = val.first;
					ans = it->first;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}