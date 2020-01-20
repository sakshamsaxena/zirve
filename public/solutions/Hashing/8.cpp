/*
	Problem :Given a string s, the task is to find the first repeated character in it.
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
		bool flag = false;
		for(int i = 0; i < s.size(); i++) {
			if(!m[s[i]]) {
				m[s[i]]++;
			} else {
				cout << s[i] << endl;
				flag = true;
				break;
			}
		}
		if(!flag) {
			cout << -1 << endl;
		}
	}
	return 0;
}