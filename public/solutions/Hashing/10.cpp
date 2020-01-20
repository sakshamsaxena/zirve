/*
	Problem :Given a string str and another string patt.
	Find the character in patt that is present at the minimum index in str.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s, patt;
		cin >> s >> patt;
		map<char,int> m;
		for(int i = 0; i < patt.size(); i++) {
			m[patt[i]]++;
		}
		bool printed = false;
		for(int i = 0; i < s.size(); i++) {
			char c = s[i];
			if(m[c]>=1) {
				cout << c << endl;
				printed = true;
				break;
			}
		}
		if(printed == false) {
			cout << "No character present" << endl;
		}
	}
	return 0;
}