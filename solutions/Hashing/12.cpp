/*
	Problem :Find and print the uncommon characters of the two given strings.
	Here uncommon character means that either the character is present in one string
	or it is present in other string but not in both.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string a,b;
		cin >> a >> b;
		map<char,int> ma, mb;
		for(int i = 0; i < a.size(); i++) {
			char c = a[i];
			ma[c] = 1;
		}
		for(int i = 0; i < b.size(); i++) {
			char c = b[i];
			mb[c] = 1;
		}
		// Iterate over larger map
		map<char,int>::iterator it;
		if(ma.size() > mb.size()) {
			for(it = ma.begin(); it!=ma.end(); it++) {
				char c = it->first;
				if(mb.find(c) != mb.end()) {
					mb.erase(c);
				} else {
					mb[c] = 1;
				}
			}
			// Output
			for(it = mb.begin(); it!=mb.end(); it++) {
				char c = it->first;
				cout << c;
			}
		} else {
			for(it = mb.begin(); it!=mb.end(); it++) {
				char c = it->first;
				if(ma.find(c) != ma.end()) {
					ma.erase(c);
				} else {
					ma[c] = 1;
				}
			}
			for(it = ma.begin(); it!=ma.end(); it++) {
				char c = it->first;
				cout << c;
			}
		}
		cout << endl;
	}
	return 0;
}