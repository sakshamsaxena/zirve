/*
	Problem : Longest Common Subsequence
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int A, B;
		cin >> A >> B;
		string S_A, S_B;
		cin >> S_A >> S_B;
		int LCS[A+1][B+1];
		for(int i = 0; i <=A; i++) {
			for(int j = 0; j <=B; j++) {
				if(i == 0 || j == 0) { // First row, First Column
					LCS[i][j] = 0;
				} else if(S_A[i-1] == S_B[j-1]) { // Letters match!
					LCS[i][j] = LCS[i-1][j-1] + 1;
				} else { // Keep the max of current matching letter or previous matching letter.
					LCS[i][j] = max(LCS[i][j-1], LCS[i-1][j]);
				}
			}
		}
		cout << LCS[A][B] << endl;
	}
	return 0;
}