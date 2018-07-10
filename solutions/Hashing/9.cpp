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
				int f = it->second;
				f = f - 1;
				// This means that f contiguous subarrays with sum 0
				// were found. Number of ways to form subarrays from
				// these f basic subarrays is f(f+1)/2. Here's how :
				// {S1,S2,S3,S4} (4), {S1+S2, S2+S3, S3+S4} (3),
				// {S1+S2+S3, S2+S3+S4} (2), {S1+S2+S3+S4} (1). 
				// That is, 4+3+2+1, which is 4*(4+1)/2 = 10
				count += ((f)*(f+1)) / 2;
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