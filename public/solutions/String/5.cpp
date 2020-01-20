/*
	Problem :
	Given a string, recursively remove adjacent duplicate characters from string.
	The output string should not have any adjacent duplicates.
*/
#include <iostream>
using namespace std;

void rmdups(string s) {
	int initind = 0;
	int len = 0;
	bool edited = false;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == s[i+1]) {
			initind = i;
			len = 2;
			int j = i+1;
			while(j < s.size()) {
				if(s[j] == s[j+1]) {
					len++;
					j++;
				} else {
					break;
				}
			}
			s.erase(initind, len);
			edited = true;
		}
	}
	if(edited) {
		return rmdups(s);
	} else {
		cout << s << endl;
		return;
	}
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		rmdups(s);
	}
	return 0;
}