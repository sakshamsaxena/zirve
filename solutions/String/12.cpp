/*
	Problem : Print length of smallest substring with maximum number of distinct characters.
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		int N = S.size();
		map<char, int> m;
		m[S[0]] = 1;
		int maxL = 1;
		int curL = 1;
		for(int i = 1; i < N; i++) {
			if(m[S[i]] == 0 || m[S[i]] < i - curL) {
				// New character or,
				// An existing char but not in current substring
				// (it's index is before the start of our substring)
				curL++;
			} else {
				// Repeating character found
				// curL will be reset, so compare with max first
				if(curL > maxL) {
					maxL = curL;
				}
				// Reset curL to the index at which the letter
				// previously occurred plus a place ahead and
				// start our new substring from there. Example :
				// aerewgfd
				curL = i - m[S[i]] + 1;
			}
			m[S[i]] = i+1; // Store the index
		}
		if(curL > maxL) {
			maxL = curL;
		}
		cout << maxL << endl;
	}
	return 0;
}