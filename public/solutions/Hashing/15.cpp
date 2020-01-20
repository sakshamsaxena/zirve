/*
	Problem : Task is to check if its possible to remove at most one character from a string
	in such a way that frequency of each distinct character becomes same in the string.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		map<char,int> m;
		map<int,int> f;
		// Populate Map
		for(int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		// Create a map of frequencies' frequency
		map<char,int>::iterator itm;
		for(itm = m.begin(); itm != m.end(); itm++) {
			f[itm->second]++;
		}
		if(f.size() == 1) {
			// Case when all are good so nothing to remove
			cout << 1 << endl;
		} else if(f.size() == 2) {
			// Case when there are 2 frequencies
			// Now need to check if at least one of it is 1
			int firstF = (f.begin())->second;
			int secondF = (++f.begin())->second;
			if(firstF == 1 || secondF == 1) {
				// At least one frequency was unqiue
				int a = (f.begin())->first;
				int b = (++f.begin())->first;
				if(abs(a-b) == 1) {
					// There can be exactly one removal
					cout << 1 << endl;
				} else {
					cout << 0 << endl;
				}
			} else {
				cout << 0 << endl;
			}
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}