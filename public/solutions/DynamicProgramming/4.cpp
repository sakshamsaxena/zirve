/*
	Problem : Minimum number of jumps
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int jumps[N];
		int min;
		// We're already at last so jumps to reach here is 0.
		jumps[N-1] = 0;
		// So let's start from N-2
		for(int i = N-2; i >= 0; i--) {
			// Handle 0 here itself. Will never reach (infinity)
			if(arr[i] == 0) {
				jumps[i] = INT_MAX;
			} else if(arr[i] >= N-1-i) { // Single direct jump can happen
				jumps[i] = 1;
			} else { // Solve the problem!
				min = INT_MAX;
				// Check all reachable points and take minimum while we
				// keep j less than the possible jumps written at arr[i]
				// so that we can reach there.
				for(int j = i+1; j < N && j <= i+arr[i]; j++) {
					if(min > jumps[j]) {
						min = jumps[j];
					}
				}
				// Update current jumps[i] on the basis of min
				if(min != INT_MAX) {
					// We found a min ahead, and we're able to reach it.
					jumps[i] = min + 1;
				} else {
					// No min found. It's just bad ...
					jumps[i] = min;
				}
			}
		}
		cout << ((jumps[0] == INT_MAX) ? -1 : jumps[0]) << endl;
	}
	return 0;
}