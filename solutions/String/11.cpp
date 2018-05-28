/*
	Problem :
	Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
*/
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		int N = S.size();
		int table[N][N];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				table[i][j] = 0;
			}
		}
		for(int p = 1; p < N; ++p) { // substring length
			for(int l = 0, h = p; h < N; ++l, ++h) {
				if(S[l] == S[h]) {
					table[l][h] = table[l+1][h-1]; // Nothing extra needed
				} else {
					table[l][h] = min(table[l][h-1], table[l+1][h]) + 1; // 1 extra needed
				}
			}
		}
		cout << table[0][N-1] << endl;
	}
	return 0;
}