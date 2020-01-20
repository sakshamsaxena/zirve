/*
	Problem : Edit Distance
	Similar to LCS
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int P, Q;
		cin >> P >> Q;
		string S,T;
		cin >> S >> T;
		int D[P+1][Q+1];
		for(int i = 0; i <= P; i++) {
			for(int j = 0; j <=Q; j++) {
				if(i == 0) { //Insert all j characters
					D[i][j] = j;
				} else if(j == 0) { // Remove all i characters
					D[i][j] = i;
				} else if(S[i-1] == T[j-1]) { // No change in cost
					D[i][j] = D[i-1][j-1];
				} else { // Take the minimal approach
					D[i][j] = 1 + min(min(D[i-1][j], D[i][j-1]), D[i-1][j-1]);
				}
			}
		}
		cout << D[P][Q] << endl;
	}
	return 0;
}