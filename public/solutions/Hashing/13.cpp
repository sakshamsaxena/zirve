/*
	Problem : Given a string and text output the smallest window in the string which covers
	all the characters present in the text.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string str, patt;
		cin >> str >> patt;
		map<char,int> mS, mP;
		// Basic checks
		if(str.size() < patt.size()) {
			cout << -1 << endl;
		} else {
			// Map the pattern text
			for(int i = 0; i < patt.size(); i++) {
				// Increment, as it may contain same letter multiple times (bitch!)
				mP[patt[i]]++;
			}
			// A variable to check if we've all the occurances
			int count = 0;
			// A custom iterator
			int start = 0;
			// Answer variable
			int ans = 1000000;
			int ind = -1;
			for(int i = 0; i < str.size();i++) {
				char c = str[i];
				// Increment string map to check later that if a new
				// occurance is there to be compared with or not
				mS[c]++;
				// Check if this char is in pattern and that we're yet to reach
				// target number of occurances
				if(mP[c] && mS[c] <= mP[c]) {
					count++;
				}
				// If we have it all
				if(count == patt.size()) {
					// We have a window, Watson
					// End point is current index (i)
					// Start point is to be found out
					// We'll do that by looking at those chars which
					// are not in pattern, or if they are excess than needed
					while(mS[str[start]] > mP[str[start]] || !mP[str[start]]) {
						// As you should be able to see, it'll break at equality
						// We also decrement the excess as it is iterated upon
						// once already now, till we're exactly at the pattern
						// match/count of all others exactly as per pattern.
						if(mS[str[start]] > mP[str[start]]) {
							mS[str[start]]--;
						}
						start++;
					}
					// Length of window is ...
					int len = i - start + 1;
					// Minimize this and update answer index
					if(ans>len) {
						ans = len;
						ind = start;
					}
				}
			}
			if(ind == -1) {
				cout << -1 << endl;
			} else {
				cout << str.substr(ind,ans) << endl;
			}
		}
	}
	return 0;
}