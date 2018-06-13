/*
	Problem :Given two unsorted arrays A[] of size n and B[] of size m of distinct elements.
	The task is to find all pairs from both arrays whose sum is equal to x.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n,m,x;
		cin >> n >> m >> x;
		int a[n], b[m];
		map<int, pair<int,int>> u, v;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			u[a[i] - x] = make_pair(i,1);
		}
		for(int i = 0; i < m; i++) {
			cin >> b[i];
			v[b[i]] = make_pair(i,1);;
		}
		map<int, pair<int,int>>::iterator it;
		vector<int> ans;
		for(it = u.begin(); it != u.end(); it++) {
			int num = (it->first);
			num = num - (2*num);
			if(v[num].second) {
				// A suitable pair exists
				// Need to output the actual numbers from indexes
				int ind1 = (it->second).first;
				int ind2 = v[num].first;
				ans.push_back(a[ind1]);
				ans.push_back(b[ind2]);
			}
		}
		if(ans.size()) {
			int i;
			for(i = 0; i < (ans.size() - 2); i+=2) {
				cout << ans[i] << " " << ans[i+1] << ", ";
			}
			cout << ans[i] << " " << ans[i+1];
		} else {
			cout << -1;
		}
		cout << endl;
	}
	return 0;
}