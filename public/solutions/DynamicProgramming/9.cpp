/*
	Problem : Cut Segments.
	Similar to LIS/subset sum in concept.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int X,Y,Z;
		cin >> X >> Y >> Z;
		int dp[N+1];
		dp[0] = 0; // For 0 length, solution is 0.
		for(int i = 1; i <= N; i++) {
			dp[i] = 0; // Initialise as we go.
			// Check for all three at same time or in different loops.
			if(i>=X && (dp[i-X]>0 || i==X)) {// We're at x or more
				if(dp[i] < dp[i-X] + 1) {//+1 as we're only counting.
					dp[i] = dp[i-X] + 1;// Incrementing count of segments.
				}
			}
			if(i>=Y && (dp[i-Y]>0 || i==Y)) {
				if(dp[i] < dp[i-Y] + 1) {
					dp[i] = dp[i-Y] + 1;// Update only if we've better coming.
				}
			}
			if(i>=Z && (dp[i-Z]>0 || i==Z)) {
				if(dp[i] < dp[i-Z] + 1) {
					dp[i] = dp[i-Z] + 1;// Update only if we've better coming.
				}
			}
		}
		cout << dp[N] << endl;
	}
	return 0;
}