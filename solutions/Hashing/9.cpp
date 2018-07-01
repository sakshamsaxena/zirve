/*
	Problem : Print the total count of sub-arrays having their sum equal to 0.
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
		int sum = 0;
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			sum+=arr[i];
			m[sum]++;
		}
		//Logic
		map<int,int>::iterator it = m.begin();
		int count = 0;
		while(it!=m.end()) {
			if(it->second > 1) {
				// This is when an intermediate sum went to 0
				// Or arrived at another intermediate sum, meaning
				// that in between some numbers summed to the 0.
				int f = it->second;
				// N such occurances means C(N,2) ways to make such subarrays.
				count += ((f)*(f-1)) / 2;
			}
			it++;
		}
		if(m.find(0) != m.end()) {
			// Don't forget to add as is 0s found in the way!
			count += m[0];
		}
		cout << count << endl;
	}
	return 0;
}