/*
	Problem : Given two strings. Find the length of the smallest string which has
	both strings as its sub-sequences.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string A,B;
		cin >> A >> B;
		int _A = A.size();
		int _B = B.size();
		// Find longest common subsequence length
		int LCS[_A+1][_B+1];
		for(int i = 0; i <=_A; i++) {
			for(int j = 0; j <=_B; j++) {
				if(i == 0 || j == 0) {
					LCS[i][j] = 0;
				} else if(A[i-1] == B[j-1]) {
					LCS[i][j] = LCS[i-1][j-1] + 1;
				} else {
					LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
				}
			}
		}
		// Super sequence will be of this length then
		int ans = _A + _B - LCS[_A][_B];
		cout << ans << endl;
	}
	return 0;
}